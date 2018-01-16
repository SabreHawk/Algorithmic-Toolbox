#include <iostream>
#include <vector>
#define MAX 1000
#define INF 1000000000
using namespace std;

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
int nodeSet[MAX];
void initSet();
bool checkPoint(int,int);
void mergePoint(int,int);
int findTop(int);
void showTree();
int main(){
    cin >> lineNum >> pointNum;
    line tempLine;
    for(int i = 0;i < lineNum;++ i){
        cin >> tempLine.pointOne >> tempLine.pointTwo >> tempLine.weight;
        lineArr.push_back(tempLine);
    }
    initSet();
    while(true){
        if(treeArr.size() == pointNum-1){
            break;
        }
        int tempMin = INF;
        line tempLine;
        vector<line>::iterator itor;
        for(itor = lineArr.begin();itor != lineArr.end();++ itor){
            if(itor->weight < tempMin&&(checkPoint(itor->pointOne,itor->pointTwo))){
                tempLine = *itor;
                tempMin = itor->weight;
            }
        }
        treeArr.push_back(tempLine);
        mergePoint(tempLine.pointOne,tempLine.pointTwo);
    }
    showTree();
    return 0;
}


void showTree(){
     cout <<"TREEARR"<<endl;
    vector<line>::iterator itor;
    for(itor = treeArr.begin();itor != treeArr.end();++ itor){
        cout << "( "<< itor->pointOne << " --- "<< itor->pointTwo << " : " << itor->weight <<" ) "<< endl; 
    }
}

void initSet(){
    for(int i = 0;i <= pointNum;++ i){
        nodeSet[i] = i;
    }
}

int findTop(int _index){
    if(_index == nodeSet[_index]){
        return _index;
    }else{
        findTop(nodeSet[_index]);
    }
}

void mergePoint(int _p1,int _p2){
    int indexOne = findTop(_p1);
    int indexTwo = findTop(_p2);
    nodeSet[indexOne] = indexTwo;
}

bool checkPoint(int _p1,int _p2){
    if(findTop(_p1) == findTop(_p2)){
        return false;
    }
    return true;
}
/*
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