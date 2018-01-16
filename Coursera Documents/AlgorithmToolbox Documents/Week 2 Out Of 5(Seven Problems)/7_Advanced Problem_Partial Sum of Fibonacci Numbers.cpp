#include "stdlib.h"
#include <iostream>
#include <cmath>
#include <stdio.h>
#define MAX 10000000
using namespace std;

long long m = 0;
long long n = 0;
int periodLengthArr[MAX] = {0};
int sumT = 1;
int periodLength();
int main(){
    periodLengthArr[0] = 0;
    periodLengthArr[1] = 1;
    cin >> m >> n;
    int T =  periodLength();
   // cout << "T : "<<T <<endl;
    int numT = n / T;
    int perNumT = m / T;
    int perCurrentIndex = m% T;
    int currentIndex = n % T;
    long long sumResult = numT * sumT;
    long long perSumResult = perNumT * sumT; 
    sumResult %= 10;
    perSumResult %= 10;
    for(int i = 0;i <= currentIndex;++ i){
        sumResult += periodLengthArr[i];
        sumResult %= 10;
    }
    for(int i=0;i<perCurrentIndex;++ i){
        perSumResult += periodLengthArr[i];
        perSumResult %= 10;
    }
//cout <<"P: "<<perCurrentIndex << " " << "C : "<<currentIndex<<endl;
//cout <<"Per" << perSumResult <<endl;

//cout <<"curr" << sumResult <<endl;
if(sumResult <10) sumResult += 10; 

cout << abs(sumResult - perSumResult)%10 <<endl;
    system("Pause");
    return 0;
}
int periodLength(){
    int pLength = 2;
    int index = 2;
    while(1){
        periodLengthArr[index] = (periodLengthArr[index - 1] + periodLengthArr[index - 2]) % 10;
        sumT += periodLengthArr[index];
        sumT %= 10;
        if(index % 2 == 1 &&periodLengthArr[index] == 1 && periodLengthArr[index - 1 ] == 0){
            sumT -= 1;
            return index -1;
        }
        ++ index;
    }
}
