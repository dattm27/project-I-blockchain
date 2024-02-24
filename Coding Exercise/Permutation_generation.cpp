#include<stdio.h>
#include<iostream>
using namespace std;
int n;
int x[100];
int m[100];// mang danh dau da liet ke
void printPermutation (){
    for(int i = 1 ; i<= n ; i++){
        cout << x[i]<<" ";
    }
    cout<<"\n";
}
void gen(int k){
    for(int v = 1 ; v <= n; v++){
        if(m[v]==0){    // neu chua liet ke
            m[v]=1;     //danh dau da liet ke
            x[k]=v;     //gan gia tri
            if( k == n) printPermutation();
            else gen(k+1);
            m[v]=0;     //danh dau lai la chua liet ke
        }
    }
}
int main () {
    cin >> n;
    gen(1);
    return 0;
}