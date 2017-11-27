#include <iostream>
#include <stdio.h>
#include <algorithm>
#include "stdlib.h"
#define MAX 1000000

using namespace std;

int N = 0;
int numArr[MAX] = {0};
int totalNum = 0;
int main(){
    scanf("%d",&N);
    for(int i = 1;i <= N;++ i){
        if(totalNum + i <= N){
            numArr[i] = i;
            totalNum += i;
            if(totalNum == N){
                cout << i <<endl;
                for(int k = 1;k <= i;++ k){
                    cout << numArr[k] <<" ";
                }
                break;
            }
        }else{
            numArr[i-1] = N - totalNum + i - 1;
            cout << i - 1 <<endl;
            for(int k = 1;k < i;++ k){
                cout << numArr[k]<<" ";
            }
            break;
        }
    }
system("PAUSE");
    return 0;
}