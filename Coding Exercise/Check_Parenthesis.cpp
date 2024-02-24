#include<stdio.h>
#include<iostream>
#include<stack>
using namespace std;
bool match(char open, char close){
    if (open =='(' && close == ')') return true;
    if (open =='[' && close == ']') return true;
    if (open =='{' && close == '}') return true;
    return false;
}
bool check (string s){
    stack<char> stack;
     for(int i = 0 ; i < s.length() ; i++) { // duyệt qua từng kí tự
        if(s[i] == '(' || s[i] == '[' || s[i] =='{'){
            stack.push(s[i]);
        }
        else {
            if(stack.empty()) return false;
            else {
               
                if (match(stack.top(), s[i])) stack.pop();
                else return false;
            }
        } 
    }

    if(!stack.empty()) return false;
    else return true;
}
int main (){
    
    string s;
    cin >> s;
    
    if(check(s)) cout<< 1;
    else cout<< 0;
   
    return 0;
}