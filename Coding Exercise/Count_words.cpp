#include<stdio.h>
#include<iostream>
using namespace std;
int words_count(string s){
    int count = 0;
    bool word = false ;
    int i = 0;
    while (i < s.length()){ // duyệt từng kí tự trong s
        if (s.at(i)!= ' ' && s.at(i)!='\n' ){ //không phải là khoảng trắng hoặc linebreak
            if(!word) { //kiểm tra xem đã là từ mới chưa, nếu chữ -> chuyển thành 1 từ, tăng count
                word = true;
                count ++;
            }
        } else word =false; // khi đã kết thúc từ -> đặt word về false
        i++;
    }
    return count;
}
int main () {
    int count = 0;
    
    //freopen("count_words.inp", "r", stdin);

    // cho nhập số dòng tuỳ ý 
    string s;
    while ( getline(cin, s)){
        count += words_count(s);
    }
    cout<< count;
    return 0;
}