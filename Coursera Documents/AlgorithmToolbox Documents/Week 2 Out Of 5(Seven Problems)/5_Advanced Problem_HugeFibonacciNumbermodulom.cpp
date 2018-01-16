#include "stdlib.h"
#include <iostream>
#include <stdio.h>
#define MAX 10000000
using namespace std;

long long n = 0;
int m = 0;
int periodLengthArr[MAX] = {0};

int periodLength();
int main(){
    periodLengthArr[0] = 0;
    periodLengthArr[1] = 1;
    cin >> n >> m;
    int T =  periodLength();
   // cout << "T : "<<T <<endl;
    int currentIndex = n % T;
   // cout << "Cindex : "<<currentIndex <<endl;

    cout << periodLengthArr[currentIndex]<<endl;
    return 0;
}
int periodLength(){
    int pLength = 2;
    int index = 2;
    while(index <= n){
        periodLengthArr[index] = (periodLengthArr[index - 1] + periodLengthArr[index - 2]) % m;
    //    cout <<"index : " << index << "  "<<periodLengthArr[index]<<endl;

        if(index % 2 == 1 &&periodLengthArr[index] == 1 && periodLengthArr[index - 1 ] == 0){
            return index -1;
        }
        if(index == n){
            return n + 1;
        }
        ++ index;
    }
}
