#include <iostream>
#include <string>
#define MAX 40 
using namespace std;

string inputExpression;
int numArr[MAX] = { 0 };
char operationArr[MAX];
long long minMap[MAX][MAX] = { 0 };
long long maxMap[MAX][MAX] = { 0 };
void minAndmax(int _start, int _end);
long long minCalculate(long long  _num1, long long  _num2, long long  _num3, long long  _num4,long long _num5) {
	_num1 = _num1 < _num2 ? _num1 : _num2;
	_num1 = _num1 < _num3 ? _num1 : _num3;
	_num1 = _num1 < _num4 ? _num1 : _num4;
	_num1 = _num1 < _num5 ? _num1 : _num5;
	return _num1;
}
long long maxCalculate(long long _num1, long long _num2, long long _num3, long long _num4,long long _num5) {
	_num1 = _num1 > _num2 ? _num1 : _num2;
	_num1 = _num1 > _num3 ? _num1 : _num3;
	_num1 = _num1 > _num4 ? _num1 : _num4;
	_num1 = _num1 > _num5 ? _num1 : _num5;
	return _num1;
}
int main() {
	cin >> inputExpression;

	int operationNum = (inputExpression.length() + 1) / 2 - 1;
	for (int i = 0;i < inputExpression.length();++i) {
		if (i % 2 == 0) {
			numArr[i / 2] = inputExpression[i]-'0';
		}
		else {
			operationArr[i / 2] = inputExpression[i];
		}
	}
	for (int i = 0;i <= operationNum;++i) {
		minMap[i][i] = (long long)numArr[i];
		maxMap[i][i] = (long long)numArr[i];
	}
	for (int i = 1;i <= operationNum;++i) {
		for (int x = 0;x <= operationNum - i;++x) {
			int y = x + i;
			minAndmax(x, y);
		}
	}

	cout << maxMap[0][operationNum] << endl;
	return 0;
}

void minAndmax(int _start, int _end) {
	long long  tempMin =  9999999999999999;
	long long  tempMax = -9999999999999999;
	//cout << tempMin<<endl;
	//cout << tempMax << endl;
	for (int i = _start;i < _end;++i) {
		long long  tempAns01 = 0;
		long long  tempAns02 = 0;
		long long  tempAns03 = 0;
		long long  tempAns04 = 0;
		switch (operationArr[i])
		{
		case '+':
			tempAns01 = (long long)maxMap[_start][i] + maxMap[i + 1][_end];
			tempAns02 = (long long)minMap[_start][i] + minMap[i + 1][_end];
			tempAns03 = (long long)minMap[_start][i] + maxMap[i + 1][_end];
			tempAns04 = (long long)maxMap[_start][i] + minMap[i + 1][_end];
			break;
		case '-':
			tempAns01 = (long long)maxMap[_start][i] - maxMap[i + 1][_end];
			tempAns02 = (long long)minMap[_start][i] - minMap[i + 1][_end];
			tempAns03 = (long long)minMap[_start][i] - maxMap[i + 1][_end];
			tempAns04 = (long long)maxMap[_start][i] - minMap[i + 1][_end];
			break;
		case '*':
			tempAns01 = (long long)maxMap[_start][i] * maxMap[i + 1][_end];
			tempAns02 = (long long)minMap[_start][i] * minMap[i + 1][_end];
			tempAns03 = (long long)minMap[_start][i] * maxMap[i + 1][_end];
			tempAns04 = (long long)maxMap[_start][i] * minMap[i + 1][_end];
			break;
		default:
			break;
		}
		tempMin = minCalculate(tempMin,tempAns01, tempAns02, tempAns03, tempAns04);
		tempMax = maxCalculate(tempMax,tempAns01, tempAns02, tempAns03, tempAns04);
	}
	minMap[_start][_end] = (long long)tempMin;
	maxMap[_start][_end] = (long long)tempMax;
}
