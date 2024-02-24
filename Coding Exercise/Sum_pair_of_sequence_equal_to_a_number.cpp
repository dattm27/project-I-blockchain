#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main() {
    int n, M;
    
    // Đọc số phần tử trong mảng và giá trị M từ đầu vào
    cin >> n >> M;

    // Mảng a chứa các phần tử
    vector<int> a(n);

    // lưu trữ tần số của từng phần tử trong mảng
    unordered_map<int, int> freq;

    // Đọc các phần tử của mảng từ đầu vào và tăng tần số tương ứng trong unordered_map
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        freq[a[i]]++;
    }

    // số cặp được tìm thấy thoả mãn yêu cầu
    long long count = 0;

    
    for (int i = 0; i < n; ++i) {
        // Tính giá trị cần phải có để tạo cặp với a[i]
        int remain = M - a[i];
        
        // Kiểm tra xem giá trị cần đã xuất hiện trong mảng a
        if (remain >= 1 && freq.count(remain)) {
            // Nếu có, tăng số lượng cặp lên bằng số lần giá trị cần xuất hiện trong mảng
            count += freq[remain];
        }

        // Nếu remain * 2 = M, trừ đi một lần để tránh đếm cặp (a[i], a[i])
        if (remain * 2 == M) {
            count--;
        }
    }

    // Số cặp (i, j) bị tính trùng lặp, nên chia 2 để có kết quả đúng
    count /= 2;

    // In ra số lượng cặp tìm thấy
    cout << count << "\n";

    return 0;
}
