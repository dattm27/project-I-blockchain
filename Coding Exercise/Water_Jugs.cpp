#include<stdio.h>
#include<iostream>
#include<queue>

using namespace std;
int a, b,c;
int visited[10000][10000];
int step[10000][10000]; // số bước để đạt được trạng thái (x, y)
int res =-1; // kết quả bài toán
std::queue<pair<int, int> > Q;

//đánh dấu 1 trạng thái đã được duyệt qua 
void markVisited(pair<int, int> state){
    visited[state.first][state.second] = 1;
}
// kiểm tra trạng thái có phải là trạng thái mục tiêu
bool reachTarget(pair<int, int> state){ 
    // thoả mãn khi một trong hai cốc == c hoặc cộng tổng 2 cốc lại == c 
    return state.first == c || state.second == c || state.first + state.second == c;
}

void stepCal(pair<int, int> state, pair<int, int> newState){
    step[newState.first][newState.second] = step[state.first][state.second] + 1;
}
//1. đổ hết nước từ cốc 1 đi
bool genMove1Out(pair<int, int> state){ 
    if(visited[0][state.second]) return false; // nếu đã thăm rồi thì false luôn
    pair<int, int> newState(0, state.second);
    Q.push(newState); // thêm vào hàng đợi
    markVisited(newState); // đánh dấu đã visit
    stepCal(state, newState); // tính số bước để có thể đạt được trạng thái newState;
    if (reachTarget(newState)){
        res = step[newState.first][newState.second];
        return true;
    }
    return false;
}
//2. đổ hết nước từ cốc 2 đi
bool genMove2Out(pair<int, int> state){ 
    if(visited[state.first][0]) return false; // nếu đã thăm rồi thì false luôn
    pair<int, int> newState(state.first, 0);
    Q.push(newState); // thêm vào hàng đợi
    markVisited(newState); // đánh dấu đã visit
    stepCal(state, newState); // tính số bước để có thể đạt được trạng thái newState;
    if (reachTarget(newState)){
        res = step[newState.first][newState.second];
        return true;
    }
    return false;
}
//3. đổ từ cốc 1 sang đầy cốc 2
bool genMove1Full2(pair<int,int> state){ 

    if (state.first + state.second < b ) return false; // đổ như này chưa đầy cốc 2 thì false
    if (visited[state.first + state.second -b][b]) return false; // nếu đã thăm rồi thì false luôn
    pair<int, int> newState(state.first + state.second -b, b);
    Q.push(newState); // thêm vào hàng đợi
    markVisited(newState); // đánh dấu đã visit
    stepCal(state, newState); // tính số bước để có thể đạt được trạng thái newState;
    if (reachTarget(newState)){
        res = step[newState.first][newState.second];
        return true;
    }
    return false;
}
//4. đổ hết nước từ cốc 1 sang cốc 2
bool genMoveAll12 (pair<int, int> state) { 
    if (state.first + state.second > b ) return false; // đổ tràn cốc 2 -> false
    if (visited[0][state.first + state.second]) return false; // nếu đã thăm rồi thì false luôn
    pair<int, int> newState(0, state.first + state.second);
    Q.push(newState); // thêm vào hàng đợi
    markVisited(newState); // đánh dấu đã visit
    stepCal(state, newState); // tính số bước để có thể đạt được trạng thái newState;
    if (reachTarget(newState)){
        res = step[newState.first][newState.second];
        return true;
    }
    return false;
}
//5. đổ từ cốc 2 sang đầy cốc 1
bool genMove2Full1(pair<int,int> state){ 

    if (state.first + state.second < a ) return false; // đổ như này chưa đầy cốc 1 thì false
    if (visited[a][state.first + state.second -a]) return false; // nếu đã thăm rồi thì false luôn
    pair<int, int> newState(a, state.first + state.second -a);
    Q.push(newState); // thêm vào hàng đợi
    markVisited(newState); // đánh dấu đã visit
    stepCal(state, newState); // tính số bước để có thể đạt được trạng thái newState;
    if (reachTarget(newState)){
        res = step[newState.first][newState.second];
        return true;
    }
    return false;
}
//6. đổ hết nước từ cốc 2 sang cốc 1
bool genMoveAll21 (pair<int, int> state) { 
    if (state.first + state.second > a ) return false; // đổ tràn cốc 1 -> false
    if (visited[state.first + state.second][0]) return false; // nếu đã thăm rồi thì false luôn
    pair<int, int> newState(state.first + state.second, 0);
    Q.push(newState); // thêm vào hàng đợi
    markVisited(newState); // đánh dấu đã visit
    stepCal(state, newState); // tính số bước để có thể đạt được trạng thái newState;
    if (reachTarget(newState)){
        res = step[newState.first][newState.second];
        return true;
    }
    return false;
}

//7. đổ hết nước từ bể vào cốc 1
bool genFill1(pair<int, int> state){
    if(visited[a][state.second]) return false;// nếu đã thăm rồi thì false luôn
    pair<int, int> newState(a, state.second);
    Q.push(newState); // thêm vào hàng đợi
    markVisited(newState); // đánh dấu đã visit
    stepCal(state, newState); // tính số bước để có thể đạt được trạng thái newState;
    if (reachTarget(newState)){
        res = step[newState.first][newState.second];
        return true;
    }
    return false;
}

//8. đổ hết nước từ bể vào cốc 2
bool genFill2(pair<int, int> state){
    if(visited[state.first][b]) return false;// nếu đã thăm rồi thì false luôn
    pair<int, int> newState(state.first, b);
    Q.push(newState); // thêm vào hàng đợi
    markVisited(newState); // đánh dấu đã visit
    stepCal(state, newState); // tính số bước để có thể đạt được trạng thái newState;
    if (reachTarget(newState)){
        res = step[newState.first][newState.second];
        return true;
    }
    return false;
}


int main (){
   
    pair<int, int> first_state(0,0);
    
    cin >> a >> b >> c ;
    // Khởi tạo trạng thái ban đầu (0,0) và đánh dấu visited
    Q.push(first_state); 
    markVisited(first_state);

    // Lấy lượt lấy các phần tử ra khỏi hàng đợi và thực hiện các hành động, nếu thoả mãn y/c --> break
    while (!Q.empty()){
        pair<int, int> state = Q.front(); // lấy trạng thái ở front của queue
        Q.pop(); // xoá phần tử ở front của queue 
        
        // thực hiện các hành động
        // 1. đổ hết nước từ cốc 1 đi
        if(genMove1Out(state)) break;

        // 2. đổ hết nước từ cốc 2 đi
        if (genMove2Out(state)) break;

        //3. đổ cốc 1 sang đầy cốc 2 
        if (genMove1Full2(state)) break;

        //4. đổ hết cốc 1 sang cốc 2
        if (genMoveAll12(state)) break;

        //5. đổ cốc 2 sang đầy cốc 1 
        if (genMove2Full1(state))  break;

        //6. đổ cốc hết cốc 2 sang cốc 1
        if (genMoveAll21(state)) break;

        //7. đổ đầy từ bể vào cốc 1
        if (genFill1(state)) break;

        //8. đổ đầy từ bể vào cốc 2
        if (genFill2(state)) break;

    }
    cout<< res;
    
    return 0;
}