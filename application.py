import os
import binascii
import time 
from iroha import IrohaCrypto
from iroha import Iroha, IrohaGrpc
from iroha import primitive_pb2
import create_account

iroha = None  # Initialize iroha variable globally
net = IrohaGrpc('127.0.0.1:50051') #Create Iroha gRPC client
ADMIN_PRIVATE_KEY = os.getenv(
    'ADMIN_PRIVATE_KEY', 'f101537e319568c765b2cc89698325604991dca57b9716b58016b253506cab70')

def init_iroha(account_id):
    return Iroha(account_id)


# Tìm kiếm xem có tồn tại file key của tài khoản mà người dùng vừa nhập hay không
def find_private_key(account_id):
    private_key_file_path = os.path.join('key', f'{account_id}.priv')

    if os.path.exists(private_key_file_path):
        with open(private_key_file_path, 'r') as file:
            stored_private_key = file.read().strip()
            return stored_private_key
    else:
        return None

# Gửi giao dịch và in trạng thái
def send_transaction_and_print_status(transaction):
    hex_hash = binascii.hexlify(IrohaCrypto.hash(transaction))
    print('Transaction hash = {}, creator = {}'.format(
        hex_hash, transaction.payload.reduced_payload.creator_account_id))
     
     # Đo thời gian bắt đầu gửi giao dịch
    start_time = time.time()
    
    net.send_tx(transaction)
    for status in net.tx_status_stream(transaction):
        print(status)
    
    # Đo thời gian kết thúc gửi giao dịch
    end_time = time.time()
    elapsed_time = end_time - start_time
    print('Transaction done in {:.4f} seconds'.format(elapsed_time))

# Chức năng đăng ký tài khoản mới 
def sign_up():
    # Nhập thông tin từ người dùng
    account_name = input("Enter account name: ")
    domain_id = input("Enter domain ID: ")

    # Tạo cặp khóa public và private key
    private_key, public_key = generate_key()

    # Lưu cặp khóa vào file
    store_key(account_name, domain_id, private_key, public_key)

    # Đăng ký tài khoản
    register(account_name, domain_id, public_key)

def register(account, domain, public_key):
    # Tạo transaction đăng ký tài khoản
    iroha = init_iroha("admin@test")
    tx = iroha.transaction([
        iroha.command('CreateAccount', account_name=account, domain_id=domain,
                      public_key=public_key)
    ])

    # Ký transaction bằng private key của admin
    IrohaCrypto.sign_transaction(tx, ADMIN_PRIVATE_KEY)

    # Gửi transaction và in trạng thái
    send_transaction_and_print_status(tx)

    # Thông báo đăng ký thành công
    print("Create an account successfully!")

def generate_key():
    # Tạo khóa ngẫu nhiên
    private_key = IrohaCrypto.private_key()
    public_key = IrohaCrypto.derive_public_key(private_key)
    return private_key, public_key

def store_key(account_name, domain_id, private_key, public_key):
    # Lưu private key vào file
    priv_file = f"key/{account_name}@{domain_id}.priv"
    with open(priv_file, 'w') as file:
        file.write(private_key.decode('utf-8'))

    # Lưu public key vào file
    pub_file = f"key/{account_name}@{domain_id}.pub"
    with open(pub_file, 'w') as file:
        file.write(public_key.decode('utf-8'))



# Chức năng đăng nhập, cho người dùng nhập vào account ID và private key
def login ():
    global iroha, account_id, user_private_key
    while True:
        account_id = input("Account ID: ")
        user_private_key = input("Private key: ")
        iroha = init_iroha(account_id)
        query = iroha.query('GetSignatories', account_id=account_id)
        IrohaCrypto.sign_query(query, user_private_key)
        response = net.send_query(query)
        if response.signatories_response.keys:
            # If there is a public key in the response, assign it
            user_public_key =  response.signatories_response.keys[0]
        else:
            # If there is no public key in the response
            user_public_key = None
        if user_public_key is not None and \
        IrohaCrypto.derive_public_key(user_private_key)==user_public_key.encode('utf-8'):
            print('Login successfully!')
            break
        else: 
            print("Your account ID or private key is incorrect. Please try again!")

# Xem số dư tài khoản
def query_balance():
    query = iroha.query('GetAccountAssets', account_id=account_id)
    IrohaCrypto.sign_query(query, user_private_key)
    response = net.send_query(query)
    print(f"Balance for account {account_id}:")
    for asset in response.account_assets_response.account_assets:
        print(f"{asset.asset_id}: {asset.balance}")

# Chuyển tài sản     
def transfer_asset():
    receiver_account_id = input("Enter receiver's account ID: ")
    asset_id = input("Enter asset ID to transfer: ")
    amount = input("Enter amount to transfer: ")

    tx = iroha.transaction([
        iroha.command('TransferAsset',
                      src_account_id=account_id,
                      dest_account_id=receiver_account_id,
                      asset_id=asset_id,
                      description="Transfer",
                      amount=amount)
    ], creator_account=account_id)
    IrohaCrypto.sign_transaction(tx, user_private_key)
    send_transaction_and_print_status(tx)

# Menu chức năng
def menu():
    while True:
        print("\nMenu:")
        print("1. Query Balance")
        print("2. Transfer Asset")
        print("3. Exit")
        choice = input("Enter your choice (1/2/3): ")

        if choice == '1':
            query_balance()
        elif choice == '2':
            transfer_asset()
        elif choice == '3':
            print("Exiting the program. Goodbye!")
            break
        else:
            print("Invalid choice. Please enter 1, 2, or 3.")

def main():
    print("Please enter your account ID and private key. 2")
    login()
    menu()
    

sign_up()
  
# if __name__ == "__main__":
    
#     main()
