#include <iostream>
#include <algorithm>
#include "stdlib.h"
#define MAX 50001
using namespace std;

struct Node{
    int rightMargin;
    int leftMargin;
};
int S = 0;
int P = 0;
struct Node nodeArr[MAX];

bool compare(Node _node1,Node _node2){
    if(_node1.leftMargin == _node2.leftMargin){
        return _node1.rightMargin < _node2.rightMargin;
    }
    return _node1.leftMargin < _node2.leftMargin;
}
int main(){
    cin >> S >> P;
    for(int i = 0;i < S;++ i){
        cin >> nodeArr[i].leftMargin >> nodeArr[i].rightMargin;
    }
    sort(nodeArr,nodeArr+S,compare);
    for(int i = 0 ;i < P;++ i){
        int num = 0;
        cin >> num;
        int ansNum = 0;
        int segmentIndex = 0;
        while(nodeArr[segmentIndex].leftMargin <= num && segmentIndex < S){
            if(nodeArr[segmentIndex++].rightMargin>= num){
                ++ ansNum;
            }
        }
        cout <<ansNum <<" ";
    }cout <<endl;

    system("PAUSE"); 
    return 0;
}

