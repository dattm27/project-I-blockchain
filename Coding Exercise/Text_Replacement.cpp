#include<stdio.h>
#include<iostream>

using namespace std;
int main (){
    string P1; //van ban bi thay the
    string P2; //van ban thay the
    string  T; //text
    
    getline(cin, P1);
    getline(cin, P2);
    getline(cin, T);
    // khi nao con xuat hien P1 trong T
    while(T.find(P1) < T.length()){
        //thay the P1 thanh P2 trong T 
        T = T.substr(0,T.find(P1) ) + P2 + T.substr(T.find(P1) + P1.length());
    }
    cout<< T;
  
    return 0;
}