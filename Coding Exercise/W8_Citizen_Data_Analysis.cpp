// #include <bits/stdc++.h> 
#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<string>
#include<vector>
using namespace std;
int number_of_people = 0; // số lượng người
int max_unrelated_people = 0; //số lượng người không có quan hệ với ai
//định nghĩa cấu trúc dữ liệu dân cư
struct Citizen {
    string code; // code of the person (length = 7)
    string date_of_birth ; // format YYYY-MM-DD (before 3000-12-31)
    string father_code; // father code (length = 7)
    string mother_code; // mother code (length = 7)
    char is_alive; //Y’ means that the person is still alive, and ‘N’ means tat the current person is died.
    string region_code; //code of the region where the person lives
    vector<string> children_codes; // store the children codes of the person

     // default constructor
    Citizen() = default;

    //constructor
    Citizen(const string& c, const string& dob, const string& father, const string& mother, char alive, const string& region)
        : code(c), date_of_birth(dob), father_code(father), mother_code(mother), is_alive(alive), region_code(region) {
    }
}; 
unordered_map<string, Citizen> database; // stores all people by their code
map<int, int> daily_births ; //lưu trữ số lượng người sinh vào mỗi ngày
vector<int> cumulativeBirths; // Mảng cộng dồn
int lastestBirth = 0; 
int ealiestBirth = 1e9;
// Hàm chuyển đổi ngày từ định dạng YYYY-MM-DD thành số ngày kể từ ngày 0000-01-01
int convertDateToDays2(const std::string& date) {
    int year, month, day;
    sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);

    // Tính số ngày kể từ ngày 0000-01-01
    // Note: Chưa xử lý các điều kiện ngoại lệ, giả sử dữ liệu là hợp lệ
    int days = (year - 1) * 365; // Số ngày từ năm 1 đến năm trước năm hiện tại

    // Xử lý năm nhuận
    for (int y = 1; y < year; ++y) {
        if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
            days++;
        }
    }

    // Số ngày từ tháng 1 đến tháng trước tháng hiện tại
    const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int m = 1; m < month; ++m) {
        days += daysInMonth[m];
    }

    // Số ngày trong tháng hiện tại
    days += day;

    return days;
}
// Hàm chuyển đổi ngày từ định dạng YYYY-MM-DD thành số ngày kể từ ngày 0000-01-01
int convertDateToDays(const std::string& date) {
    int year, month, day;
    sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);

    return year*365 + month*30 + day;
}


// Đếm số người không có quan hệ với ai cả 
int countPeopleWithNoRelation() {
    int count = 0;

    for (const auto& entry : database) {
        const Citizen& person = entry.second;

        // Check if father_code and mother_code are "0000000"
        if (person.father_code == "0000000" && person.mother_code == "0000000") {
            // Check if children_codes has size 0
         if (person.children_codes.empty()) {
                count++;
                
            }
        }else if (person.children_codes.empty()) {
            count++;
            
        }
       
    }
    cout<<"\n";
    return count;
}



// DFS để tính số thế hệ
int dfs(const std::string& current_code, int generation) {
    // Kiểm tra một người có trong database không
    if (database.find(current_code) == database.end()) {
        return 0; // người này không có trong database
    }

    const Citizen& current_person = database[current_code];

    // Kiểm tra một người không có bố và mẹ
    if (current_person.father_code == "0000000" && current_person.mother_code == "0000000") {
        return generation;
    }

    // Recursive DFS for father and mother
    int father_generation = 0;
    int mother_generation = 0;

    if (current_person.father_code != "0000000") {
        father_generation = dfs(current_person.father_code, generation + 1);
    }

    if (current_person.mother_code != "0000000") {
        mother_generation = dfs(current_person.mother_code, generation + 1);
    }

    //  Trả về thế hệ lớn nhất giữa bố và mẹ
    return max(father_generation, mother_generation);
}
unordered_map<string, int> max_generation; // Lưu trữ max generation của mỗi người


//Cộng dồn để tính số lượng người sinh trong một khoảng thời gian
void cumulative_births(){
    //cout<< ealiestBirth << " " << lastestBirth<<"\n";
    cumulativeBirths = vector<int>(lastestBirth, 0); // khởi tạo vector cộng dồn
   
    for(int i = ealiestBirth ; i<= lastestBirth ; ++i){
        cumulativeBirths[i] += cumulativeBirths[i-1] + daily_births[i];
    }
}
//test max generation -> tính max unrelative people 
void test() {

   int oddGen = 0;
   int evenGen = 0;
    for (const auto& entry : database){
        max_generation[entry.first] = dfs(entry.first,0) ;
        if (max_generation[entry.first] %2==0) evenGen++;
        else oddGen++;
    }
    max_unrelated_people = (oddGen, evenGen);
   
}
//Nhập truy vấn 
void input_query () {
    string query;
     while (true) {
        getline(cin, query);
        if (query == "***") break;
        else if (query == "NUMBER_PEOPLE"){
            cout<<number_of_people<<"\n";
        }
        else if (query.find("NUMBER_PEOPLE_BORN_AT") < query.length()){
            string date = query.substr(22);
            //cout << date<<" ";
            cout<< daily_births[convertDateToDays(date)]<<"\n";
        }
        else if (query == "MAX_UNRELATED_PEOPLE") {
            cout<<max_unrelated_people<<"\n";
        }
        else if (query.find("MOST_ALIVE_ANCESTOR") < query.length()){
            string code = query.substr(20);
            cout << dfs(code,0) <<"\n";
        }
        else if (query.find("NUMBER_PEOPLE_BORN_BETWEEN") < query.length()){
            string fromDate = query.substr(27,10);
            string toDate = query.substr(38,10);
            //đổi ngày ra số int
            int fromDay = convertDateToDays(fromDate);
            int toDay = convertDateToDays(toDate);
            // cout << fromDate << " " <<toDate<<"\n";
            // cout << fromDay << " " << toDay << "\n";
            //cout << fromDate <<" " << toDate <<": ";
            cout<<(toDay <= lastestBirth? cumulativeBirths[toDay] : cumulativeBirths[lastestBirth]) - (fromDay <= lastestBirth ? cumulativeBirths[fromDay - 1] : cumulativeBirths[lastestBirth])<<"\n";
        }
    }

}

set<string> testDate;
//Nhập dữ liệu dân cư
void input_data() {
    string s ;
    while(true){
        getline(cin, s); // input the information about a person
        if (s == "*") return;
        //lấy các thông tin của người đó 
        string code = s.substr(0,7);
        string date_of_birth = s.substr(8, 10);
        string father_code = s.substr(19,7); 
        string mother_code = s.substr(27,7);
        char is_alive = s.at(34);
        string region_code = s.substr(37);

        //tạo instance citizen mới
        Citizen new_citizen(code, date_of_birth, father_code, mother_code, is_alive, region_code);

        // thêm new_citizen vào database
        database[code] = new_citizen;

        //kiểm tra nếu như father_code , mother_code khác 0 thì thêm vào làm con của father/ mother
          if (father_code != "0000000") {
            database[father_code].children_codes.push_back(code);
        }
        if (mother_code != "0000000") {
            database[mother_code].children_codes.push_back(code);
        }

        // cập nhật dữ liệu
        number_of_people++;
        int day = convertDateToDays(date_of_birth);
        if (day == 704775) testDate.insert(date_of_birth);
    
        daily_births[day]++;
        lastestBirth = max(lastestBirth, day); // tìm ngày sinh muộn nhất (lớn nhất)
        ealiestBirth = min(ealiestBirth, day); // tìm ngày sinh sớm nhất (nhỏ nhất)
    } 
   

}
int main () {
    freopen("Citizen_Data_Analysis.inp", "r", stdin);
    freopen("W8_B1.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input_data ();
    // cout<<convertDateToDays("1930-10-15") <<"\n";
    // for (const auto& element : testDate) {
    //     std::cout << element << std::endl;
    // }
    test();
    cumulative_births();
    input_query();
    return 0 ;
}