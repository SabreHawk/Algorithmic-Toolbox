#include <iostream>
#include "stdlib.h"
#define MAX 100001
using namespace std;

int N = 0;
int inputArr[MAX] = {0};
long long  ansNum = 0;
void mergeSort(int _start ,int _end){
    if(_end == _start) return ;
    int midIndex =_start + (_end - _start)/2;
    mergeSort(_start,midIndex);
    mergeSort(midIndex+1,_end);
    int ansArr[MAX] = {0};
    int ptrOne = _start;
    int ptrTwo = midIndex + 1;
    int ptrAns = 0;
    while(ptrOne <= midIndex && ptrTwo <= _end){
        if(inputArr[ptrOne] <= inputArr[ptrTwo]){
            ansArr[ptrAns ++ ] = inputArr[ptrOne ++ ];
        }else{
            ansArr[ptrAns ++ ] = inputArr[ptrTwo ++ ];
            ansNum += midIndex - ptrOne + 1;
        }
    }
    if(ptrOne>midIndex){
        for(int i = ptrTwo ; i <= _end;++ i){
            ansArr[ptrAns ++] = inputArr[i]; 
        }
        
    }
    if(ptrTwo > _end){
        for(int i = ptrOne;i <= midIndex;++ i){
            ansArr[ptrAns ++ ] = inputArr[i];
        }
    }
    int index = _start;
    for(int i = 0;i < ptrAns;++ i){
        inputArr[index ++ ] = ansArr[i];
    }
}

int main(){
    cin >> N;
    for(int i = 0;i < N;++ i){
        cin >> inputArr[i];
    }
    mergeSort(0,N-1);
    cout << ansNum <<endl;
    system("PAUSE");

    return 0;
}