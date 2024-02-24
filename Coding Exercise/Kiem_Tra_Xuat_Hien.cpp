#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    
    map<int, int> last_seen; //theo dõi lần xuất hiện gần nhất của mỗi phần tử.

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
         // Kiểm tra xem phần tử đã xuất hiện trước đó
        if (last_seen.count(a[i])) {
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
        }
        // Cập nhật chỉ số xuất hiện cuối cùng của phần tử
        last_seen[a[i]] = i;
    }

    return 0;
}