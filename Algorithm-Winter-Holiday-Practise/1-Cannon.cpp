#include <iostream>
#include <string.h>
using namespace std;

#define M 5
#define N 5

int row_num,row_num,chess_num,max_cannon_num;
int chess_map[N][M];
const int dir[4][2] = {}
void cannon_dfs(int,int,int);
bool eat_detection(int,int);
int main(){
    while(cin >> row_num >> row_num >> chess_num){
        int tempX,tempY;
        max_cannon_num = 0;
        memset(chess_map,0,sizeof(chess_map));
        for(int i = 0;i < chess_num ;++ i){
            cin >> tempX >> tempY;
            chess_map[tempX][tempY] = 1;
        }
        cannon_dfs(0,0,0);
    }
    return 0;
}

void cannon_dfs(int _x,int _y,iny _layer){
    if(chess_map[_x][_y] != 1 && eat_detection(_x,_y)){

    }
}

bool eat_detection(int _x,int _y){
    int flag = 0;
    for(int i = _x;i < row_num;++ i){
        if(chess_map[i][_y]){
            ++ flag;
            if(flag > 2){
                return false;
            }
        } 
    }

    for(int i = _x;i > -1;-- i){
        if(chess_map[i][_y]){
            ++ flag;
            if(flag > 2){
                return false;
            }
        }
    }
    for(int j = _y;j < col_num;++ j){
        if(chess_map[_x][j]){
            ++ flag;
            if(flag > 2){
                return false;
            }
        } 
    }

    for(int j = _y;j > -1;-- j){
        if(chess_map[_x][j]){
            ++ flag;
            if(flag > 2){
                return false;
            }
        }
    }
    return true;
}
/* input
4 4 2
1 1 1 2
*/