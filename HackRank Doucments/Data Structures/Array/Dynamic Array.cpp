#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

vector< vector<long long> > seq(2);
vector<long long>::iterator itor;
long long N = 0;
long long Q = 0;
long long t = 0;
long long x = 0;
long long y = 0;
long long lastAns = 0;
    
    
void judgeValues(int,int,int);

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cin >> N >> Q;  
    for(int Q_i = 0;Q_i < Q;++ Q_i){
        cin >> t >> x >> y;
        judgeValues(t,x,y);
    }
    return 0;
}

void judgeValues(int _t,int _x,int _y){
    int tempIndex = int(_x ^ lastAns);
    int tempResult = tempResult % N;
    switch(_t){
        case 1:{ 
            seq[tempIndex].push_back(_y);
        }break;
        case 2:{
            int outIndex = _y % seq[tempIndex].size();
            lastAns = seq[tempIndex][outIndex];
            cout << lastAns <<endl;
        }break;
    }
}
