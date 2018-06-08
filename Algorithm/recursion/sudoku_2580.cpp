#include <cstdio>
#include <iostream>
#include <cstdlib>


using namespace std;


int board[15][15];
bool check_row[15][15];
bool check_col[15][15];
bool check_box[15][15];



void printboard(){

	for(int i = 0; i < 9 ; i++){
		for(int j = 0 ; j< 9 ; j++)
			printf("%d ", board[i][j]);
		printf("\n");
	}

}






int mach(int num){

	if(num == 81){
		printboard();
		return true;
	}
	
	int x = num/9; int y= num%9;
	
	if(board[x][y] != 0){
		mach(num+1);
	}
	else{
		for(int j = 1; j <= 9 ; j++){
			if(check_row[x][j] == false && check_col[y][j] == false && check_box[(x/3)*3 + y/3][j] == false){
				board[x][y] = j;
				check_row[x][j] = true;
				check_col[y][j] = true;
				check_box[(x/3)*3 + y/3][j] = true;
				if(mach(num+1))
					return true;
				board[x][y] = 0;
				check_row[x][j] = false;
				check_col[y][j] = false;
				check_box[(x/3)*3 + y/3][j] = false;
				

			}
		}
	}

	return false;

}





int main(){

	for(int i = 0; i < 9 ; i++)
		for(int j = 0 ; j< 9 ; j++){
			scanf("%d", &board[i][j]);
			check_row[i][board[i][j]] = true;
			check_col[j][board[i][j]] = true;
			check_box[(i/3)*3 + j/3][board[i][j]] = true;
		}


	mach(0);



}