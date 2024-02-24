#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>
using namespace std;

// Maximum number of vertices in the graph
#define V 100

/* Returns true if there is a path from source 's' to sink
't' in residual graph. Also fills parent[] to store the path. */
bool bfs(int rGraph[V][V], int s, int t, int parent[])
{
    bool visited[V];
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++) {
            if (visited[v] == false && rGraph[u][v] > 0) {
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
    return false;
}

// Returns the maximum flow from s to t in the given graph
int fordFulkerson(int graph[V][V], int s, int t, int N)
{
    int u, v;
    int rGraph[V][V];
    for (u = 0; u < N; u++)
        for (v = 0; v < N; v++)
            rGraph[u][v] = graph[u][v];

    int parent[V];
    int max_flow = 0;

    while (bfs(rGraph, s, t, parent)) {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main()
{
    int N, M;
    
    cin >> N >> M ;

    int graph[V][V] = {0};
    int source;
    
    int target;
    cin >> source >> target;


    for (int i = 0; i < M; i++) {
        int u, v, capacity;
        cin >> u >> v >> capacity;
        graph[u-1][v-1] = capacity;
    }

    cout << "The maximum possible flow is: " << fordFulkerson(graph, source, target, N) << endl;

    return 0;
}
