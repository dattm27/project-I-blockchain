#include<stdio.h>
#include<iostream>
#include<stack>
using namespace std ;

int main (){
    stack<int> stack;
    string s;
    do {
        getline(cin,s);
        if(s.find("PUSH") == 0) stack.push(stoi(s.erase(0, 5)));
        if (s.find("POP") == 0) {
            if(!stack.empty()){
                cout<< stack.top() <<"\n";
                stack.pop() ;
            }
            else cout<<"NULL\n";
        } 
    }
    while(s!="#");
    return 0;
}