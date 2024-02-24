//CPP 
#include <stdio.h> 
#include<iostream>
using namespace std;
int main() 
{ 
    int n, a;
    long long sum = 0;
    cin>> n;
    for(int i = 1; i<= n; i++){
        cin>> a;
        sum += a;
    }
    cout<< sum ;
}