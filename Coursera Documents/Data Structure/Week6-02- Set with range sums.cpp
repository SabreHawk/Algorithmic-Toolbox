//#include "stdafx.h"
#include <cstdio>
#include <iostream>
using namespace std;

// Splay tree implementation
// Vertex of a splay tree
struct Vertex {
	long long key;
	// Sum of all the keys in the subtree - remember to update
	// it after each operation that changes the tree.
	long long sum;
	Vertex* left;
	Vertex* right;
	Vertex* parent;

	Vertex(int key, long long sum, Vertex* left, Vertex* right, Vertex* parent)
		: key(key), sum(sum), left(left), right(right), parent(parent) {}
};

void update(Vertex* v) {
	if (v == NULL) return;
	v->sum = v->key + (v->left != NULL ? v->left->sum : 0ll) + (v->right != NULL ? v->right->sum : 0ll);
	if (v->left != NULL) {
		v->left->parent = v;
	}
	if (v->right != NULL) {
		v->right->parent = v;
	}
}

void small_rotation(Vertex* v) {
	Vertex* parent = v->parent;
	if (parent == NULL) {
		return;
	}
	Vertex* grandparent = v->parent->parent;
	if (parent->left == v) {
		Vertex* m = v->right;
		v->right = parent;
		parent->left = m;
	}
	else {
		Vertex* m = v->left;
		v->left = parent;
		parent->right = m;
	}
	update(parent);
	update(v);
	v->parent = grandparent;
	if (grandparent != NULL) {
		if (grandparent->left == parent) {
			grandparent->left = v;
		}
		else {
			grandparent->right = v;
		}
	}
}

void big_rotation(Vertex* v) {
	if (v->parent->left == v && v->parent->parent->left == v->parent) {
		// Zig-zig
		small_rotation(v->parent);
		small_rotation(v);
	}
	else if (v->parent->right == v && v->parent->parent->right == v->parent) {
		// Zig-zig
		small_rotation(v->parent);
		small_rotation(v);
	}
	else {
		// Zig-zag
		small_rotation(v);
		small_rotation(v);
	}
}

// Makes splay of the given vertex and makes
// it the new root.
void splay(Vertex*& root, Vertex* v) {
	if (v == NULL) return;
	while (v->parent != NULL) {
		if (v->parent->parent == NULL) {
			small_rotation(v);
			break;
		}
		big_rotation(v);
	}
	root = v;
}
void traversal(Vertex* Node) {
	if (Node == nullptr) return;
	if (Node->left != nullptr) {
		traversal(Node->left);
	}
	cout <<"T : "<< Node->key << endl;
	if (Node->right != nullptr) {
		traversal(Node->right);
	}
}
// Searches for the given key in the tree with the given root
// and calls splay for the deepest visited node after that.
// If found, returns a pointer to the node with the given key.
// Otherwise, returns a pointer to the node with the smallest
// bigger key (next value in the order).
// If the key is bigger than all keys in the tree, 
// returns NULL.
Vertex* find(Vertex*& root, long long key) {
	Vertex* v = root;
	Vertex* last = root;
	Vertex* next = NULL;
	while (v != NULL) {
		if (v->key >= key && (next == NULL || v->key < next->key)) {
			next = v;
		}
		last = v;
		if (v->key == key) {
			break;
		}
		if (v->key < key) {
			v = v->right;
		}
		else {
			v = v->left;
		}
	}
	splay(root, last);
	return next;
}

void split(Vertex* root, long long key, Vertex*& left, Vertex*& right) {
	right = find(root, key);
	splay(root, right);
	if (right == NULL) {
		left = root;
		return;
	}
	left = right->left;
	right->left = NULL;
	if (left != NULL) {
		left->parent = NULL;
	}
	update(left);
	update(right);
}

Vertex* merge(Vertex* left, Vertex* right) {
	if (left == NULL) return right;
	if (right == NULL) return left;
	Vertex* min_right = right;
	while (min_right->left != NULL) {
		min_right = min_right->left;
	}
	splay(right, min_right);
	right->left = left;
	update(right);
	return right;
}

// Code that uses splay tree to solve the problem

Vertex* root = NULL;

void insert(long long x) {
	//cout << "IN : " << x << endl;
	Vertex* left = NULL;
	Vertex* right = NULL;
	Vertex* new_vertex = NULL;
	split(root, x, left, right);
	if (right == NULL || right->key != x) {
		new_vertex = new Vertex(x, x, NULL, NULL, NULL);
	}
	root = merge(merge(left, new_vertex), right);
}

void erase(long long x) {
	// Implemernt erase yourself
	if (root == NULL) return;
	Vertex * left = NULL;
	Vertex * right = NULL;
	split(root, x, left, right);
	if (right == NULL || right->key != x)
		root = merge(left, right);
	else if (right->key == x) {
		if (right->right == NULL) {
			root = left;
		}
		else {
			right = right->right;
			right->parent = NULL;
			root = merge(left, right);
		}
	}
}

bool find(long long x) {
	// Implement find yourself
	Vertex * tempPtr = find(root, x);
	if (tempPtr == NULL)return false;
	if (tempPtr->key == x) return true;
	return false;
}

long long sum(long long from, long long to) {
	Vertex* left = NULL;
	Vertex* middle = NULL;
	Vertex* right = NULL;
	split(root, from, left, middle);
	split(middle, to + 1, middle, right);
	long long ans = 0;
	// Complete the implementation of sum
	if (middle != NULL) {
		ans = middle->key + (middle->left != NULL ? middle->left->sum : 0ll) + (middle->right != NULL ? middle->right->sum : 0ll);
	}
	root = merge(left, merge(middle, right));
	//cout << "FROM : " << from << " TO : " << to << " ANS : " << ans << endl;
	//traversal(root);
	//cout << root->key << endl;
	//cout << root->left->key << endl;
	return ans;
}

const int MODULO = 1000000001;

int main() {
	int n;
	cin >> n;
	long long last_sum_result = 0;
	for (int i = 0; i < n; i++) {
		char buffer[10];
		cin >> buffer;
		char type = buffer[0];
		switch (type) {
		case '+': {
			int x;
			cin >> x;
			insert((x + last_sum_result) % MODULO);
		} break;
		case '-': {
			int x;
			cin >> x;
			erase((x + last_sum_result) % MODULO);
		} break;
		case '?': {
			int x;
			cin >> x;
			printf(find((x + last_sum_result) % MODULO) ? "Found\n" : "Not found\n");
		} break;
		case 's': {
			int l, r;
			cin >> l >> r;
			//cout << "B: " << l + last_sum_result << endl;
			//cout << "BEFOE : " << (l + last_sum_result) % MODULO << endl;
			long long res = sum((l + last_sum_result) % MODULO, (r + last_sum_result) % MODULO);
			printf("%lld\n", res);
			//traversal(root);
			last_sum_result = (res % MODULO);
			//cout << "LAST : " << last_sum_result << endl;
		}
		}
		//traversal(root);	
	}
	//cout << "END" << endl;
	
//	system("PAUSE");
	return 0;
}
