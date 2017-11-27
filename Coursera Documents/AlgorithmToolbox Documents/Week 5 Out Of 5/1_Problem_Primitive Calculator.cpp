// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//


#include <iostream>
#define MAX 1000001
using namespace std;

int targetNum = 0;
int procedureArr[MAX] = { 0 };

int main()
{
	procedureArr[1] = 0;
	cin >> targetNum;
	for (int i = 2;i <= targetNum;++i) {
		int minNum = procedureArr[i - 1] + 1;
		int tempNum2 = 10000000;
		int tempNum3 = 10000000;
		if (i % 3 == 0) {
			tempNum3 = procedureArr[i / 3] + 1;
		}		
		minNum = tempNum3 < minNum ? tempNum3 : minNum;
		if (i % 2 == 0) {
			tempNum2 = procedureArr[i / 2] + 1;
		}
		minNum = tempNum2 < minNum ? tempNum2 :minNum;
		procedureArr[i] = minNum;
  	}
	int step = 0;
	cout << procedureArr[targetNum] << endl;
	for (int i = 1;i <= targetNum;++i) {
		if (procedureArr[i] == step) {
			cout << i << ' ';
			++step;
		}
	}
    return 0;
}


