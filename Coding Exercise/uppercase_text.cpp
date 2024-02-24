#include<stdio.h>
#include<iostream>

using namespace std;
int main () {
    freopen("upercase_text.inp","r",stdin);
    string s;
    while(getline(cin, s)){
        for(int i =  0 ; i < s.length(); i++) { // duyệt từng phần tử của chuỗi
            char& c = s[i];
            if(isalpha(c)) c = toupper(c); // nếu là chữ cái thì chuyển sang chữ hoa
        }
        cout<< s <<"\n";
    }
 
    return 0;
}