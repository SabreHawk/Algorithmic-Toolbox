#include <iostream>
#include <string>
#include <algorithm>

//8
//1 10 99 23 8 1 9 8 3
#define MAX 10000
using namespace std;

int N = 0;
string strArr[MAX];

bool compare(string _str1,string _str2){
    bool leftStr = true;
    int minLength = 0;
    if(_str1.length() < _str2.length()){
        minLength = _str1.length();
    }else{
        minLength = _str2.length();
        leftStr = false;
    }
    for(int i = 0 ;i < minLength;++ i){
        if(_str1[i] != _str2[i]){
           return  _str1[i] > _str2[i];
        }
    }
    if(leftStr){
       	// cout << _str1 << " " <<_str2 << endl;
        for(int i = _str1.length();i < _str2.length();++ i){
            if(_str2[i] != _str1[0]){
      	//cout << _str2[i] << " " <<_str1[0] << endl;
            	return _str2[i] < _str1[0];
       		}
        }
        if(_str2[_str2.length()-1] >= _str2[_str2.length()-2])
        	return _str1.length() > _str2.length();
        else{
        	return _str1.length() < _str2.length();
		}
    }else{
        for(int i = _str2.length();i < _str1.length();++ i){
            if(_str1[i] != _str2[0]){
                return _str1[i] > _str2[0];
            }
        }
        if(_str1[_str1.length()-1] >= _str1[_str1.length()-2])
        	return _str1.length() > _str2.length();
        else
        	return _str1.length() < _str2.length();
    }
}
int main(){
    cin >> N;
    for(int i = 0;i < N; ++ i){
        cin >> strArr[i];
    }
    sort(strArr,strArr + N,compare);
    string answer;
    for(int i = 0;i < N;++ i){
        answer += strArr[i];
    }
    cout << answer <<endl;
    system("PAUSE");
    return 0;
}