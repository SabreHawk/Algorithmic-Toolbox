#include <iostream>
#include <string>
#include <string>
#define MAX 101
using namespace std;

string strOne;
string strTwo;
int numTable[MAX][MAX] = { 0 };
int minStep(int _num1, int _num2, int _num3) {
	_num1 = _num1 < _num2 ? _num1 : _num2;
	_num1 = _num1 < _num3 ? _num1 : _num3;
	return _num1;
}
int main() {
	cin >> strOne >> strTwo;
	int LENGTHONE = strOne.length();
	int LENGTHTWO = strTwo.length();
	
	for (int i = 0;i <= LENGTHTWO;++i) {
		numTable[0][i] = i;
	}
	for (int i = 0;i <= LENGTHONE;++i) {
		numTable[i][0] = i;
	}
	for (int i = 0;i < LENGTHONE;++i) {
		for (int j = 0;j < LENGTHTWO;++j) {
		//	cout << i <<" " << j << endl;
			int insertNum = numTable[i+1][j] + 1;
			int deleteNum = numTable[i][j+1] + 1;
			int dismatchNum = numTable[i][j] + 1;
			int matchNum = numTable[i][j];
			if (strOne[i] == strTwo[j]) {
				numTable[i+1][j+1] = minStep(insertNum, deleteNum, matchNum);
			}
			else {
				numTable[i+1][j+1] = minStep(insertNum, deleteNum, dismatchNum);
			}
		}
	}
	cout << numTable[LENGTHONE][LENGTHTWO] << endl;
	return 0; 
}
