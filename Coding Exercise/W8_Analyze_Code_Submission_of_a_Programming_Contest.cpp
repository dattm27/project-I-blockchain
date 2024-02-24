// #include <bits/stdc++.h> 
#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<string>
#include<vector>
using namespace std;
int number_of_error_submission = 0 ;// tổng số bài nộp lỗi
unordered_map<string, int> number_of_error_submission_of ; // số bài nộp lỗi của một user
unordered_map<string, int> total_point_of_user; // tổng điểm của một user
unordered_map<string, unordered_map<string, int> > point_at_problem; // Tạo một unordered_map để lưu điểm của userID tại problemID
vector<int> number_submission_at(24*60*60,0) ; // số bài nộp ở một thời điểm 
int number_of_submission = 0 ; // tổng số submission
int lastest_submission_timepoint = -1; // thời điểm bài nộp muộn nhất
int first_submission_timepoint = 1e9; // thời điểm bài nộp đầu tiên 
struct Submission{
    string userID;
    string problemID;
    string timepoint; //thời gian submit dạng HH:MM:SS
    string status;
    int point; 

    //constructor
      // Default constructor
    Submission() = default;

    // Parameterized constructor
    Submission(const string& user, const string& problem, const string& time, const string& stat,  int pt)
        : userID(user), problemID(problem), timepoint(time), status(stat), point(pt) {
    }
};

static int convertTimeToSeconds(const std::string& time) {
        int hours, minutes, seconds;
        sscanf(time.c_str(), "%d:%d:%d", &hours, &minutes, &seconds);
        return hours * 3600 + minutes * 60 + seconds;
}

void input_data() {
    string s;
    while (true){
        getline(cin, s);
        if (s == "#") break; // kết thúc nhập data nếu gặp #
        string userId = s.substr(0, s.find(" ")); // ID của user
        s.erase(0, userId.length()+1);
        string problemID = s.substr(0,3);
        string timepoint = s.substr(4,8);
        s.erase(0,13);
        string status = s.substr(0, s.find(" "));
        string pointstr = s.substr(status.length()+1);
        int point = stoi(pointstr);

        if (status == "ERR") {
            number_of_error_submission ++ ;
            number_of_error_submission_of[userId] ++;
        }
        else {
            //kiểm tra user từng nộp bài này chưa
            if (point_at_problem[userId][problemID]== 0)
            {
                total_point_of_user[userId] += point;
                point_at_problem[userId][problemID] = point;
            }
            else {
                if (point >point_at_problem[userId][problemID] ){
                    total_point_of_user[userId] = total_point_of_user[userId] - point_at_problem[userId][problemID] + point;
                    point_at_problem[userId][problemID] = point;
                }
           
            }
           
        }
        int time = convertTimeToSeconds(timepoint);
        number_submission_at[time] ++ ;
        number_of_submission ++;
        lastest_submission_timepoint = max (lastest_submission_timepoint, time);
        first_submission_timepoint = min(first_submission_timepoint, time);
    }


    //tính tổng cộng dồn số lượng bài nộp ở một thời điểm
    for (int i = first_submission_timepoint ; i<= lastest_submission_timepoint ; ++i){
        number_submission_at[i] += number_submission_at[i-1];
    } 
}

//xử lý truy vấn 
void input_query(){
    string query;
    while (true){
        getline(cin, query);
        if (query == "#") break;
        else if (query == "?total_number_submissions") cout << number_of_submission<<"\n";
        else if (query == "?number_error_submision") cout << number_of_error_submission <<"\n";
        else if (query.find("?number_error_submision_of_user")< query.length()){
            string userId = query.substr(query.find_first_of(" ")+1);
            userId = userId.substr(0, userId.find(" ")); // bỏ ký tự cách đằng sau
            cout<<number_of_error_submission_of[userId]<<"\n";
        }
        else if (query.find("?total_point_of_user") < query.length()) {
            string userId = query.substr(query.find_first_of(" ")+1);
            userId = userId.substr(0, userId.find(" ")); // bỏ ký tự cách đằng sau
            cout<<total_point_of_user[userId]<<"\n";
        }
        else {
            
            string from_time = query.substr(26, 8);
            string to_time = query.substr(35, 8);
            // đổi các timepoint ra giây
            int from_second = convertTimeToSeconds(from_time);
            int to_second = convertTimeToSeconds(to_time);

            //tính số lượng submission trong khoảng thời gian ấy
            //(to_second <= latest_order) ? (period_revenue[to_second] - period_revenue[from_second - 1]) : period_revenue[latest_order]-period_revenue[from_second-1];
            int period_submission = (to_second <= lastest_submission_timepoint) ? number_submission_at[to_second] - number_submission_at[from_second-1] : number_submission_at[lastest_submission_timepoint] -  number_submission_at[from_second-1] ;
            cout << period_submission <<"\n";
        }
    }
}

int main () {
    freopen("W8_B2.inp", "r",stdin);
    freopen("W8_B2.out", "w",stdout);
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
    input_data();
    input_query();
    return 0;
}