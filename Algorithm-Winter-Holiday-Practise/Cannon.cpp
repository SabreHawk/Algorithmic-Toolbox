#include <iostream>
#include <string.h>
using namespace std;

#define M 5
#define N 5

int row_num,col_num,chess_num,max_cannon_num;
int chess_map[N][M];

void cannon_dfs(int,int,int);
bool eat_detection(int,int);
int main(){
    while(cin >> row_num >> col_num >> chess_num){
        int tempX,tempY;
        max_cannon_num = 0;
        memset(chess_map,0,sizeof(chess_map));
        for(int i = 0;i < chess_num ;++ i){
            cin >> tempX >> tempY;
            chess_map[tempX][tempY] = 1;
        }
        cannon_dfs(0,0,0);
        cout << max_cannon_num << endl;
    }
    return 0;
}

void cannon_dfs(int _x,int _y,int _layer){
    if(_x >= row_num){
        if(_layer > max_cannon_num){
            max_cannon_num = _layer;
        }
        return;
    }
    if(_y >= col_num){
        cannon_dfs(_x+1,0,_layer);
        return;
    }
    cannon_dfs(_x,_y+1,_layer);

    if(chess_map[_x][_y] == 0 && eat_detection(_x,_y)){
        chess_map[_x][_y] = 2;
        cannon_dfs(_x,_y+1,_layer+1);
        chess_map[_x][_y] = 0;
    }
}

bool eat_detection(int _x,int _y){
    int flag = 0;
    for(int i = _x;i > -1 ;-- i){
        if(chess_map[i][_y] == 1){
            ++ flag;
        }else if(chess_map[i][_y] == 2){
            if(flag==1){
                return false;
            }else{
                ++ flag;
            }
        }
    }
    flag = 0;
    for(int j = _y;j > -1 ;-- j){
        if(chess_map[_x][j]==1){
            ++ flag;
        }else if(chess_map[_x][j] == 2){
            if(flag == 1){
                return false;
            }else{
                ++ flag;
            }
        }
    }
    return true;
}
/* input
4 4 2 1 1 1 2
5 5 8 0 0 1 0 1 1 2 0 2 3 3 1 3 2 4 0 
*/