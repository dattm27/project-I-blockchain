#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// hàm DFS từ đỉnh u
void DFS(vector<vector<int> > & edge , bool * visited, int u){
    visited[u] = true;
    cout<< u<< " ";
    for(int i = 0 ; i < edge[u].size() ; i++){
        int v = edge[u][i];
        if (!visited[v]) DFS(edge, visited, v);
    }
    
}
int main () {
    freopen("List_order_of_nodes_visited_by_a_DFS.inp", "r", stdin);
    int n ; //number of nodes
    int m ; // number of edge
    cin >> n >> m ;

    vector<vector<int> > edge(n+1) ; // danh sách kề 
    bool * visited = new bool[n+1]; // đánh dấu một node đã được duyệt qua
    for (int i = 0 ; i< m ; i++){
        int  u , v;
        cin >> u >> v ;
        // thêm u vào danh sách kề của v và ngược lại
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    // sắp xếp các vector danh sách kề
    for (int i = 1 ; i<= n ;i++){
        sort(edge[i].begin(), edge[i].end());
        visited[i] = false;
    }

    for(int i = 1; i<= n ; i++){
        if( !visited[i]) DFS(edge, visited, i);
    }



    
}