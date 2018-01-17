#include <iostream>
#include <string.h>
using namespace std;

#define N 7
#define M 8

int row_num,col_num,T;
int maze_map[N][M];
int used_map[N][M];
int endX,endY;
int isOk = 0;
const int dir[4][2] = {1,0,0,1,-1,0,0,-1};
void disp_maze_map();
void dfs(int,int,int);
bool wall_detection(int,int);
int main(){
    while(cin >> row_num >> col_num >> T){
        if(row_num == 0 && row_num == 0 && T == 0){
            break;
        }
        memset(maze_map,0,sizeof(maze_map));
        memset(used_map,0,sizeof(used_map));
        isOk = 0;
        char tmp_char;
        int startX,startY;int t_parity = T % 2;int step_parity;
        for(int i = 0 ;i < row_num;++ i){
            for(int j = 0;j < col_num ;++ j){
                cin >> tmp_char;
                if(tmp_char == 'S'){
                    startX = i;
                    startY = j;
                    maze_map[i][j] = -1;
                }else if(tmp_char == 'D'){
                   endX = i;endY = j;
                }else if(tmp_char == 'X'){
                    maze_map[i][j] = 1;
                    step_parity = (abs(i - startX) + abs(j - startY)) % 2;
                }
            }
        }
        if(step_parity != t_parity){
            cout << "NO" <<endl;
            continue;
        }
        dfs(startX,startY,0);
        if(isOk){
            cout << "YES"<<endl;
        }else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

void disp_maze_map(){
    for(int i = 0;i < row_num;++ i){
        for(int j = 0;j < col_num;++ j){
            cout << maze_map[i][j] <<" ";
        }cout << endl;
    }
}

void dfs(int _x,int _y,int _layer){
    if(isOk){
        return;
    }
    if(_layer == T){
        if(_x == endX && _y == endY){
            isOk = 1;
        }
        //disp_maze_map();
        return;    
    }
    if(abs(_x-endX)+abs(_y-endY) > T-_layer){
        return;
    }
    if(abs(_x-endX)+abs(_y-endY)%2 != (T-_layer)%2){
        return;
    }
    int tmp_x,tmp_y;
    for(int i = 0;i < 4;++ i){
        tmp_x = _x + dir[i][0];
        tmp_y = _y + dir[i][1];
     //   cout << dir[i][0] << " " << dir[i][1] << endl;
        if(wall_detection(tmp_x,tmp_y)){
            if(used_map[tmp_x][tmp_y] == 0 && maze_map[tmp_x][tmp_y] != 1){
                used_map[tmp_x][tmp_y] = 1;
                dfs(tmp_x,tmp_y,_layer+1);
                used_map[tmp_x][tmp_y] = 0;
            }
        }
        if(isOk){
            return;
        }
    }
}

bool wall_detection(int _x,int _y){
    if(_x>-1 && _y > -1 && _x < row_num&& _y < col_num){
        return true;
    }
    return false;
}
/*
4 4 5 S . X . . . X . . . X D . . . .
3 4 5 S . X . . . X . . . . D
3 4 5 S . X D . . X . . . . .
3 4 9 S . X D . . X . . . . .
3 4 11 S . X D . . X . . . . .
3 4 11 S . X D . . X . . . . X
*/