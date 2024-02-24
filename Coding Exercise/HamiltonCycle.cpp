#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

// đồ thị hamilton là đồ thị chứa chu trình hamilton 
bool is_hamilton(vector<vector<int> > & graph, vector<int> & path, bool*visited, int n, int v){
    if (path.size() == n+1 ){ // nếu như lượng đỉnh đã đi qua đúng bằng số đỉnh của đồ thị
        // trả lại kết quả so sánh điểm đầu của đường đi có phải v không (điểm bắt đầu của chu trình)
        // để kiểm tra đó đúng là chu trình
        // for(int i= 0; i< path.size() ; i++){
        //     cout << path[i] <<" ";
        // }
        // cout << "\n";
       
        return (path.front()== v); 
    }
    
    for (int i = 0 ; i < graph[v].size(); i++) { //duyệt từng đỉnh trong danh sách kề của v
        int u = graph[v][i];
        if (visited[u] == 0 && u !=v) { // với mỗi u chưa được thăm 
            path.push_back(u); // thêm u vào cuối đường đi 
            visited[u] = true;    // đánh dấu u đã được thăm 

            // kiểm tra nếu đã thoả mãn đồ thị hamilton và trả về kết quả
            if (is_hamilton(graph, path, visited, n, u)) {
                return true;   
            }

            //bỏ đỉnh của của đường đi và đánh dấu lại là chưa thăm để quay lui 
            path.pop_back();
            visited[u] = 0;
        }
    }
    return false;
}
int main () {
    freopen("HamiltonCycle.inp", "r", stdin);

    int T; // number of Graph
    cin >> T; 

    // nhập lần lượt từng đồ thị
    for(int i = 0 ; i< T ; i++){
        int n ; // number of node
        int m ; // number of edges 
        cin >> n >> m ; 
        vector<vector<int> > graph(n+1) ; // danh sách kề
        for(int i = 1 ; i <= m ; i++){
            int u, v;
            cin >> u >> v;
            
            // thêm đỉnh u là một đỉnh kề với v và ngược lại
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // duyệt từ từng đỉnh của đồ thị xem có thoả mãn
        // đồ thị hamilton không
        int res = 0; // kết quả đồ thị đó có phải hamilton hay không
        for (int i = 1 ; i<= n ; i++){
            vector<int> path ; // đường đi
            bool* visited = new bool[n]();  // đánh dấu các cạnh đã thăm 
            
            //với cạnh thứ i, đưa i vào path ()
            path.push_back(i);
            // visited[i] = true;

            //gọi hàm kiểm tra đồ thị hamilton, bắt đầu duyệt từ đỉnh i
            if (is_hamilton(graph, path, visited, n , i)){
                res = 1;
                break;
            }
            delete[] visited; //giải phóng visted
            
        }
        cout << res <<"\n";

    }
    return 0;
}