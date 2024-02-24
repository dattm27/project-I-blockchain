#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>
using namespace std;
 
int N ;// số đỉnh
/* Returns true if there is a path from source 's' to sink
  't' in residual graph. Also fills parent[] to store the
  path */
bool bfs(vector<vector<int> >& rGraph, int s, int t, vector<int>& parent)
{
    // Create a visited array and mark all vertices as not
    // visited
    bool visited[N];
    memset(visited, 0, sizeof(visited));
 
    // Create a queue, enqueue source vertex and mark source
    // vertex as visited
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
 
    // Standard BFS Loop
    while (!q.empty()) {
        int u = q.front();
        q.pop();
 
        for (int v = 0; v < N; v++) {
            if (visited[v] == false && rGraph[u][v] > 0) {
                // If we find a connection to the sink node,
                // then there is no point in BFS anymore We
                // just have to set its parent and can return
                // true
                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
 
    // nếu không thể tới được đích thì return fals
    return false;
}
 
// trả về giá trị luồng cực đại từ s tới t 
int fordFulkerson(vector<vector<int> >& graph, int s, int t)
{
    int V = graph.size(); // lấy ra kích thước graph
    vector<vector<int> > rGraph(V, vector<int>(V, 0)); //đồ thị luồng dư được tạo từ đồ thị graph và luồng hiện tại
    //rGraph[i][j] chỉ ra phần capacity còn dư của cạnh i - j 
   
   //ban đầu đặt giá trị luồng dư cho mỗi cạnh bằng capacity của cạnh đó lúc đầu
    for (int u = 0; u < V; u++)
        for (int v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];
 
     vector<int> parent(V); //lưu đỉnh cha của một đỉnh, dùng để truy vết đường đi 
 
    int max_flow = 0; //khởi tạo luồng cực đại bằng 0
 
    
    while (bfs(rGraph, s, t, parent)) {
       // tìm giá trị luồng tối thiểu 
        int path_flow = INT_MAX; 
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
 
        // cập nhật lại capacity còn dư mỗi cạnh
        // bằng truy vết từ đích về nguồn
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
 
        // cộng thêm giá trị path_flow vào giá trị luồng cực đại
        max_flow += path_flow;
    }
 
    // trả về gí trị luồng cực đại
    return max_flow;
}
 

int main()
{   
    
    int M; // số cạnh
    cin >> N >> M ; //nhập số đỉnh và số cạnh
    int source ; //đỉnh bắt nguồn
    int target ; //đỉnh kết thúc
    cin >> source >> target;
    vector<vector<int> > graph(N, vector<int>(N, 0)); //ma trận capacity của các cạnh i - j
    // Let us create a graph shown in the above example
    for(int i = 0; i < M ; i++){
        int u , v , c;
        cin >> u >> v >> c; //nhập cạnh kèm capacity của cạnh đó
        graph[u-1][v-1] = c; //đặt capacity cho cạnh u ,v  (trừ 1 vì số đỉnh lưu từ 0) 
        
    }

 
    cout << fordFulkerson(graph, source, target);
 
    return 0;
}