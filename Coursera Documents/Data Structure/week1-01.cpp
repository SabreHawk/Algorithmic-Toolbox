// TestProject.cpp : 定义控制台应用程序的入口点。
//

#include<iostream>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <string>
#include <stack>
#define MAX 100001
using namespace std;

int main()
{
	string initialStr;
	stack<char> charStack;
	stack<int> indexStack;
	bool flag = false;
	cin >> initialStr;
	int LENGTH = initialStr.length();
	for (int i = 0; i < initialStr.length(); ++i) {
		if (initialStr[i] == '(' || initialStr[i] == '[' || initialStr[i] == '{') {
			charStack.push(initialStr[i]);
			indexStack.push(i+1);
		}
		else if (initialStr[i] == ')' || initialStr[i] == ']' || initialStr[i] == '}') {
			switch (initialStr[i])
			{
			case ')':
				if (!charStack.empty()&&charStack.top() == '(') {
					charStack.pop();
					indexStack.pop();
				}
				else {
					charStack.push(')');
					indexStack.push(i+1);
					flag = true;
				}
				break;
			case ']':
				if (!charStack.empty() && charStack.top() == '[') {
					charStack.pop();
					indexStack.pop();
				}
				else {
					charStack.push(']');
					indexStack.push(i+1);
					flag = true;
				}
			
				break;
			case '}':
				if (!charStack.empty() && charStack.top() == '{') {
					charStack.pop();
					indexStack.pop();
				}
				else {
					charStack.push('}');
					indexStack.push(i+1);
					flag = true;
				}
				break;
			}
		}
		if (flag) break;
	}
	if (charStack.empty()) {
		cout << "Success";
	}
	else {
		cout << indexStack.top();
	}
    return 0;
}

