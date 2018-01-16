#include <iostream>
#define MAX 101
using namespace std;

int arrMap[3][MAX] = {0};
int lengthArr[3] = {0};
int ansMap[MAX][MAX][MAX] = {0};
int max(int _num1,int _num2,int _num3,int _num4,int _num5){
    _num1 = _num1 > _num2 ? _num1 : _num2;
    _num1 = _num1 > _num3 ? _num1 : _num3;
    _num1 = _num1 > _num4 ? _num1 : _num4;
    _num1 = _num1 > _num5 ? _num1 : _num5;
    return _num1;
}

int main(){
    for(int i = 0;i < 3;++ i){
        cin >> lengthArr[i];
        for(int j = 0;j < lengthArr[i];++ j){
            cin >> arrMap[i][j];
        }
    }
    for(int i = 1;i <= lengthArr[0];++ i){
        for(int j = 1;j <= lengthArr[1];++ j){
            for(int k = 1;k <= lengthArr[2];++ k){
                int tempNum01 = ansMap[i][j][k-1];
                int tempNum02 = ansMap[i][j-1][k];
                int tempNum03 = ansMap[i-1][j][k];
                int tempNum04 = ansMap[i][j-1][k-1];
                int tempNum05 = ansMap[i-1][j][k-1];
                int tempNum06 = ansMap[i-1][j-1][k];
                if(arrMap[0][i-1]== arrMap[1][j-1] && arrMap[0][i-1] == arrMap[2][k-1] && arrMap[1][j-1] == arrMap[2][k-1]){
                    ansMap[i][j][k] = ansMap[i-1][j-1][k-1] + 1;
                }else{
                    ansMap[i][j][k] = max(tempNum01,tempNum02,tempNum03,tempNum04,tempNum05);
                }
            }
        }
    }
    cout << ansMap[lengthArr[0]][lengthArr[1]][lengthArr[2]]<<endl;
    return 0;
}