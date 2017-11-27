#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
struct node {
	int x;
	int y;
	int value;
	node(int _x, int _y, int _value) :x(_x), y(_y),value(_value) {
	}
};

vector<node> matrix;

int calDiagonal() {
	vector<node>::iterator itor;
	int tempSum = 0;
	for (itor = matrix.begin(); itor != matrix.end(); itor++) {
		if (itor->x == itor->y) {
			tempSum += itor->value;
			cout << itor->x << " " << itor->y << " " <<itor->value<<endl;
		}
	}
	return tempSum;
}

int main() {
	matrix.push_back(*(new node(1, 1, 50)));
	matrix.push_back(*(new node(2, 1, 10)));
	matrix.push_back(*(new node(2, 3, 20)));
	matrix.push_back(*(new node(4, 1, -30)));
	matrix.push_back(*(new node(4, 3, -60)));
	matrix.push_back(*(new node(4, 4, 5)));
	cout << calDiagonal() << endl;
	system("Pause");
	return 0;
}