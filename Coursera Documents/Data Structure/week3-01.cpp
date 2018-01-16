#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100001

struct node {
	int preIndex;
	int aftIndex;
};
int n = 0;
int numArr[MAX] = { 0 };
node nodeArr[MAX];
int swapNum = 0;

void mySwap(int _leftIndex, int _rightIndex) {
	int temp = numArr[_leftIndex];
	numArr[_leftIndex] = numArr[_rightIndex];
	numArr[_rightIndex] = temp;
}
void heapify(int _index) {
	int leftIndex = (_index + 1) * 2 - 1;
	int rightIndex = (_index + 1) * 2;	
	int swapIndex = _index;
	if (leftIndex < n&&numArr[leftIndex] < numArr[swapIndex]) {
		swapIndex = leftIndex;
	}
	if (rightIndex < n&&numArr[rightIndex] < numArr[swapIndex]) {
		swapIndex = rightIndex;
	}
	if (swapIndex != _index) {
		mySwap(swapIndex, _index);
		nodeArr[swapNum].preIndex = _index;
		nodeArr[swapNum++].aftIndex = swapIndex;
		heapify(swapIndex);
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> numArr[i];
	}
	for (int i = n / 2 - 1; i >= 0; --i) {
		heapify(i);
	}
	cout << swapNum << endl;
	for (int i = 0; i < swapNum; ++i) {
		cout << nodeArr[i].preIndex << " " << nodeArr[i].aftIndex << endl;
	}
	return 0;
}