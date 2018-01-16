#include <iostream>
#include <stdio.h>
#include "stdlib.h"
using namespace std;

int N = 0;
int coinNum = 0;
int main(){
    scanf("%d",&N);
    while(N>0){
        if(N>=10){
            coinNum += N / 10;
            N %= 10;
        }
        if(N>=5){
            coinNum += N/5;
            N %= 5;
        }
        if(N>=1){
            coinNum += N;
            break;
        }
    }
    printf("%d\n",coinNum);
    system("Pause");
    return 0;
}