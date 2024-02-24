#include <stdio.h>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define f1(i,n) for (int i=1; i<=n; i++)
typedef pair<int, int> ii;
#define X first //trong so 
#define Y second 
#define N 100005
const int INF = 1e9;
int n, m;
vector<ii> a[N];
int d[N]; //khoảng cách từ start đến điểm i;

bool minimize(int &a, int b){
    if (a>b) a=b;
    else return false;
    return true;
}
 int dijkstra(int Start, int Target){
   
    priority_queue<ii> qu; // sử dụng priority_queue để đưa các cặp <trọng số, đỉnh> theo chiều trọng số được sắp xếp
    
    ///Khoi tao voi dinh start v� duong di ngan nhat den diem start la 0;
    qu.push(ii(0, Start));
    
    /// khoi tao khoang cach tu diem start den cac diem la vo cung;
    f1(i,n) {
        d[i]=INF;
    }
    d[Start]=0;
    
    // trong khi hang doi con khac rong;
    while (qu.size()){
        ///lay ra phan tu dau tien cua hang doi;
        ii top=qu.top(); qu.pop();
        int du=-top.X, u=top.Y;
        //cout<<du<<"\n";
        //if (du!=d[u]) continue;
        if (u==Target) return d[u]; /// da di den dich;
        ///dung dinh u de co dinh cac khoang cach d[v];
        for (int i=0;i < a[u].size(); i++)
        {   
            int v = a[u][i].Y;
            if (minimize(d[v], d[u]+a[u][i].X))
            ///Vi hang doi uu tien phan tu co gia tri lon nhat tren dau vi vay ta can dau nguoc gia tri
            ///bang cach them vao "-";
            qu.push(ii(-d[v], v));
        }

    }
    return -1;
}
int main(){
   // freopen("DIJKSTRA.inp","r",stdin);
   // freopen("DIJKSTRA.out","w",stdout);
    int Start, Target;
    cin >> n >> m; // nhập số đỉnh và số cạnh
    f1(i,n) a[i].clear();
    f1(i,m){
        int p, q, w;
        cin >> p >> q >> w; //nhập cạnh và trọng số 
        ///Danh sach canh, tat ca cac dinh ke voi dinh p co trong so w;
        a[p].push_back(ii(w, q));
       
    }
    f1(i,n) a[i].push_back(ii());
    cin >> Start >> Target;
    cout << dijkstra(Start, Target);

}




