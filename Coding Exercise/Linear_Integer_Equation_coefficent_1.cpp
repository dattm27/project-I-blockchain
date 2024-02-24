#include<iostream>
#include<stdio.h>
using namespace std;
int n , m;
int x[20];
int sum = 0;
void printSolution (){
    for(int i = 1 ; i<= n ; i++){
        cout << x[i]<<" ";
    }
    cout<<"\n";
}
void gen(int k){
    for(int v = 1 ; v <= m - sum +1 ; v++){
            x[k]=v;     //gan gia tri
            sum += v;   //cộng tổng các phần tử đã được generate
            if( k == n && sum == m)  printSolution();
            else gen(k+1); 
            sum -=v;    //trừ đi phần từ vừa được generate
    }
}
int main (){

    cin >> n >> m;
    gen(1);
    return 0;
}