#include <iostream>
#include <algorithm>
#define MAX 100001
#include "stdlib.h"

using namespace std;

int N = 0;
int inputArr[MAX]  = {0};
int countArr[MAX] = {0};
int main(){
    cin >> N;
    for(int i = 0;i < N;++ i){
        cin >> inputArr[i];
    }
    sort(inputArr,inputArr+N);
    int currentIndex = 0;
    countArr[0] = 1;
    for(int i = 1;i < N;++ i){
        if(inputArr[i] == inputArr[i-1]){
            ++ countArr[currentIndex];
             if(countArr[currentIndex] > N/2){
                cout << 1;
                system("PAUSE");
                return 0;
            }
        }else{
            ++ currentIndex;
            ++countArr[currentIndex];
        }
    }
    cout << 0;

system("PAUSE");
    return 0;

}