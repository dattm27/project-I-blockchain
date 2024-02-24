#include<stdio.h>
#include<iostream>
using namespace std;
int n; 
int x[1000];
void printSequence () {
    for(int i = 1 ; i<= n ; i++){
       cout<<x[i];
    }
    cout<<"\n";
}

void tr(int k){
    for(int v = 0 ; v <= 1 ; v ++){
        x[k] = v;
        if(k == n) printSequence();
        else tr(k+1);
    }
}
int main () { 
    cin>> n;
    tr(1);
}