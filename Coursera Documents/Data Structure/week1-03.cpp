// TestProject.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include<iostream>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <string>
#include <stack>
#include <vector>
#include <deque>
#define MAX 100001
int SIZE = 0;
int NUM = 0;

using namespace std;
int main(){
	int arriveTime = 0;
	int processTime = 0;
	int currentTime = 0;
	int startTimeArr[MAX] = { 0 };
	int currentNum = 0;
	deque<int> packetQueue;
	cin >> SIZE >> NUM;
	for (int i = 0; i < NUM; ++i) {//1 2	01 11 
		cin >> arriveTime >> processTime;
		if (packetQueue.empty()) {
			//cout << "Push into empty deque" << endl;
			packetQueue.push_back(arriveTime + processTime);
			startTimeArr[i] = arriveTime;
		}
		else {
			if (arriveTime >= packetQueue[0]) {
			//	cout << "Arrive : " << arriveTime << " zero Finish : " << packetQueue[0] << endl;
				if (arriveTime >= packetQueue.back()) {
					startTimeArr[i] = arriveTime;
				}
				else {
					startTimeArr[i] = packetQueue.back();
				}
				packetQueue.pop_front();
				packetQueue.push_back(startTimeArr[i] + processTime);
			}
			else {
				if (packetQueue.size() < SIZE) {
			//		cout << "Size before push : " << packetQueue.size() << endl;
					if (arriveTime >= packetQueue.back()) {
						startTimeArr[i] = arriveTime;
					}
					else {
						startTimeArr[i] = packetQueue.back();
					}
					packetQueue.push_back(startTimeArr[i] + processTime);
				}
				else {
			//		cout << "DROP" << endl;
					startTimeArr[i] = -1;
				}
			}
		}
	}
	for (int i = 0; i < NUM; ++i) {
		cout << startTimeArr[i] << endl;
	}
//	system("Pause");
	return 0;
}