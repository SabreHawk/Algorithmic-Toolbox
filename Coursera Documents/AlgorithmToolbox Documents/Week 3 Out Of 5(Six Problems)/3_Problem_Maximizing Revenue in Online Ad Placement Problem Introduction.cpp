#include <iostream>
#include <algorithm>
#include <stdio.h>
#include "stdlib.h"

#define MAX  10000000
using namespace std;


int N = 0;
int aArr[MAX] = {0};
int bArr[MAX] = {0};
bool compare(int _num1,int _num2){
    return _num1 > _num2;
}
int main(){
    scanf("%d",&N);
    for(int i = 0;i < N;++ i){
        scanf("%d",&aArr[i]);
    }
    for(int i = 0;i < N;++ i){
        scanf("%d",&bArr[i]);
    }
    sort(aArr,aArr + N,compare);
    sort(bArr,bArr + N,compare);
    long long sum =(long long) aArr[0] * bArr[0];
    for(int i = 1;i < N;++ i){
        sum +=(long long) aArr[i] * bArr[i];
    }
   cout << sum << endl;
    system("Pause");
    return 0;
}
