//#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#define P 100000007
#define X 17
#define MAX 500001
using namespace std;

string strT;
string strP;
long long hashMap[MAX] = { 0 };
vector<int> resultList;
long long naivePolyHash(string &_inStr) {
	long long hIndex = 0;
	for (int i = _inStr.length(); i >= 0; --i) {
		hIndex = (((hIndex * X + (long long)_inStr[i])%P)+P)%P;
	}
	return hIndex;
}
void reComputeHash() {
	hashMap[strT.length() - strP.length()] = naivePolyHash(strT.substr(strT.length() - strP.length(), strT.length() - 1));
	long long Y = 1;
	for (int i = 0; i < strP.length(); ++i) {
		Y = (((Y * X) % P) + P) % P;
	}
	for (int i = strT.length() - strP.length() - 1; i >= 0; --i) {
		hashMap[i] = (X*hashMap[i + 1] + strT[i] - Y * strT[i + strP.length()]) % P;
	}
}
bool areEqual(int _startIndex) {
	for (int i = 0; i < strP.length();++ i) {
		if (strP[i] != strT[_startIndex + i]) {
			return false;
		}
	}
	return true;
}
int main() {
	//cout << "G" << endl;
	cin >> strP >> strT;
	//cout << "G" << endl;
	long long pHashIndex = naivePolyHash(strP);
	reComputeHash();
	
	for (int i = 0; i <= strT.length() - strP.length(); ++i) {
		if (pHashIndex != hashMap[i]) {
			continue;
		}
		//cout << i << endl;
		if (areEqual(i)) {
			resultList.push_back(i);
		}
	}
	vector<int>::iterator itor;
	for (itor = resultList.begin(); itor != resultList.end();++ itor) {
		cout << *itor << " ";
	}cout << endl;
	//system("PAUSE");
	return 0;
}