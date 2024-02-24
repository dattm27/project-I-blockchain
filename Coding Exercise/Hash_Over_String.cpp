#include <iostream>
#include <string>
using namespace std;
long long base[202]; //base[i] lưu kết quả 256^i
int n, m;
void base_cal(){
    // tính trước base 
    base[0] = 1;
    for(int i = 1 ; i<= 200; i++){
        base[i] = (base[i-1]*256)%m;
    }
}

int main() {
    
    freopen( "Hash_Over_String.inp", "r", stdin);
    freopen( "Hash_Over_String.out", "w", stdin);
    // cải thiện đọc ghi, tránh quá time
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
  
    // Nhập vào số lượng string và m để mod
    cin >> n >> m;

    //Tính base 
    base_cal();

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        long long hash = 0; 
        int k = s.length(); 

        for (int j = 0; j < k; j++) {
            hash = (hash + base[k-j-1] *s[j]) % m;
        }

        cout<< hash<<"\n";
    }

    return 0;
}