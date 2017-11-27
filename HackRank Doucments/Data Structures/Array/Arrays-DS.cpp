// TestProject.cpp : 定义控制台应用程序的入口点。
//
#include <iostream>
#include <vector> 

using namespace std;


int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int>::iterator itor;
	int tempValue = 0;
	for (int arr_i = 0; arr_i < n; arr_i++) {
		cin >> arr[arr_i];
	}

	for (int i = n-1 ;i >= 0;-- i){
		cout << arr[i] <<" ";
	}

	return 0;
}

