#include <iostream>
#include <algorithm>
#include "stdlib.h"
#define MAX 100001
using namespace std;

int N = 0;
int inputArr[MAX] = {0};
int arrLeft[MAX] = {0};
int arrRight[MAX] = {0};

void improvedSort(int _start,int _end){
    if(_start+1>_end){return;}
 //   cout << _start <<" "<<_end<<endl;
    int pivotNum = inputArr[_start];
    int rightIndex = 0;
    int leftIndex = 0;
    int pivotCount = 1;
    for(int i = _start+1;i < _end;++ i){
        if(inputArr[i] == pivotNum){
            ++ pivotCount ;
        }else if(inputArr[i] < pivotNum){
            arrLeft[leftIndex++] = inputArr[i];
        }else if(inputArr[i] > pivotNum){
            arrRight[rightIndex++] = inputArr[i];
        }
    }
    for(int i = _start ;i <_start + leftIndex;++ i){
        inputArr[i] = arrLeft[i - _start];
   //     cout <<i <<" : "<<inputArr[i]<<endl;
    }
    for(int i = _start + leftIndex;i < _start + leftIndex + pivotCount;++ i){
        inputArr[i] = pivotNum;
    }
    for(int i = _start + leftIndex + pivotCount;i < _end;++ i){
        inputArr[i] = arrRight[i-_start-leftIndex-pivotCount];
    }
    improvedSort(_start,_start +leftIndex);
    improvedSort(_start + leftIndex+pivotCount,_end);
}
int main(){
    cin >> N;
    for(int i = 0 ;i < N;++ i){
        cin >> inputArr[i];
    }
    improvedSort(0,N);
    for(int i =0;i < N;++ i){
        cout << inputArr[i] <<" ";
    }
    system("PAUSE");
    return 0;
}