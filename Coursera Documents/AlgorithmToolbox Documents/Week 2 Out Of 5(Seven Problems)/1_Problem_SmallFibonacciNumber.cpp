#include <iostream>
#include <stdio.h>
#include "stdlib.h"
#define MAX 10000000
using namespace std;

int indexNum = 0;
int fibonacciArr[MAX] = {0};

int main(){
    fibonacciArr[0] = 0;
    fibonacciArr[1] = 1;
    scanf("%d",&indexNum);
    for(int i = 2;i <= indexNum;++ i){
        fibonacciArr[i] = fibonacciArr[i-1] + fibonacciArr[i-2];
    }
    printf("%d\n",fibonacciArr[indexNum]);
    system("Pause");
    return 0;   
}