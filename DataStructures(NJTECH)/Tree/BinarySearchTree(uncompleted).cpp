#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;
struct Node
{
	char key;
	long long sum;
	long long height;
	Node* leftPtr;
	Node* rightPtr;
	Node* parentPtr;
	Node(int _key)
		:key(_key), sum(0), height(1), leftPtr(nullptr), rightPtr(nullptr), parentPtr(nullptr) {}
	bool isNum() {
		if (key >= '0'&&key <= '9') {
			return true;
		}
		return false;
	}
};

class myBinaryTree {
private:
	Node* rootPtr;
public:
	myBinaryTree() :rootPtr(nullptr) {}
	myBinaryTree(long long _key) {
		rootPtr = new Node(_key);
	}
	Node* getRoot() {
		return rootPtr;
	}
	long long getHeight(Node * _inNode) {
		if (_inNode != nullptr) {
			return _inNode->height;
		}
		return 0;
	}
	void setHeight(Node * _inNode) {
		long long tempHeight = 1 + max(getHeight(_inNode->leftPtr), getHeight(_inNode->rightPtr));
		if (tempHeight == 0) {
			tempHeight = 1;
		}
		_inNode->height = tempHeight;
	}
	void updateHeight(Node * _inNode) {
		Node * tempPtr = _inNode;
		setHeight(tempPtr);
		while (tempPtr->parentPtr != nullptr&&tempPtr->height == tempPtr->parentPtr->height)
		{
			setHeight(tempPtr->parentPtr);
			tempPtr = tempPtr->parentPtr;
		}
	}
	Node* search(long long _targetValue) {
		Node* tempPtr = rootPtr;
		while (tempPtr != nullptr) {
			if (tempPtr->key == _targetValue) {
				break;
			}
			else if (tempPtr->key < _targetValue) {
				if (tempPtr->rightPtr != nullptr) {
					tempPtr = tempPtr->rightPtr;
				}
				else {
					return tempPtr;
				}
			}
			else if (tempPtr->key > _targetValue) {
				if (tempPtr->leftPtr != nullptr) {
					tempPtr = tempPtr->leftPtr;
				}
				else {
					return tempPtr;
				}
			}
		}
		return tempPtr;
	}
	Node* nextMin(long long _targetValue) {
		Node* tempPtr = search(_targetValue); //cout <<"NextMin: "<< tempPtr->key << endl;
		if (tempPtr->rightPtr == nullptr)
		{
			while (tempPtr->parentPtr != nullptr) {
				tempPtr = tempPtr->parentPtr;
				if (_targetValue < tempPtr->key) {
					break;
				}
			}
			if (tempPtr->parentPtr == nullptr&&tempPtr->key <= _targetValue) {
				return nullptr;
			}
		}
		else {
			tempPtr = tempPtr->rightPtr;
			while (tempPtr->leftPtr != nullptr) {
				tempPtr = tempPtr->leftPtr;
			}
		}

		return tempPtr;
	}
	Node* preMax(long long _targetValue) {
		Node* tempPtr = search(_targetValue);
		if (tempPtr->leftPtr = nullptr) {
			while (tempPtr->parentPtr != nullptr) {
				tempPtr = tempPtr->parentPtr;
				if (_targetValue > tempPtr->key) {
					break;
				}
			}
			if (tempPtr->parentPtr == nullptr) {
				return nullptr;
			}
		}
		else {
			tempPtr = tempPtr->leftPtr;
		}
		while (tempPtr->rightPtr != nullptr) {
			tempPtr = tempPtr->rightPtr;
		}
		return tempPtr;
	}
	long long sumRange(long long _low, long long _high) {
		Node* tempPtr = search(_low); //cout << tempPtr->key << endl;
		long long localSum = 0;
		while (tempPtr != nullptr&&tempPtr->key <= _high) {
			if (tempPtr->key >= _low) {
				localSum += tempPtr->key;
				cout << localSum << endl;
			}
			tempPtr = nextMin(tempPtr->key);
			//cout << tempPtr->key << endl;
		}
		return localSum;
	}
	void insert(int _inValue) {
		Node* tempPtr = search(_inValue);
		Node* tempNode = new Node(_inValue);
		if (_inValue < tempPtr->key) {
			tempPtr->leftPtr = tempNode;
		}
		else if (_inValue>tempPtr->key) {
			tempPtr->rightPtr = tempNode;
		}
		else {
			return;
		}
		tempNode->parentPtr = tempPtr;
		updateHeight(tempPtr);

	}
	bool remove(int _inValue) {
		Node* tempPtr = search(_inValue);
		if (tempPtr->key != _inValue) {
			return false;
		}
		tempPtr->height -= 1;
		if (tempPtr->leftPtr == nullptr&&tempPtr->rightPtr == nullptr) {
			if (tempPtr->parentPtr == nullptr) {
				//if (_inValue == 15) cout << _inValue << "delete root" << endl;
				rootPtr = nullptr;
			}
			else {
				if (tempPtr->key < tempPtr->parentPtr->key) {
					tempPtr->parentPtr->leftPtr = nullptr;
				}
				else {
					tempPtr->parentPtr->rightPtr = nullptr;
				}
				updateHeight(tempPtr->parentPtr);
			}
			delete tempPtr;
		}
		else if (tempPtr->leftPtr == nullptr&&tempPtr->rightPtr != nullptr) {
			tempPtr->rightPtr->parentPtr = tempPtr->parentPtr;
			if (tempPtr->parentPtr == nullptr) {
				rootPtr = tempPtr->rightPtr;
			}
			else {
				if (tempPtr->key<tempPtr->parentPtr->key) {
					tempPtr->parentPtr->leftPtr = tempPtr->rightPtr;
				}
				else {
					tempPtr->rightPtr = tempPtr->leftPtr;
				}
				updateHeight(tempPtr->parentPtr);
			}
			delete tempPtr;
		}
		else if (tempPtr->rightPtr == nullptr&&tempPtr->leftPtr != nullptr) {
			tempPtr->leftPtr->parentPtr = tempPtr->parentPtr;
			if (tempPtr->parentPtr == nullptr) {
				rootPtr = tempPtr->leftPtr;
			}
			else {
				if (tempPtr->key <tempPtr->parentPtr->key) {
					tempPtr->parentPtr->leftPtr = tempPtr->leftPtr;
				}
				else {
					tempPtr->parentPtr->rightPtr = tempPtr->rightPtr;
				}
				updateHeight(tempPtr->parentPtr);
			}
			delete tempPtr;
		}
		else {
			Node* nextNode = nextMin(tempPtr->key);
			long long tempValue = nextNode->key;
			remove(tempValue);
			tempPtr->key = tempValue;
		}
		return true;
	}
	void inOrderTraversal(Node* _node) {
		if (_node == nullptr) {
			return;
		}
		if (_node->leftPtr != nullptr) {
			inOrderTraversal(_node->leftPtr);
		}
		cout << _node->key << " ";
		if (_node->rightPtr != nullptr) {
			inOrderTraversal(_node->rightPtr);
		}
	}
	void rotateSL(Node * _inNode) {
		Node * tempPreRoot = _inNode;
		Node * tempLatRoot = _inNode->leftPtr;
		//	cout << tempPreRoot->key << endl;
		//	cout << tempLatRoot->key << endl;
		if (tempLatRoot->rightPtr != nullptr) {
			tempLatRoot->rightPtr->parentPtr = tempPreRoot;
			tempPreRoot->leftPtr = tempLatRoot->rightPtr;
		}
		else {
			tempPreRoot->leftPtr = nullptr;
		}
		if (tempPreRoot->parentPtr != nullptr) {
			tempLatRoot->parentPtr = tempPreRoot->parentPtr;
			if (tempPreRoot->parentPtr->key > tempLatRoot->key) {
				tempPreRoot->rightPtr = tempLatRoot;
			}
			else {
				tempPreRoot->leftPtr = tempLatRoot;
			}
		}
		else {
			rootPtr = tempLatRoot;
		}
		tempPreRoot->parentPtr = tempLatRoot;
		tempLatRoot->rightPtr = tempPreRoot;
		updateHeight(tempPreRoot);
		updateHeight(tempLatRoot);
	}
	void rotateSR(Node * _inNode) {
		Node * tempPreRoot = _inNode;
		Node * tempLatRoot = _inNode->rightPtr;
		if (tempLatRoot->leftPtr != nullptr) {
			tempLatRoot->leftPtr->parentPtr = tempPreRoot;
			tempPreRoot->rightPtr = tempLatRoot->leftPtr;
		}
		else {
			tempPreRoot->rightPtr = nullptr;
		}
		if (tempPreRoot->parentPtr != nullptr) {
			tempLatRoot->parentPtr = tempPreRoot->parentPtr;
			if (tempPreRoot->parentPtr->key > tempLatRoot->key) {
				tempPreRoot->parentPtr->rightPtr = tempLatRoot;
			}
			else {
				tempPreRoot->parentPtr->leftPtr = tempLatRoot;
			}
		}
		else {
			rootPtr = tempLatRoot;
		}
		tempPreRoot->parentPtr = tempLatRoot;
		tempLatRoot->leftPtr = tempPreRoot;
		updateHeight(tempPreRoot);
		updateHeight(_inNode);
	}
	void rotateLR(Node * _inNode) {
		rotateSR(_inNode->leftPtr);
		rotateSL(_inNode);
	}
	void rotateRL(Node * _inNode) {
		rotateSL(_inNode->rightPtr);
		rotateSR(_inNode);
	}
	void MidOrderTraversal(Node *nodePtr) {
	//	cout << "." << endl;
		if (nodePtr == nullptr) {
			cout << "NULL" << endl;
			return;
		}
		if (nodePtr->leftPtr != nullptr) {
			MidOrderTraversal(nodePtr->leftPtr);
		}		
		cout << nodePtr->key << " ";
		if (nodePtr->rightPtr != nullptr) {
			MidOrderTraversal(nodePtr->rightPtr);
		}
		
	}
	void CreateTree(string _expression) {
		Node * tempNode = nullptr;
		Node * tempRoot = rootPtr;
		bool isK = false;
		int lengthCounter = 0;
	//	cout << "LENGTH :" << _expression.length() << endl;
		while (lengthCounter<_expression.length()) {
		//	cout << "TRAVERSAL :"; MidOrderTraversal(getRoot());
			tempNode = new Node(_expression[lengthCounter]);
		//	cout << tempNode->key << endl;
			if (rootPtr == nullptr) {
				rootPtr = tempNode;
			}
			else if (rootPtr->isNum() == true) {
				rootPtr->parentPtr = tempNode;
				tempNode->leftPtr = rootPtr;
				rootPtr = tempNode;
			}
			else if (tempNode->isNum()) {
				Node * tNode = rootPtr;
				while (tNode->rightPtr != nullptr) {
					tNode = tNode->rightPtr;
				//	cout << "Node" << tempNode->key << endl;
				}
				tNode->rightPtr = tempNode;
				tempNode->parentPtr = tNode;
				//cout << "NUM " << tempNode->key << endl;
			}
			else if (!tempNode->isNum()) {
				if (tempNode->key == '*' || tempNode->key == '/') {
					tempNode->parentPtr = tempRoot;
					tempNode->leftPtr = tempRoot->rightPtr;
					tempNode->leftPtr->parentPtr = tempNode;
					tempRoot->rightPtr = tempNode;
				}
				else if(tempNode->key == '+' ||tempNode->key == '*'){
					tempNode->leftPtr = tempRoot;
					tempRoot->parentPtr = tempNode;
					tempRoot = tempNode;
				}
				else if (tempNode->key == '(') {
					isK = true;
				}
				else if (tempNode->key == ')') {
					isK = false;
				}
			}
			
			lengthCounter++;
		//	cout << "L" << lengthCounter << endl;
		}
	//	cout << "EXIT" << endl;
	}
	double computeTree(Node * nodePtr) {
		if (nodePtr->isNum()) {
			return double(nodePtr->key - '0');
		}
		else {
			switch (nodePtr->key)
			{
			case '+':
				return computeTree(nodePtr->leftPtr) + computeTree(nodePtr->rightPtr);
				break;
			case '-':
				return computeTree(nodePtr->leftPtr) - computeTree(nodePtr->rightPtr);
				break;
			case '*':
				return computeTree(nodePtr->leftPtr) * computeTree(nodePtr->rightPtr);
				break;
			case '/':
				return computeTree(nodePtr->leftPtr) / computeTree(nodePtr->rightPtr);
				break;
			default:
				break;
			}
		}
	}
};

int main() {
	myBinaryTree computerTree;
	//computerTree.MidOrderTraversal(computerTree.getRoot());
	computerTree.CreateTree("5+6*7-3+2/3");
	computerTree.MidOrderTraversal(computerTree.getRoot());
	cout << "= ";
	cout << computerTree.computeTree(computerTree.getRoot()) << endl;
	cout << "END" << endl;
	system("PAUSE");
	/*cout << "START" << endl;
	myBinaryTree testTree(20);
	testTree.insert(9);
	testTree.insert(10);
	cout << "ROOT: " << testTree.getHeight(testTree.search(20)) << endl;
	cout << "ROOT: " << testTree.getHeight(testTree.search(9)) << endl;
	cout << "ROOT: " << testTree.getHeight(testTree.search(10)) << endl;
	cout << "ROOT: " << testTree.getRoot()->key << endl;
	cout << testTree.getRoot()->leftPtr->key << endl;
	cout << testTree.getRoot()->rightPtr->key << endl;
	testTree.inOrderTraversal(testTree.getRoot()); cout << endl;
	cout << testTree.getHeight(testTree.search(20)) << endl;
	cout << testTree.getHeight(testTree.search(9)) << endl;
	cout << testTree.getHeight(testTree.search(17)) << endl;
	testTree.insert(9);
	testTree.inOrderTraversal(testTree.getRoot()); cout << endl;
	testTree.insert(3);
	testTree.inOrderTraversal(testTree.getRoot()); cout << endl;
	testTree.insert(4);
	testTree.inOrderTraversal(testTree.getRoot()); cout << endl;
	cout << "HEIGHT : " << testTree.getHeight(testTree.search(11)) << endl;
	cout << "HEIGHT : " << testTree.getHeight(testTree.search(15)) << endl;
	cout << "HEIGHT : " << testTree.getHeight(testTree.search(8)) << endl;
	cout << "HEIGHT : " << testTree.getHeight(testTree.search(9)) << endl;
	cout << "HEIGHT : " << testTree.getHeight(testTree.search(3)) << endl;
	cout << "HEIGHT : " << testTree.getHeight(testTree.search(4)) << endl;
	testTree.remove(4);
	testTree.remove(8);
	testTree.inOrderTraversal(testTree.getRoot()); cout << endl;
	testTree.remove(11);
	testTree.inOrderTraversal(testTree.getRoot()); cout << endl;
	testTree.remove(11);
	testTree.inOrderTraversal(testTree.getRoot()); cout << endl;
	cout << "ROOT:" << testTree.getRoot()->key << endl;
	cout << "HEIGHT : " << testTree.getHeight(testTree.getRoot()) << endl;
	cout << "HEIGHT : " << testTree.getHeight(testTree.search(9)) << endl;
	cout << "HEIGHT : " << testTree.getHeight(testTree.search(3)) << endl;
	testTree.remove(9);
	testTree.inOrderTraversal(testTree.getRoot()); cout << endl;
	testTree.remove(3);
	testTree.inOrderTraversal(testTree.getRoot()); cout << endl;
	testTree.remove(12);
	testTree.inOrderTraversal(testTree.getRoot()); cout << endl;
	cout << "ROOT:" << testTree.getRoot()->key << endl;
	cout << "HEIGHT : " << testTree.getHeight(testTree.search(15)) << endl;
	testTree.remove(15);
	//cout << testTree.getRoot()->key << endl;
	cout << "BEFORE" << endl;
	testTree.inOrderTraversal(testTree.getRoot()); cout << endl;
	cout << "AFTER" << endl;
	cout << (testTree.getRoot() == nullptr) << endl;
	//	cout << testTree.remove(100) << endl;;
	//cout << testTree.nextMin(9)->key << endl;
	//cout << testTree.sumRange(3, 15) << endl;
	//testTree.search(12);
	//testTree.search(1);
	system("pause");
	*/
	return 0;
}
