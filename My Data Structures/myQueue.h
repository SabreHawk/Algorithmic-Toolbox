// Implementation Of Data Structure - Priority Queue With Vector
//
#ifndef MYHEAP
#define MYHEAP

#include <iostream>
#include <vector>
using namespace std;

class myQueue {
private:
	vector<int> PriorityQueue;
	int size;

	void ShiftUp(int _index){
		int tempIndex = _index;
		int tempParentIndex = getParentIndex(tempIndex);
		int tempValueHolder = getValue(tempIndex);
		while ( tempValueHolder > PriorityQueue[tempParentIndex] && tempIndex > 0){
			PriorityQueue[tempIndex] = PriorityQueue[tempParentIndex];
			tempIndex = tempParentIndex;
			tempParentIndex = getParentIndex(tempIndex);
		}
		PriorityQueue[tempIndex] = tempValueHolder;
	}

	void ShiftDown(int _index){
		int tempIndex = _index;
		int tempValueHolder = getValue(tempIndex);
		int targetIndex = (tempIndex + 1) * 2 - 1;
		while (targetIndex < size){
			if (targetIndex + 1 < size && getValue(targetIndex) < getValue(targetIndex+1)){
				targetIndex ++;
			}
			if (getValue(targetIndex) > tempValueHolder){
				PriorityQueue[tempIndex] = PriorityQueue[targetIndex];
				tempIndex = targetIndex;
				targetIndex = (tempIndex + 1) * 2 - 1;
			}else{
				break;
			}
		}
		PriorityQueue[tempIndex] = tempValueHolder;
	}
	void SwapValue(int _indexOne,int _indexTwo){
		int tempValue = getValue(_indexOne);
		PriorityQueue[_indexOne] = PriorityQueue[_indexTwo];
		PriorityQueue[_indexTwo] = tempValue;
	}
public:
	myQueue():size(0){
	}
	int getMax(){
		return size == 0 ? -1 : PriorityQueue[0];
	}
	int getValue(int _index){
		return PriorityQueue[_index];
	}
	int getParentValue(int _index){
		return getValue((_index - 1) / 2);
	}
	int getParentIndex(int _index){
		return (_index + 1) / 2 - 1;
	}
	int getSize(){
		return size;
	}
	void Insert(int _inValue){
		PriorityQueue.push_back(_inValue);
		size ++;
		ShiftUp(size - 1);
	}
	int DeleteTop(){
		int outValue = getMax();		
		PriorityQueue[0] = getValue(--size);
		PriorityQueue.pop_back();
		ShiftDown(0);
		return outValue;
	}
	int PrintQueue(){
		vector<int>::iterator queueItor;
		for (queueItor = PriorityQueue.begin();queueItor != PriorityQueue.end(); queueItor++){
			cout << *queueItor <<" ";
		}cout << "Queue Ends" << endl;
	}

};

#endif