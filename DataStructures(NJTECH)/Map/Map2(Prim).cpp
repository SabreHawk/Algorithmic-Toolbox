#include <iostream>
#include <vector>
#define MAX 1000
#define INF 1000000000
using namespace std;
struct node{
    int value;
    node * nodePtr;
    node(int _value):value(_value),nodePtr(NULL){
    }
    node(){
    }
};
struct line{
    int pointOne;
    int pointTwo;
    int weight;
};

int lineNum = 0;
int pointNum = 0;
int weight = 0;

vector<line> lineArr;
vector<line> treeArr;
node nodeArr[MAX];
void nodeAdd(int,int);
bool checkPoint(int _p1,int _p2);
void unionPoint(int _p1,int _p2);
void deleteLine(line);
void showTree();
void showNodeMap();
int main(){
    cin >> lineNum >> pointNum;
    line tempLine;
    for(int i = 0;i < lineNum;++ i){
        cin >> tempLine.pointOne >> tempLine.pointTwo >> tempLine.weight;
        lineArr.push_back(tempLine);
    }
    while(true){
        showNodeMap();cout <<endl;
        if(treeArr.size() == pointNum){
            break;
        }
        int tempMin = INF;
        vector<line>::iterator itor;
        vector<line>::iterator tempLine;
        for(itor = lineArr.begin();itor != lineArr.end();++ itor){
            if(itor->weight < tempMin&&(checkPoint(itor->pointOne,itor->pointTwo))){
                tempLine = itor;
                tempMin = itor->weight;
             //   cout <<itor->pointOne<<"--"<<itor->weight<<"--"<<itor->pointTwo <<endl;
            }
        }
       // cout << "tempMIN : " << tempLine->weight <<endl;
        treeArr.push_back(*tempLine);
        unionPoint(tempLine->pointOne,tempLine->pointTwo);
      //  deleteLine(*tempLine);
        tempLine = lineArr.erase(tempLine);
    }
    showTree();
    cin.get();
    cin.get();
    return 0;
}

bool checkPoint(int _p1,int _p2){
    node * tempNode = &nodeArr[_p1];
    while(tempNode->nodePtr!=NULL){
        if(tempNode->value == _p2){
            return false;
        }
        tempNode = tempNode->nodePtr; 
    }
    tempNode = &nodeArr[_p2];
    while(tempNode->nodePtr!=NULL){
        if(tempNode->value == _p1){
            return false;
        }
        tempNode = tempNode->nodePtr;
    }
    return true;
}

void deleteLine(line _line){
    node * tempNode = &nodeArr[_line.pointOne];
    while(tempNode->nodePtr != NULL){
        if(tempNode->value == _line.pointTwo){
            node * freeNode =  tempNode->nodePtr;
            tempNode->nodePtr = tempNode->nodePtr->nodePtr;
            delete(freeNode);
            break;
        }
    }
    tempNode = &nodeArr[_line.pointTwo];
    while(tempNode->nodePtr != NULL){
        if(tempNode->value == _line.pointOne){
            node * freeNode =  tempNode->nodePtr;
            tempNode->nodePtr = tempNode->nodePtr->nodePtr;
            delete(freeNode);
            break;
        }
    }
}

void showTree(){
     cout <<"TREEARR"<<endl;
    vector<line>::iterator itor;
    for(itor = treeArr.begin();itor != treeArr.end();++ itor){
        cout << "( "<< itor->pointOne << " --- "<< itor->pointTwo << " : " << itor->weight <<" ) "<< endl; 
    }
}
void showNodeMap(){
    node * tempNode = NULL;
    for(int i = 1;i <= pointNum;++ i){
        tempNode = &nodeArr[i];
        cout << i;
        while(tempNode->nodePtr!=NULL){
              tempNode = tempNode -> nodePtr;
            cout <<" --> "<< tempNode->value;
          
        }cout << endl;
    }
}

void nodeAdd(int _pointOne,int _pointTwo){
    node * tempPtr1 = &nodeArr[_pointOne];
    node * newNode1 = new node(_pointTwo);
    while(tempPtr1->nodePtr!=NULL){
        if(tempPtr1->value == _pointTwo) return;
        tempPtr1 = tempPtr1->nodePtr;
    }
    tempPtr1->nodePtr = newNode1;
    
    node * tempPtr2 = &nodeArr[_pointTwo];
    node * newNode2 = new node(_pointOne);
    while(tempPtr2->nodePtr!=NULL){
        if(tempPtr2->value == _pointOne) return;
        tempPtr2 = tempPtr2->nodePtr;
    }
    tempPtr2->nodePtr = newNode2;

}

void unionPoint(int _p1,int _p2){
    node * tempNode = &nodeArr[_p1];
    while(tempNode->nodePtr != NULL){
        tempNode = tempNode -> nodePtr;
    }
    tempNode->nodePtr = new node(_p2);
    tempNode = &nodeArr[_p2];
    while(tempNode->nodePtr != NULL){
        tempNode = tempNode -> nodePtr;
    }
    tempNode->nodePtr = new node(_p1);
}
/* TEST CASE
8 6
1 2 6
1 3 3
2 4 1
3 4 6
3 5 6
2 6 5
4 6 5
5 6 2
*/