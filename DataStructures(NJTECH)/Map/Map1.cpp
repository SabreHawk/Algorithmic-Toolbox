#include <iostream>
#include <vector>
#include <set>
#define MAX 1000
using namespace std;
struct node{
    int targetIndex;
    node * nodePtr;
    node(int _value):targetIndex(_value),nodePtr(NULL){

    }
    node(){
    	
	}
}; 
int N = 0;
int T = 0;
int pointOne = 0;
int pointTwo = 0;
int map[MAX][MAX] = {0};
int map2[MAX][MAX] = {0};
node nodeMap[MAX];
int searchCount = 0;
int widthCount = 0;
set<int> WFSSet;
void nodeAdd(int _pointOne,int _pointTwo);
void showMap();
void showNodeMap();
void DFS(int i);
void WFS(set<int> _set);
int main(){
    cin >> N >> T;
    for(int N_i = 0;N_i < N; ++ N_i){
        cin >> pointOne >> pointTwo;
        map[pointOne][pointTwo] = 1;
        map[pointTwo][pointOne] = 1;
        map2[pointOne][pointTwo] = 1;
        map2[pointTwo][pointOne] = 1;
        nodeAdd(pointOne,pointTwo);
    }
    showMap();
    cout << endl << endl;
    showNodeMap();
    DFS(1);
    for(int i = 0;i <= T;++ i){
    	for(int j = 0;j <= T;++ j){
    		map[i][j] = map2[i][j]; 
		}
	}
	cout<<endl<<endl;
	WFSSet.insert(1);
	WFS(WFSSet);
    cin.get();
    cin.get();

    return 0;
}

void nodeAdd(int _pointOne,int _pointTwo){
    node * tempPtr1 = &nodeMap[_pointOne];
    node * newNode1 = new node(_pointTwo);
    while(tempPtr1->nodePtr!=NULL){
        if(tempPtr1->targetIndex == _pointTwo) return;
        tempPtr1 = tempPtr1->nodePtr;
    }
    tempPtr1->nodePtr = newNode1;
    
    node * tempPtr2 = &nodeMap[_pointTwo];
    node * newNode2 = new node(_pointOne);
    while(tempPtr2->nodePtr!=NULL){
        if(tempPtr2->targetIndex == _pointOne) return;
        tempPtr2 = tempPtr2->nodePtr;
    }
    tempPtr2->nodePtr = newNode2;

}

void showMap(){
    for(int i = 1;i <= T;++ i){
        for(int j = 1;j <= T;++ j){
            cout << map[i][j]<<" ";
        }cout << endl;
    }
}

void showNodeMap(){
    node * tempNode = NULL;
    for(int i = 1;i <= T;++ i){
        tempNode = &nodeMap[i];
        cout << i;
        while(tempNode->nodePtr!=NULL){
              tempNode = tempNode -> nodePtr;
            cout <<" --> "<< tempNode->targetIndex;
          
        }cout << endl;
    }
}

void DFS(int _i){
    //cout <<"_i " <<_i<<endl;
    if(searchCount == N * 2){
        cout << searchCount <<" s"<<endl;
        showMap();
        return;
    }

    for(int j = 0;j <= T;++ j){
       // cout << j<<endl;
      //  showMap();
        if(map[_i][j] == 1){
            cout << "DFS : ( "<<_i<<" --> "<<j<<" ) "<<endl; 
            map[_i][j] = 0;
            map[j][_i] = 0;
            for (int k = 0;k <= T;++ k){
            	map[k][j] = 0;
			}
			for(int k = 0;k <= T;++ k){
				map[k][_i] = 0;
			} 
            DFS(j);
            searchCount += 2;
       //     cout << searchCount << endl;
        }
    }
}

void WFS(set<int> _set){
	if(_set.size() == 0){
		return ;
	} 
    set<int> nextWFSSet;
    //cout << "WIDTHCOUNT "<<widthCount<<endl;
    set<int>::iterator itor;
    cout <<"Set Num :";
    for(itor = _set.begin();itor != _set.end();++ itor){
		cout << *itor<<" ";
	}cout<<endl;

    for(itor = _set.begin();itor != _set.end();++ itor){
        for(int j = 0;j <= T;++ j){
        	if(map[j][*itor] == 1){
        		map[j][*itor] = 0;
        		widthCount ++;
			}
            
        }
      //  showMap();cout<<endl;
        for(int i = 0;i <= T;++ i){
        	if(map[*itor][i] == 1){
        	  	nextWFSSet.insert(i);
        	  	map[*itor][i] = 0;
        	  	widthCount ++ ;
                  for(int j = 0;j <= T;++ j){
                      if(map[j][i] == 1){
                          map[j][i] = 0;
                      }
                  }
			}
 
		}
    }
	cout << endl;
	WFS(nextWFSSet);
}
/*
9 6
1 2
2 3
3 5
2 5
2 4
1 4
1 6
4 6
4 5
*/
