
#include <iostream>
using namespace std;
/*
设有一个带头结点的双向链表h，设计一个算法用于查找第一个元素为x的结点，并将其与其前驱结点进行交换。
要求：
1、定义带头结点的双向链表的型DLIST。
2、定义双向链表DLIST的基本操作。
3、定义函数int swap(elementtype x, DLIST &h)，查找第一个元素之为x的结点，如果在链表中存在元素值为x的结点，并其与其前驱结点进行交换，并返回1，否则返回0。
4、在主函数中测试所编写函数的正确性。
*/

struct node {
	int value;
	node * forePtr;
	node * nextPtr;
	node(int _value) :value(_value), forePtr(nullptr), nextPtr(nullptr) {
	}
};
class DList {
private:
	node * head;
public :
	DList() {
		head = new node(0);
	}
	void add(int _value) {
		node * tempPtr = head;
		node * tempNode = new node(_value);
		while (tempPtr->nextPtr != nullptr) {
			tempPtr = tempPtr->nextPtr;
		}
		tempPtr->nextPtr = tempNode;
		tempNode->forePtr = tempPtr;
		head->value++;
	}

	void show() {
		node * tempPtr = head;
		cout << "Num :" << head->value << endl;;
		while (tempPtr->nextPtr != nullptr) {
			cout << tempPtr->nextPtr->value << endl;
			tempPtr = tempPtr->nextPtr;
		}
	}

	int swap(int _value) {
		node *tempPtr = head->nextPtr;
		while (tempPtr->nextPtr != nullptr) {
			if (tempPtr->value == _value) {
				node * tempNode = tempPtr->forePtr->forePtr;
				tempPtr->forePtr->forePtr->nextPtr = tempPtr;
				tempPtr->forePtr->forePtr = tempPtr;
				tempPtr->forePtr->nextPtr = tempPtr->nextPtr;
				tempPtr->nextPtr->forePtr = tempPtr->forePtr;
				tempPtr->nextPtr = tempPtr->forePtr;
				tempPtr->forePtr = tempNode;
				return 1;
			}
			tempPtr = tempPtr->nextPtr;
		}
		if (tempPtr == nullptr) return 0;
	}
};
int main() {
	DList  newList;
	newList.add(2);
	newList.add(3);
	newList.add(4);
	newList.show();
	newList.swap(3);
	newList.show();
	system("PAUSE");
	return 0;
}