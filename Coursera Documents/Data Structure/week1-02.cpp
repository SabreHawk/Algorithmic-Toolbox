// TestProject.cpp : 定义控制台应用程序的入口点。
//
#include<iostream>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <string>
#include <stack>
#include <vector>
#define MAX 100001
using namespace std;

struct Node {
	int value;
	vector<int> childrenArr;
};
Node nodeArr[MAX];
long long maxDis = 0;
void findLeaf(int _layer, int _children) {
	if (nodeArr[_children].childrenArr.empty()) {
		if (_layer > maxDis) {
			maxDis = _layer;
		}
	}
	else {
		for (int i = 0; i < nodeArr[_children].childrenArr.size(); ++i) {
			findLeaf(_layer + 1, nodeArr[_children].childrenArr[i]);
		}
	}
}
int main()
{
	int nodeNum = 0;
	int rootIndex = 0;
	cin >> nodeNum;
	for (int i = 0; i < nodeNum; ++i) {
		nodeArr[i].value = i;
		int tempFather = 0;
		cin >> tempFather;
		if (tempFather != -1) {
			nodeArr[tempFather].childrenArr.push_back(i);
		}
		else {
			rootIndex = i;
		}

		
	}
	findLeaf(0, rootIndex);
	cout << maxDis + 1 << endl;
    return 0;
}

