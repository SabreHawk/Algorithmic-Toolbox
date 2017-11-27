#include <iostream>
#include <algorithm>
#include <stdio.h>
#include "stdlib.h"
#define MAX 10000000
using namespace std;
struct item{int value;int weight;double ratio;};

int  N = 0;
int W = 0;
item itemsArr[MAX];
double maxValue = 0;
double currentWeight = 0;
bool compare(item _item1,item _item2){
    return _item1.ratio > _item2.ratio;
}

int main(){
    scanf("%d%d",&N,&W);
    for(int i = 0;i < N;++ i){
        scanf("%d%d",&itemsArr[i].value,&itemsArr[i].weight);
        itemsArr[i].ratio = (double)itemsArr[i].value / itemsArr[i].weight;
    }
    sort(itemsArr,itemsArr + N,compare);
    for(int i = 0;i < N;++ i){
        if(itemsArr[i].weight + currentWeight <= W){
            maxValue += itemsArr[i].value;
            currentWeight += itemsArr[i].weight;
        }else{
            double tempWeight = W - currentWeight;
            maxValue += (double)tempWeight * itemsArr[i].ratio;
            break;
        }
    }
    printf("%.4lf\n",maxValue);
    system("Pause");

    return 0;
}