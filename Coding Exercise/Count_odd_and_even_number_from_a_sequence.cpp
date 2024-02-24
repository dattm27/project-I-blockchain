#include<iostream>
#include<stdio.h>
using namespace std;
int main (){
    int n ;
    int  odd = 0, even = 0;
    cin >> n ; 
    for(int i = 1 ; i<= n ; i++){
        // Nhap vao a[i]
        int a;
        cin >> a ; 
        // (a % 2) != 0 -> so le
        if(a % 2) odd++ ;
        else even++ ;
    }
    cout<< odd << " " << even;
    return 0;
}