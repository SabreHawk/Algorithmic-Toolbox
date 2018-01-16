//#include "stdafx.h"
#include <iostream>
#define MAX 100000
using namespace std;
struct node {
	int value;
	int leftIndex;
	int rightIndex;
};
void inorderTraversal(int);
void preorderTraversal(int);
void postorderTraversal(int);
int N = 0;
node nodeArr[MAX];
int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> nodeArr[i].value >> nodeArr[i].leftIndex >> nodeArr[i].rightIndex;
	}
	inorderTraversal(0); cout << endl;
	preorderTraversal(0); cout << endl;
	postorderTraversal(0); cout << endl;
	//system("Pause");
	return 0;
}

void inorderTraversal(int _index) {
	if (nodeArr[_index].leftIndex != -1) {
		inorderTraversal(nodeArr[_index].leftIndex);
	}
	cout << nodeArr[_index].value<<" ";
	if (nodeArr[_index].rightIndex != -1) {
		inorderTraversal(nodeArr[_index].rightIndex);
	}
	
}
void preorderTraversal(int _index) {
	cout << nodeArr[_index].value << " ";
	if (nodeArr[_index].leftIndex != -1) {
		preorderTraversal(nodeArr[_index].leftIndex);
	}
	if (nodeArr[_index].rightIndex != -1) {
		preorderTraversal(nodeArr[_index].rightIndex);
	}
}
void postorderTraversal(int _index) {
	if (nodeArr[_index].leftIndex != -1) {
		postorderTraversal(nodeArr[_index].leftIndex);
	}
	if (nodeArr[_index].rightIndex != -1) {
		postorderTraversal(nodeArr[_index].rightIndex);
	}
	cout << nodeArr[_index].value << " ";
}