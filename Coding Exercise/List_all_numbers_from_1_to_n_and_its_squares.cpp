#include<iostream>
#include<stdio.h>
using namespace std;
int main () {
    int n; 
    cin >> n;
    for(int i = 1 ; i<= n ; i++){
        // in ra i va i binh phuong
        cout << i << " "<< i*i << "\n";
    }
    return 0;
}