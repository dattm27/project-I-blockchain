#include<stdio.h>
#include<iostream>
#include<string>
#include<regex>
using namespace std;
int year, month, day;
bool formatCheck(string date){ // kiểm tra định dạng
    if(date.length()!=10)  return false; // số kí tự 
    if (date.at(4)!='-'||date.at(7)!='-')  return false; //format hai dấu gạch ngang
    for(int i = 0 ; i< 8; i++){ // còn lại là các chữ số
        if (i == 4 || i == 7 ) continue;
        if (isdigit(date.at(i))==0) return false;
    }
     
    //tách các thành phần ngày, tháng, năm trong date
    year = stoi(date.substr(0, date.find("-")));
    date = date.erase(0,5);
    month = stoi(date.substr(0, date.find("-")));
    if (month > 12 || month < 1) return false; 
    date = date.erase(0,3);
    day = stoi(date.substr(date.find("-")+1));
    if (day > 31 || day < 1) return false; 
    return true;
}

int main () {
    string s;
    cin >> s ;
    //kiểm tra format YYYY-MM-DD
    if (formatCheck(s))  cout<< year << " "<< month << " " << day;
    else cout << "INCORRECT";
    return 0;
}
 
  