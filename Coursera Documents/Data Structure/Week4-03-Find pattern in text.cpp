//#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#define P 1000000007
#define X 1
#define MAX 500001
using namespace std;

string strT;
string strP;
long long hashMap[MAX] = { 0 };
vector<long long> resultList;
long long naivePolyHash(string _inStr) {
	long long hIndex = 0;
	for (long long i = _inStr.length(); i >= 0; --i) {
		hIndex = (((hIndex * X + (long long)_inStr[i])%P)+P)%P;
	}
	hIndex %= P;
	return hIndex;
}
void reComputeHash() {
	hashMap[strT.length() - strP.length()] = naivePolyHash(strT.substr(strT.length() - strP.length(), strT.length()));
	long long Y = 1;
	for (long long i = 0; i < strP.length(); ++i) {
		Y = (((Y * X) % P) + P) % P;
	}
	for (long long i = strT.length() - strP.length() - 1; i >= 0; --i) {
		hashMap[i] = (((X*hashMap[i + 1] + strT[i] - Y * strT[i + strP.length()]) % P) + P) % P;
	}
}
bool areEqual(int _startIndex) {
	for (long long i = 0; i < strP.length();++ i) {
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
	for (long long i = 0; i <= strT.length() - strP.length(); ++i) {
		if (pHashIndex != hashMap[i]) {
			continue;
		}
		//cout << i << endl;
		if (areEqual(i)) {
			resultList.push_back(i);
		}
	}
	vector<long long>::iterator itor;
	for (itor = resultList.begin(); itor != resultList.end();++ itor) {
		cout << *itor << " ";
	}cout << endl;
	//system("PAUSE");
	return 0;
}