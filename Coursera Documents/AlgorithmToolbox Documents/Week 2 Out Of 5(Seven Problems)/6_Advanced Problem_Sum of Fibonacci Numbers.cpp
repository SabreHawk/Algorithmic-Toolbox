#include "stdlib.h"
#include <iostream>
#include <stdio.h>
#define MAX 10000000
using namespace std;

long long n = 0;
int periodLengthArr[MAX] = {0};
int sumT = 1;
int periodLength();
int main(){
    periodLengthArr[0] = 0;
    periodLengthArr[1] = 1;
    cin >> n;
    int T =  periodLength();
   // cout << "T : "<<T <<endl;
    int numT = n / T;
    int currentIndex = n % T;
    long long sumResult = numT * sumT;
    sumResult %= 10;
    for(int i = 0;i <= currentIndex;++ i){
        sumResult += periodLengthArr[i];
        sumResult %= 10;
    }
    cout << sumResult%10 <<endl;
    system("Pause");
    return 0;
}
int periodLength(){
    int pLength = 2;
    int index = 2;
    while(index <= n){
        periodLengthArr[index] = (periodLengthArr[index - 1] + periodLengthArr[index - 2]) % 10;
        sumT += periodLengthArr[index];
        sumT %= 10;
        if(index % 2 == 1 &&periodLengthArr[index] == 1 && periodLengthArr[index - 1 ] == 0){
            sumT -= 1;
            return index -1;
        }
        if(index == n){
            return n + 1;
        }
        ++ index;
    }
}
