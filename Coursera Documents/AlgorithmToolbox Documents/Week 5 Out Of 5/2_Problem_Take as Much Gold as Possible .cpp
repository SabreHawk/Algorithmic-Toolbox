#include <iostream>
#include <algorithm>
#define MAX 301
#define NUM 301
#define WEIGHT 10001
using namespace std;
int W = 0;
int N = 0;
int Sum = 0;
int weightArr[MAX] = { 0 };
int valueMap[NUM][WEIGHT] = { 0 };
bool compare(int _num1, int _num2) {
	return _num1 > _num2;
}
int main() {
	cin >> W >> N;
	for (int i = 0; i < N;++i) {
		cin >> weightArr[i];
	}
	for (int i = 1;i <= N;++i) {
		for (int j = 1;j <= W;++j) {
			valueMap[i][j] = valueMap[i-1][j];
			int tempValue = 0;
			if (weightArr[i-1] <= j ){
				tempValue = valueMap[i - 1][j - weightArr[i-1]] + weightArr[i-1];
				if (tempValue > valueMap[i][j]) {
					valueMap[i][j] = tempValue;
				}
			}
		}
	}
	cout << valueMap[N][W] << endl;

	return 0;
}
