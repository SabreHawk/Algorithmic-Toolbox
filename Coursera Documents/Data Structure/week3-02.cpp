
#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
#include <vector>
using namespace std;

#define MAX 100001

struct node {
	int index;
	long long proTime;
};
struct smaller
{
	 bool operator()(node n1,node n2)
	{
		 if (n1.proTime != n2.proTime)
			 return n1.proTime > n2.proTime;
		 else
			 return n1.index > n2.index;
	}
};
int n = 0;
int m = 0;
priority_queue<node, vector<node>, smaller> threadArr;
int main() {
	node tempNode;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> tempNode.proTime;
		if (i<n) {
			tempNode.index = i;
			threadArr.push(tempNode);
			cout << i << " " << 0 << endl;
		}
		else {
			tempNode.index = threadArr.top().index;
			tempNode.proTime += threadArr.top().proTime;
			cout << tempNode.index << " " << threadArr.top().proTime << endl;
			threadArr.pop();
			threadArr.push(tempNode);
			
		}
	}
	return 0;
}