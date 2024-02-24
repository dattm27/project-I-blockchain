#include<stdio.h>
#include <algorithm>
#include<iostream>
#include<queue>

using namespace std;


void BFS(vector<vector<int> > & edge, bool *visited, int u){
    queue<int> q;
    // đưa phần tử đầu tiên vào hàng đợi và đánh dấu đã visit 
    q.push(u);
    visited[u] = true;
    while (!q.empty()){ // chừng nào hàng đợi khác rỗng
        int u = q.front(); // lấy ra phần tử đầu tiên
        cout<< u <<" ";
        q.pop(); // pop phần tử đầu tiên ra khỏi hàng đợi
        //duyệt danh sách kề của đỉnh u vừa lấy ra
        for(int i = 0 ; i < edge[u].size(); i++){
            int v = edge[u][i];
            //nếu chưa được thăm
            if (!visited[v]){
                visited[v] =true; // đánh dấu đỉnh u đã duyệt qua
                q.push(v); // thêm v vào hàng đợi
               
            }
        }
    }
}

int main () {
    freopen("Sequence_of_nodes_visited_by_BFS.inp", "r", stdin);

    int n; // number of nodes
    int m; // number of edges
    cin >> n >> m;
   vector<vector<int> > edge(n +1); // danh sách kề (n + 1) vì số đỉnh bắt đầu từ 1
   bool * visited = new bool[n+1](); // đánh dấu đỉnh đã được duyệt qua hay chưa
    for(int i = 0 ; i <m ; i++){
        int u , v;
        cin >> u >> v;
        // thêm u là đỉnh kề của v và ngược lại
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    
    for(int i = 1 ; i<= n; i++) {
        sort(edge[i].begin(), edge[i].end()); // sắp xếp lại vector danh sách kề
        visited[i] = false; 
    }
   
    for(int i = 1 ; i<= n; i++){
        if (!visited[i]) BFS(edge, visited, i);
    }

    delete[] visited;
    
    return 0;

}