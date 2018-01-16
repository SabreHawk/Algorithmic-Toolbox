#include <iostream>
#include <string.h>
using namespace std;

#define M 5
#define N 5

int col_num,row_num,chess_num;
int chess_map[N][M];
int setCannon(int,int);
bool rowCannonDetection(int,int);
bool colCannonDetection(int,int);
bool chessBewteenDetection(int,int);

int main(){
 
    while(cin >> col_num >> row_num >> chess_num){
        memset(chess_map,0,sizeof(chess_map));
        int tempX,tempY;
        for(int i = 0 ;i < chess_num ;++ i){
            cin >> tempX >> tempY;
            chess_map[tempX][tempY] = 1;
        }

    }
}

int setCannon(int _layer,int _cannon_num){
    for(int i = 0 ;i < col_num;++ i){
        for(int j = 0;j < row_num;++ j){
            if(i > 1 && chess_map[i-1][j] && chess_map[i-2][j] != -1)
        }
    }
}

bool chessBewteenDetection(int _row,int _col){

}