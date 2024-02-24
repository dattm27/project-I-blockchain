#include<stdio.h>
#include<iostream>
using namespace std;
int x[9][9];
int counter =0;
void printSolution(){
	// printf("\n--------------------------\n");
	// for(int i = 0; i < 9; i++){
	// 	printf("\n");
	// 	for(int j = 0; j < 9; j++)
	// 		printf("%d ",x[i][j]);
	// }
	counter++;
	
}
bool check(int v, int r, int c){
    for(int i = 0 ; i<=  8 ; i++){
        if (x[r][i]==v && i!=c) return false; // kiểm tra nếu đã có số đó trên cùng hàng
    }
    for(int i = 0 ; i<=  8 ; i++){
        if (x[i][c]==v && i!=r) return false; // kiểm tra nếu đã có số đó trên cùng cột
    }
    //kiểm tra trong phạm vi 3x3
    int I = r/3;
	int J = c/3;
	int i = r - 3*I;
	int j = c - 3*J;
	for(int i1 = 0; i1 <= 2; i1++)
		for(int j1 = 0; j1 <= 2; j1++)
			if(x[3*I+i1][3*J+j1] == v)
				return false;
    // for(int j1 = 0; j1 <= 2; j1++)
    //     if(x[3*I+i][3*J+j1] == v)
    //         return false;
                
    return true;
}
void gen(int r, int c){

    if (x[r][c]!=0){
        if(r == 8 && c == 8){
            printSolution();
        }else{
            if(c == 8) gen(r+1,0);
            else gen(r,c+1);
        }
    }
    else { 
        for(int v = 1; v <= 9; v++){
		if(check(v,r,c)){
			x[r][c] = v;
			if(r == 8 && c == 8){
				printSolution();
			}else{
				if(c == 8) gen(r+1,0);
				else gen(r,c+1);
			}
            x[r][c] = 0;
		}
	    }
    }
}

int main(){
    freopen("Count_number_of_sudoku_solutions.inp","r",stdin);
    
    for(int i = 0 ; i<= 8; i++){
        for(int j = 0 ; j <= 8 ; j++){
            cin>> x[i][j];
        }
    }   

    gen(0,0);
    cout<< counter;
    return 0;
}