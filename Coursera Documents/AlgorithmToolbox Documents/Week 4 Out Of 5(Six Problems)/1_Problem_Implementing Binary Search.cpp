#include <iostream>
#include "stdlib.h"
#define MAX 100001
using namespace std;


int N = 0;
int K = 0;
int upArr[MAX] = {0};
int downArr[MAX] = {0};
int binarySearch(int _targetNum,int _head,int _tail){
    int midIndex = _head + (_tail -  _head)/2;
    if(_tail < _head){
        return -1;
    }
    if(upArr[midIndex] == _targetNum){
        return midIndex;
    }else if( upArr[midIndex] < _targetNum){
        binarySearch(_targetNum,midIndex+1 ,_tail);
    }else if( upArr[midIndex] > _targetNum){
        binarySearch(_targetNum,_head, midIndex-1);
    }
}
int main(){
    cin >> N;
    for(int i = 0;i < N;++ i){
        cin >> upArr[i];
    }
    cin >> K;
    for(int i = 0;i < K;++ i){
        cin >> downArr[i];
    }
    for(int i = 0;i < K;++ i){
        cout << binarySearch(downArr[i],0,N-1) << " ";
    }
    system("PAUSE");
    return 0;
}