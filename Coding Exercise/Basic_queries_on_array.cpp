#include<stdio.h>
#include<iostream>
using namespace std;
int n, a[10002];
int Max = -1001, Min = 10001, sum = 0;
int find_max_segment(int start , int end){
    int maxInSegment = -1001;
    for(int i = start; i <= end ; i++){
        if (a[i] > maxInSegment) maxInSegment  = a[i];
    }
    return maxInSegment;
}
void query(string q) {
    if (q== "find-max") cout<< Max;
    else if (q== "find-min") cout<<  Min;
    else if (q=="sum") cout << sum;
    else {
        q.erase(0,17); // bỏ đi phần lệnh
        string i = q.substr(0, q.find(" ")); //lấy ra i là xâu con từ đầu đến trước khoảng trắng đầu tiên
        string j = q.substr(q.find(" ")+1); // lấy ra j là xâu con từ sau khoảng trắng đầu tiên
        cout << find_max_segment(stoi(i), stoi(j));
    }
    cout<< "\n";
}

int main(){
   cin >> n;
    for(int i = 1 ; i<=n ; i++ ){
        cin>>a[i];
        // tìm max
        if (Max < a[i]) Max = a[i];
        if (Min > a[i]) Min = a[i];
        sum+= a[i];
    }  
    //query
    string q="*" ;
    while (getline(cin>>ws, q)){
        if (q== "***") break;
        if (q != "*") query(q);
       
    }
    return 0;
}