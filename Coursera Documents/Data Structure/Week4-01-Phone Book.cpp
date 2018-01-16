//#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS 
#define MAX 100000
#define P 100027
#define A  18
#define B 7
#define M 1000
using namespace std;
unordered_map<int, string> phoneBook;
int N = 0;
int main() {
	cin >> N;
	int number = 0;
	string name = "";
	string type = "";
	for (int i = 0; i < N; ++i) {
		cin >> type;
		if (type == "add") {
			cin >> number >> name;
			phoneBook[number] = name;
		}
		else if (type == "find") {
				cin >> number;
				if (phoneBook.find(number) != phoneBook.end()) {
					cout << phoneBook[number] << endl;
				}
				else {
					cout << "not found" << endl;
				}
		}
		else if (type == "del") {
			cin >> number;
			if (phoneBook.find(number) != phoneBook.end()) {
				phoneBook.erase(number);
			}
		}
	}
	//system("Pause");
	return 0;
}