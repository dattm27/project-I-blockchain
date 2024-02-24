// #include<bits/stdc++.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;
long long total_money_transaction; // tổng số tiền đã chuyển trong các giao dịch
set<string> account; //danh sách các tài khoản (cả gửi & nhận) không trùng lặp
unordered_map<string, int> total_money_from_account; // số tiền mà một tài khoản đã gửi

//cấu trúc giao dịch
struct Transaction {
    string from_account; //tài khoản người gửi
    string to_account;  // tài khoản người nhận 
    int money;          //lượng tiền giao dịch
    string time_point;  //thời điểm giao dịch
    string atm;         //code cây ATM nơi thực hiện giao dịch

    // constructor
    Transaction(const string& from, const string& to, int amount, const string& time, const string& atm_code)
        : from_account(from), to_account(to), money(amount), time_point(time), atm(atm_code) {}

};

vector<Transaction> transactions; // vector lưu lịch sử các giao dịch


//kiểm tra nếu có chu trình giao dịch độ dài k từ tài khoản account
bool dfs(string current_account, string start_account, int k, set<string>& visited, int depth) {
    //cout<< "dfs current_account = " << current_account << "depth = " << depth << " k = " << k <<"\n";
    visited.insert(current_account);

    for (const Transaction& transaction : transactions) {
        if (transaction.from_account == current_account && visited.find(transaction.to_account) == visited.end() ) {
            
            if (dfs(transaction.to_account, start_account, k, visited, depth + 1)) return true;
              
        }
        else  if (transaction.from_account == current_account && transaction.to_account == start_account && depth+1==k) {
          
            return true;
        }
      
    }

    visited.erase(current_account);
    return false;
}

void check_cycle(string account, int k) {
    set<string> visited;
    cout<< dfs(account, account, k, visited, 0)<<"\n" ;
}


// nhập các giao dịch
void input_data () {
    string transaction; 
   
    while (true) {
        getline(cin, transaction);
        if (transaction == "#") {
            break;
            return; // khi gặp # -> kết thúc khối data block
        
        }
       //lấy các thôg tin từ giao dịch
        string depositor = transaction.substr(0, transaction.find(" ")); //lấy ra tài khoản người gưi 
        transaction.erase(0, depositor.length()+1);
        string receiver = transaction.substr(0, transaction.find(" ")); //lấy ra tài khoản người gưi 
        transaction.erase(0, receiver.length()+1);
        string money =  transaction.substr(0, transaction.find(" ")); //lất ra lượng tiền giao dịch
        int amount = stoi(money);
        transaction.erase(0, money.length()+1);
        string time_point  = transaction.substr(0, transaction.find(" ")); //lấy ra thời điểm thực hiện gd 
        transaction.erase(0, time_point.length());
        string atm = transaction; 
        Transaction newTrans(depositor, receiver, amount, time_point, atm); // tạo instance transaction mới 
        transactions.push_back(newTrans); // thêm transaction đó vào lịch sử giao dịch

        
        //cập nhật các thông tin
        total_money_transaction += amount ; //cộng thêm lượng tiền giao dịch vào tổng tiền tất cả các giao dịch
        total_money_from_account[depositor] += amount;
        account.insert(depositor) ;// thêm người gửi vào danh sách tài khoản
        account.insert(receiver);  //thêm người nhận vào danh sách tài khoản

    }
}




void input_query () {
    string query;
    while (true ){
        getline(cin, query);
        if (query == "#") return; // kết thúc truy vấn
        // ?number_transactions
        else if (query == "?number_transactions") cout<<transactions.size()<<"\n";
        //?total_money_transaction
        else if(query == "?total_money_transaction") cout<< total_money_transaction <<"\n";
        //?list_sorted_accounts
        else if (query == "?list_sorted_accounts") {
            for (const std::string& account : account) {
                cout << account << " ";
            }
            cout<<"\n";;
        }
        //?total_money_transaction_from T000010010
       else if (query.find("?total_money_transaction_from") < query.length()) {
            string account = query.substr(query.find(" ")+1); //lấy ra tài khoản được query
            cout<<total_money_from_account[account]<<"\n";
        }
        //?inspect_cycle T000010010 3
        else if (query.find("?inspect_cycle") < query.length()){
            query.erase(0,15);
            string account = query.substr(0, query.find(" ")); //lấy ra tài khoản được query
            query.erase(0, account.length());
            int k = stoi(query); //lấy ra k 
            //cout<< "inspect from "<< account <<"\n";
            check_cycle(account, k);
        }
        //cout<<query.find("number")<<" ";
    }
}


int main () {
    freopen("Bank_Transaction.inp", "r", stdin);
    freopen("Bank_Transaction.out", "w", stdout);
    // cải thiện đọc ghi, tránh quá time
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
    input_data();  
    input_query();
  
    return 0;
}