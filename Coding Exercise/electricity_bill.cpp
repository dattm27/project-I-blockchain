#include<stdio.h>
#include<iostream>
using namespace std;
float oldBill (int kwh){
    int total = 0;
    int accumalation;


    if (kwh>=401){
        accumalation =50*1728 + 50*1786+ 100*2074+ 100*2612+  100*2919;
        total = (kwh-400) * 3015 + accumalation ;

    }
    else if (kwh >= 301){
        accumalation = 50*1728 + 50*1786+ 100*2074+ 100*2612;
        total = (kwh-300) * 2919 + accumalation ;
    }
    else  if (kwh >= 201){
        accumalation = 50*1728 + 50*1786+ 100*2074;
        total = (kwh-200) * 2612 + accumalation ;
    }
    else if (kwh >=101 ){
        accumalation = 50*1728 + 50*1786;
        total =(kwh-100) * 2074 + accumalation ;
    }
    else if (kwh >= 51) {
        accumalation = 50*1728;
        total = (kwh - 50) * 1786 + accumalation ;
    }
    else total = kwh * 1728;

    return total*1.1;
} 
float newBill (int kwh){
    int total = 0;
    int accumalation = 0;
   
    if (kwh>= 701){
        accumalation = 100*1728 + 100*2074 + 200*2612+  300*3111;
        total = (kwh-700) * 3457+ accumalation ;
    }
    else if (kwh >= 401){
        accumalation =100*1728 + 100*2074 + 200*2612;
        total = (kwh-400) * 3111 + accumalation ;
    }
    else if (kwh >= 201){
        accumalation = 100*1728 + 100*2074;
        total =(kwh-200) * 2612 + accumalation ;
    }
    else if (kwh>= 101) {
        accumalation = 100*1728;
        total = (kwh - 100) * 2074 + accumalation ;
    }
    else total = kwh * 1728;
    
  
    return total*1.1;
} 

int main (){
    
    int kwh;
    cin>> kwh;
    printf("%.2f",  newBill(kwh) - oldBill(kwh)) ;
    return 0;
}