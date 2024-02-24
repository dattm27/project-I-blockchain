#include<stdio.h>
#include<iostream>
#include<algorithm>
#include <vector>

using namespace std;

// cấu trúc 1 edge bao gồm 2 đỉnh u , v và trọng số w
struct Edge {
    int u, v, weight;
};

// so sánh 2 đỉnh theo trọng số
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// find set trả về set chứa phần tử v
int findSet(int v, vector<int>& parent) {
    return (v == parent[v]) ? v : (parent[v] = findSet(parent[v], parent));
}

int main () {
    //input dữ liệu
    int N; //number of nodes
    int M; // number of edges
    cin >> N >> M ;
    
    vector<Edge> edges(M);
    vector<int> parent(N+1);

    //nhập M cạnh kèm trọng số
    for(int i = 0 ; i < M ; i++){
        //nhập các cạnh và trọng số
        cin >> edges[i].u >> edges[i].v >> edges[i].weight; 
    }

    //sắp xếp danh sách cạnh theo trọng số tăng dần
    sort(edges.begin(), edges.end(), compareEdges);

    //gán cha của mỗi đỉnh bằng chính nó
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    int mstWeight = 0; // trọng số cây bao trùm nhỏ nhất -> Kết quả

    /*
    - Chọn 1 cạnh trong số cạnh có trọng số nhỏ nhất
    - Bổ sung các cạnh có trọng số nhỏ nhất sao cho không tạo thành chu trình với những cạnh đã được chọn
    - Dừng sau khi n - 1 cạnh đã được chọn
    */
    
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        int setU = findSet(u, parent);
        int setV = findSet(v, parent);

        if (setU != setV) {
            mstWeight += weight;
            parent[setU] = setV;
        }
    }

    cout<< mstWeight; // in ra kết quả là trọng số của cây bao trùm nhỏ nhất

    return 0;
}