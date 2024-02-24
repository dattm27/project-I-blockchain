#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;
int main() {
   unordered_set<string> database; // Sử dụng một unordered_set để lưu trữ các khóa

    // Đọc khối đầu tiên chứa các khóa và chèn chúng vào cơ sở dữ liệu
   string key;
    while (true) {
       cin >> key;
       //nếu nhập * thì thoát nhập
        if (key == "*") { 
            break;
        }
        database.insert(key);
    }

    // Xử lý khối thứ hai chứa các hành động
   string cmd, action_key;
    while (true) {
       cin >> cmd;
        if (cmd == "***") {
            break;
        }
       cin >> action_key;
        
        // Kiểm tra xem khóa có tồn tại trong cơ sở dữ liệu không
        if (cmd == "find") {
            if (database.find(action_key) != database.end()) {
               cout << "1\n"; // Khóa tồn tại
            } else {
               cout << "0\n"; // Khóa không tồn tại
            }
        }
        // Chèn khóa vào cơ sở dữ liệu và báo cáo thành công hoặc thất bại
        else if (cmd == "insert") {
            if (database.insert(action_key).second) {
               cout << "1\n"; // Chèn thành công
            } else {
               cout << "0\n"; // Chèn thất bại
            }
        }
    }

    return 0;
}