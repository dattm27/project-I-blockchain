#include<stdio.h>
#include<iostream>
using namespace std;
int hour , minute, second;
bool formatCheck(string time){ // kiểm tra định dạng
    if(time.length()!=8)  return false; // số kí tự 
    if (time.at(2)!=':'||time.at(5)!=':')  return false; //format hai dấu chấm
    for(int i = 0 ; i< 8; i++){ // còn lại là các chữ số
        if (i == 2 || i == 5 ) continue;
        if (isdigit(time.at(i))==0) return false;
    }
     
    //tách các thành phần giờ, phút, giây trong time
     hour = stoi(time.substr(0, time.find(":")));
    if (hour > 23 || hour < 0) return false; 
    time = time.erase(0,3);
     minute = stoi(time.substr(0, time.find(":")));
    time = time.erase(0,3);
    if (minute > 59 || minute < 0) return false; 
     second= stoi(time.substr(time.find(":")+1));
    if (second > 59 || second < 0) return false; 
    
    return true;
}

int main (){
    string time;
    cin>>time;
    if (formatCheck(time))  cout<< hour*3600+ minute*60 + second;
    else cout<<"INCORRECT";
    return 0;
}