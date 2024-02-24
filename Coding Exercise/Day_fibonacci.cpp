#include<stdio.h>
#include<iostream>
using namespace std;
int n, a[23];
int main (){
    a[0]=0;
    a[1]=1;
    cin>> n ;
    for(int i = 2 ; i<= n-1; i++){
        a[i] = a[i-1] + a[i-2];
    }
    cout << a[n-1];
    return 0;

}