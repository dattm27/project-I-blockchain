#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    int n,k, Q;
    int sum[100002];
    cin >> n >> k ;
    sum[0] = 0;
    for(int i = 1; i <= n ; i++){
        int a;
        cin >> a;
        sum[i] = sum[i - 1] + a; // sử dụng mảng cộng dồn để tính tổng các đoạn con
    }
    for(int i = k ; i<= n ; i++){
        if ((sum[i] - sum[i-k])%2==0) {  // kiểm tra tổng đoạn từ ai-k-1 -> ai chẵn hay không 
            Q++;
        }
    }
    cout << Q;
    return 0;
}