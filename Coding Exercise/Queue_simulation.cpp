#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;

int main (){
    queue<int> queue;
    string s;
    while(s != "#"){
        getline(cin, s);
        if (s.find("PUSH")==0){  // lệnh PUSH
            queue.push(stoi(s.erase(0, 5)));
        }
        if (s.find("POP") == 0) { // lệnh POP
            if (queue.empty()) cout << "NULL\n";
            else {
                cout << queue.front() <<"\n";
                queue.pop();
            }

        }
    }
    return 0;
}