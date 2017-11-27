#include <iostream>
#include <stack>
using namespace std;
#define MAX 5
struct node {
	int x;
	int y;
	node() :x(0), y(0){}
	node(int _x, int _y) :x(_x), y(_y){}
};
int testMap[MAX][MAX] = {
	-1,0,1,1,1,
	1,0,0,1,1,
	1,1,0,0,0,
	0,0,0,1,0,
	0,1,0,1,0
};
int xDir[4] = { -1,0,1,0 };
int yDir[4] = { 0,1,0,-1 };

int main() {
	stack<node> myStack;
	node * tempNode = new node(0, 0);
	myStack.push(*tempNode);
	while (!myStack.empty())
	{
		//cout << "Circle" << endl;
		node topNode = myStack.top();
		//cout <<"top "<< topNode.x << " , " << topNode.y << endl;
		bool isBlocked = true;
		for (int i = 0; i < 4; ++i) {
			int tempX = topNode.x + xDir[i];
			int tempY = topNode.y + yDir[i];
			if (tempX >= 0 && tempX < MAX&&tempY >= 0 && tempY < MAX&&testMap[tempX][tempY] == 0) {
				node * tempNew = new node(tempX, tempY);
				myStack.push(*tempNew);
				testMap[tempX][tempY] = 2;
				cout << "--> (" << tempX << " , " << tempY << ")" << endl;
				isBlocked = false;
				break;
				
			}
		}
		if (isBlocked) {
			//cout << "pop "<<myStack.top().x << " ," << myStack.top().y << endl;
			myStack.pop();
		}
	}

	for (int i = 0; i < MAX; ++i) {
		for (int j = 0; j < MAX; ++j) {
			cout << testMap[i][j] << "  ";
		}cout << endl;
	}
	//system("PAUSE");
	return 0;
}
