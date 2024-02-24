#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF = 1e9;
// định nghĩa cấu trúc đồ thị với các cạnh (u, v) và sức chứa c(u, v)
struct Edge {
    int from;       // đỉnh đầu của cạnh
    int to;         // đỉnh đến của cạnh
    int capacity;   // capacity (max flow) của cạnh
    int flow;       // flow hiện tại của cạnh
};

// Đỉnh nghĩa cấu trúc Graph dùng để lưu trữ danh sách kề và danh sách các cạnh
struct Graph {
    vector<vector<int> > adj; // danh sách cạnh của đồ thị
    vector<Edge> edges;         //lưu trữ thông tin các cạnh 

    // Hàm thêm cạnh vào biểu đồ
    void addEdge(int from, int to, int capacity) {
        Edge e1 = {from, to, capacity, 0}; // Cạnh chạy từ 'from' đến 'to' với sức chứa 'capacity'
        Edge e2 = {to, from, 0, 0};       // Cạnh ngược lại với sức chứa ban đầu là 0

        adj[from].push_back(edges.size()); // Thêm index của cạnh e1 vào danh sách kề của 'from'
        edges.push_back(e1);              // Thêm cạnh e1 vào danh sách cạnh
        adj[to].push_back(edges.size());   // Thêm index của cạnh e2 vào danh sách kề của 'to'
        edges.push_back(e2);              // Thêm cạnh e2 vào danh sách cạnh
    }
};

// sử dụng thuật toán Ford-Fulkerson tìm luồng cực đại
int maxFlow(Graph &graph, int source, int sink) {
    vector<int> parent(graph.adj.size(), -1); // vector lưu cha của mỗi đỉnh trong đường tăng luồng

    int maxFlow = 0; //  luồng cực đại ban đầu = 0 

    // Bắt đầu thuật toán Ford-Fulkerson
    while (true) {
        vector<bool> visited(graph.adj.size(), false); // vector đánh dấu đỉnh đã được duyệt, khởi tạo là false

        queue<int> q; // hàng đợi sử dụng cho tìm đường tăng luồng

        q.push(source); // đưa đỉnh nguồn vào hàng đợi
        visited[source] = true; // đánh dấu đỉnh nguồn đã được thăm

        // BFS tìm đường tăng luồng: khi nào hàng đợi khác rỗng 
        while (!q.empty()) {
            int u = q.front(); //đặt u là phần tử đầu tiên trong hàng đợi
            q.pop();    //đưa phần tử đầu tiên ra khỏi hàng đợi

            for (int i = 0; i < graph.adj[u].size(); i++) { // lần lượt lấy ra các cạnh trong danh sách cạnh
                int edgeIndex = graph.adj[u][i];
                Edge &e = graph.edges[edgeIndex];
                int v = e.to; // v là đỉnh tới của cạnh đó
                
                //kiểm tra nếu v chưa được thăm và capacity của cạnh lớn hơn flow hiện tại 
                if (!visited[v] && e.capacity - e.flow > 0) {
                    q.push(v); //đưa vào hàng đợi
                    visited[v] = true; // đánh dấu là đỉnh v đã thăm
                    parent[v] = edgeIndex; // đặt cha của đỉnh v là edgeIndex
                }
            }
        }

        // nếu không tìm thấy đường tăng luồng từ nguồn đến đích, thoát vòng lặp
        if (!visited[sink]) {
            break;
        }
        // nếu tìm thấy các đường đi từ nguồn đến đích
        // tìm giá trị của đường tăng luồng
        int pathFlow = INF;  //giá trị luồng tối thiểu trên đường đi cụ thể từ nguồn tới đích, ban đầu đặt là INT_MAX
        int u = sink; //u là đỉnh tới cống

        //truy ngược từ u về nguồn để tìm giá trị pathFlow tối thiểu
        while (u != source) {
            int edgeIndex = parent[u];
            Edge &e = graph.edges[edgeIndex];
            pathFlow = min(pathFlow, e.capacity - e.flow);
            u = e.from;
        }

        // Cập nhật luồng trên các cạnh trong đường tăng luồng
        u = sink;
        while (u != source) {
            int edgeIndex = parent[u];
            graph.edges[edgeIndex].flow += pathFlow;     //tăng luồng trên một cạnh  
            graph.edges[edgeIndex ^ 1].flow -= pathFlow; // giảm luồng trên cạnh ngược lại
            u = graph.edges[edgeIndex].from;
        }

        // Cộng giá trị luồng mới vào tổng luồng cực đại
        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() {
    int N, M; 
    cin >> N >> M; //nhập vào số đỉnh và số cạnh
    Graph graph;
    graph.adj.resize(N + 1); //cấp phát bộ nhớ cho vector adj

    int source, sink;
    cin >> source >> sink; // nhập vào đỉnh nguồn và đỉnh đích (cống)

    // Đọc thông tin về các cạnh và sức chứa
    for (int i = 0; i < M; i++) {
        int u, v, capacity;
        cin >> u >> v >> capacity;
        graph.addEdge(u, v, capacity);
    }

    // Gọi hàm tìm luồng cực đại
    int result = maxFlow(graph, source, sink);
    
    // in ra  kết quả luồng cực đại
    cout << result << endl;

    return 0;
}
