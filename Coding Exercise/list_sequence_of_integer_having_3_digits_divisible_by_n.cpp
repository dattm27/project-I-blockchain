//CPP 
#include <stdio.h> 
#include<iostream>
using namespace std;
int main() 
{ 
    int n;
    cin>> n ;
    //số đầu tiên có 3 chữ số chia hết cho n;
    int start = (100/n * n) >= 100 ? (100/n * n) : ((100/n +1) * n);
    for (int i =  start; i<= 999 ; i+=n){
        cout << i << " ";
    }
    return 0;
}