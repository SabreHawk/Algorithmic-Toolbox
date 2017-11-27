#include <iostream>
#include <cstring>
#include "stdlib.h"

using namespace std;

int T = 0;
int N = 0;
int S = 0;
bool check(int  _num,int _j){
	int Arr[100000] = {0};
	int length = 0;
	while(_num>0){
		tempNum[length ++]= _num%_j;
		_num /= _j;
	}
	for(int i = 0;i <= length/2;++ i){
		if(tempNum[i] != tempNum[length-1-i]){
			return false;
		}
	}
	return true;
}
int main(){
	cin >> T;
	for(int i = 0;i < T;++ i){
		cin >> N >> S;
		S ++;
		while(N > 0){
			int tempNum = 0;
			for(int i = 2;i <= 10;++ i){
				if(check(S,i)){
					tempNum ++;
				}
			}
			if(tempNum >= 2){
						cout << S <<endl;
						S ++;
						N --;
						break;
					}
			if(tempNum<2){
				S ++;
			}
		}
	}
	system("PAUSE");
	return 0;
}