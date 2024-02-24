#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
const int INF = 1000000000;

int main () {
    int n; // số đỉnh 
    int m; // số cạnh
    cin >> n >> m ; //nhập số đỉnh và số cạnh
    
    //khởi tạo ma trận khoảng cách với giá trị vô cùng
    vector<vector<int> > d(n, vector<int>(n, INF));

    //cập nhật các giá trị trên đường chéo về 0
    for (int i = 0; i < n; i++) {
        d[i][i] = 0;
    }

    for(int i = 0 ; i < m ; i++){
        int u , v , w;
        cin >> u >> v >> w; // nhập cạnh và trọng số
        d[u - 1][v - 1] = w; //đặt trọng số cho cạnh (-1 vì để đỉnh bắt đầu từ 0)
    }

    // sử dụng thuật toán Floyd-Warshall 
    for (int k = 0; k < n; k++) { // chọn đỉnh trung gian
        //chọn 1 cặp đỉnh i - j phân biệt không trùng với đỉnh trung gian
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                //kiểm tra nếu khoảng cách i-k và k-j không phải là vô cùng
                if (d[i][k] < INF && d[k][j] < INF) {
                    // so sánh: đường đi ngắn nhất i-j là giá trị nhỏ nhất 
                    //giữa đường đi ngắn nhất hiện tại giữa i-j, và đường đi ngắn nhất giữa i-k và k-j
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }

    //in ra ma trận đường đi ngắn nhất
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (d[i][j] == INF) {
                cout << -1 << " ";
            } else {
                cout << d[i][j] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}