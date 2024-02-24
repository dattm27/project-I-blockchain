#include<stdio.h>
#include<iostream>
using namespace std;
int n,x[22];
void printSequence () {
    for(int i = 1 ; i<= n ; i++){
       cout<<x[i];
    }
    cout<<"\n";
}

void gen(int k){
    for(int i = 0; i<=1; i++){
        if (i== 1 && x[k-1]==1) continue;
        x[k]=i;
        if (k == n) printSequence();
        else gen(k+1);
    }
}
int main (){
    x[0]=2;
    cin>> n;
    gen(1);
    return 0;
}