// #include <bits/stdc++.h> 
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

#include <algorithm>
using namespace std ;
struct Order{
    string customer_ID; // id khach hang
    string product_ID; // ma san pham 
    int price; // gia
    string shop_ID; // id shop
    string time_point ; // thoi gian order viet theo format HH:MM:SS

    // Constructor
    Order(const std::string& customer, const std::string& product, int orderPrice, const std::string& shop, const std::string& time)
        : customer_ID(customer), product_ID(product), price(orderPrice), shop_ID(shop), time_point(time) {
        
      
    }
};
vector<Order> orders ; // vector luu laii cac order
long long total_revenue =0; //tong thu nhap tren tat ca cac order
unordered_map<string, int> revenue_of_shop; // thu nhap tu mot shop
unordered_map<string, long long> total_consume_of_customer_shop; // tong hoa don cua khach doi voi mot cua hang 
vector<long long> period_revenue(24 * 60 * 60, 0);  // period_revenue[i] la tong doanh thu tu 00:00:00 den thoi diem i
 static int convertTimeToSeconds(const std::string& time) {
        int hours, minutes, seconds;
        sscanf(time.c_str(), "%d:%d:%d", &hours, &minutes, &seconds);
        return hours * 3600 + minutes * 60 + seconds;
}
int latest_order = -1; // thoi diem order muon nhat  
void input_data(){
    string order;
    while(true) {
        getline(cin, order);

        // lay cac thong tin tu order 
        if(order == "#") return; // neu gap # thi ket thuc nhap du lieu
        string customer_ID = order.substr(0, order.find(" ")); // lay id khach hang tu order
        order.erase(0, customer_ID.length()+1);
        
        string product_ID = order.substr(0, order.find(" "));   // lay ma san pham tu order
        order.erase(0, product_ID.length()+1);
        string temp = order.substr(0, order.find(" "));   // lay gia san pham tu order
        int price = stoi(temp); // chuyen gia san pham tu string sang int
        order.erase(0, temp.length()+1);
        string shop_ID = order.substr(0, order.find(" "));   // lay shop id tu order
        order.erase(0, shop_ID.length()+1);
        string time_point  = order ; // lay thoi gian order tu order
      // cout << customer_ID << " " << product_ID  << " " << shop_ID << " " << time_point <<"\n";

        //tao ra instance order moi 
        Order new_order(customer_ID, product_ID, price, shop_ID, time_point);

        //cap nhat data
        total_revenue += price; // tang tong so thap nhap len
        orders.push_back(new_order); // them order moi vao
        revenue_of_shop[shop_ID] +=price; // tang thu nhap cho shop
        total_consume_of_customer_shop[customer_ID + " " +shop_ID] += price; // them luong tieu thu cua khach voi 1 cua hang
        latest_order = max( latest_order,convertTimeToSeconds(time_point) );
        period_revenue[convertTimeToSeconds(time_point)] += price; // 
       //cout<<"total " <<customer_ID + " " +shop_ID <<" "<< total_consume_of_customer_shop[customer_ID + " " +shop_ID] <<"\n";
        //cout << "period_revenue["<<convertTimeToSeconds(time_point)<<"] = " <<   period_revenue[convertTimeToSeconds(time_point)]<<"\n";
    }

    

}

//xu ly cac cau truy van
void process_query () {
    //tính tổng cộng dồn 
    //cout<< "lastest" <<latest_order <<"\n";
    for (int i = 1; i <= latest_order; ++i) {
        period_revenue[i] += period_revenue[i - 1];
    }
  
    string query;
    while (true ){
        getline(cin, query);
        if (query == "#") return;
        if (query =="?total_number_orders") cout << orders.size()<<"\n";
        else if ( query == "?total_revenue") cout <<total_revenue<<'\n';
        else if (query.find("?revenue_of_shop")< query.length()) cout<<revenue_of_shop[query.substr(query.find(" ")+1)]<<"\n";
        else if (query.find("total_consume_of_customer_shop") < query.length() ){
            query.erase(0, query.find(" ")+1); //cat phan lenh truy van di
            //cout<< query<<"\n";
            cout << total_consume_of_customer_shop[query] <<"\n" ;
        }
        else if (query.find("?total_revenue_in_period") < query.length()){
            query.erase(0, query.find(" ") + 1); // bo di lenh truy van
            string from_time = query.substr(0, query.find(" "));  //lay ra thoi diem bat dau
            query.erase(0, query.find(" ") + 1);
            string to_time = query; // lay ra thoi diem ket thuc
            
            //tinh gia thoi gian bat dau va ket thuc
            int from_second = convertTimeToSeconds(from_time);
            int to_second = convertTimeToSeconds(to_time);
            //cout<< from_second << " " << to_second << "\n";
            //tinh tong revenue trong khoang thoi gian do 
            
            long long period_revenue_sum = (to_second <= latest_order) ? (period_revenue[to_second] - period_revenue[from_second - 1]) : period_revenue[latest_order]-period_revenue[from_second-1];
            //cout<< period_revenue[latest_order]  << " " << period_revenue[from_second]<<"\n";
            cout << period_revenue_sum << '\n';
        }

    }
}
int main () {
    freopen("order.inp","r", stdin);
    freopen("order.out","w", stdout);
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
    input_data();
    process_query();
    return 0;
}