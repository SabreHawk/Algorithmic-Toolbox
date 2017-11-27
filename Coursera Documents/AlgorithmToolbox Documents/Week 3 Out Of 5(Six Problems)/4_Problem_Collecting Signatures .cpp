#include <iostream>
#include <algorithm>
#include <stdio.h>
#include "stdlib.h"
#define MAX 101

using namespace std;
struct segment{int start;int end;};

int N = 0;
segment segmentsArr[MAX];
int pointsArr[MAX] = {0};
bool compare(segment _seg1,segment _seg2){
    return _seg1.start < _seg2.start;
}
int main(){
    scanf("%d",&N);
    for(int i = 0;i < N;++ i){
        scanf("%d%d",&segmentsArr[i].start,&segmentsArr[i].end);
    }
    sort(segmentsArr,segmentsArr + N,compare);
    int pointIndex = 0;
    pointsArr[0] = segmentsArr[0].end;
    for(int i  = 1; i < N;++ i){
//cout << segmentsArr[i].start << " "<<pointsArr[pointIndex]<<endl;
        if(segmentsArr[i].start > pointsArr[pointIndex]){
            ++ pointIndex;
//cout << pointIndex <<endl;            
            pointsArr[pointIndex]  = segmentsArr[i].end;
        }else{
            if(segmentsArr[i].end < pointsArr[pointIndex]){
                pointsArr[pointIndex] = segmentsArr[i].end;
            }
        }
    }
    cout << pointIndex + 1<<endl;
    for(int i  = 0 ;i <= pointIndex ;++ i){
        cout <<pointsArr[i] << " ";
    }cout << endl;
    system("Pause");
    return 0;
}