#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include "stdlib.h"
#define MAX 100001
using namespace std;

struct Node{
    int xPos;
    int yPos;
};
int N = 0;
Node nodeArr[MAX];
Node nodeArrY[MAX];
Node midNodeArr[MAX];
bool compareX(Node _node1,Node _node2){
    if(_node1.xPos == _node2.xPos){
        return _node1.yPos < _node2.yPos;
    }
    return _node1.xPos < _node2.xPos;
}
bool compareY(Node _node1,Node _node2){
    if(_node1.yPos == _node2.yPos){
        return _node1.xPos < _node2.yPos;
    }
    return _node1.yPos < _node2.yPos;
}
double calculateDis(int _indexOne,int _indexTwo){
    double rtnDis = sqrt(pow(abs(nodeArr[_indexOne].xPos - nodeArr[_indexTwo].xPos),2) + pow(abs(nodeArr[_indexOne].yPos - nodeArr[_indexTwo].yPos),2));
    return rtnDis;
}
double divideSeek(int _leftMargin,int _rightMargin){
    if(_leftMargin == _rightMargin){
        return 0.0;
    }
    if(_rightMargin - _leftMargin == 1){
//cout <<' ( '<< nodeArr[_rightMargin].xPos <<' , '<<nodeArr[_rightMargin].yPos<<' ) '<<endl;
//cout << '(' << nodeArr[_leftMargin].xPos <<' , '<<nodeArr[_leftMargin].yPos <<' ) '<<endl;
//cout << calculateDis(_rightMargin,_leftMargin);
        return calculateDis(_rightMargin,_leftMargin);
    }else if(_rightMargin  - _leftMargin == 2){
        double tempDis01 = calculateDis(_leftMargin,_leftMargin+1);
        double tempDis12 = calculateDis(_leftMargin+1,_leftMargin + 2);
        double tempDis02 = calculateDis(_leftMargin,_leftMargin+2);
        double tempMin = tempDis01 < tempDis02 ? tempDis01 : tempDis02;
        tempMin = tempMin < tempDis12 ? tempMin : tempDis12;
//cout <<' ( '<< nodeArr[_rightMargin].xPos <<' , '<<nodeArr[_rightMargin].yPos<<' ) '<<endl;
//cout << '(' << nodeArr[_leftMargin].xPos <<' , '<<nodeArr[_leftMargin].yPos <<' ) '<<endl;
//cout << tempMin<<endl;
        return tempMin; 
    }else{
            int mid = _leftMargin + (_rightMargin -_leftMargin)/2;
            double tempLeftMin = divideSeek(_leftMargin,mid);
            double tempRightMin = divideSeek(mid+1 ,_rightMargin);
            double tempLRMin = min(tempLeftMin,tempRightMin);
            double divideLineXPos = (nodeArr[mid].xPos + nodeArr[mid+1].xPos)/2;
            double leftLineXPos = divideLineXPos - tempLRMin;
            double rightLineXPos = divideLineXPos + tempLRMin;
            int tempIndex = 0;
            for(int i = _leftMargin;i <= _rightMargin;++ i){
                if(leftLineXPos <= nodeArr[i].xPos && nodeArr[i].xPos <= rightLineXPos){
                    midNodeArr[tempIndex++] = nodeArr[i];
                    continue;
                }
                if(nodeArr[i].xPos > _rightMargin){
                    break;
                }
            }
            sort(midNodeArr,midNodeArr + tempIndex,compareY);
            double rtnMin = tempLRMin;
            for(int i = 0;i < tempIndex;++ i){
                for(int j = i+1;j < tempIndex ;++ j){
                    if(midNodeArr[j].yPos - midNodeArr[i].yPos > rtnMin) {break;}   
                    double xOffset = abs(midNodeArr[i].xPos - midNodeArr[j].xPos);
                    double yOffset = abs(midNodeArr[i].yPos - midNodeArr[j].yPos);
                    double temp = sqrt(yOffset*yOffset + xOffset * xOffset);
                    if(temp < rtnMin){
                        rtnMin = temp;
                    }
                }
            }
//cout <<' ( '<< nodeArr[_rightMargin].xPos <<' , '<<nodeArr[_rightMargin].yPos<<' ) '<<endl  << endl;;
//cout << '(' << nodeArr[_leftMargin].xPos <<' , '<<nodeArr[_leftMargin].yPos <<' ) '<<endl;
//cout << rtnMin <<endl;
            return rtnMin;
    }
}


int main(){
    cin >> N;
    for(int i = 0;i < N;++ i){
        cin >> nodeArr[i].xPos >> nodeArr[i].yPos;
        nodeArrY[i].xPos = nodeArr[i].xPos;
        nodeArrY[i].yPos = nodeArr[i].yPos;
    }
    sort(nodeArr,nodeArr + N,compareX);
    double result =  divideSeek(0,N-1);
    printf("%.5lf",result);
    system("PAUSE");
    return 0;
}