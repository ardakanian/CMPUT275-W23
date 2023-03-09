#include <iostream>
#include <utility>
#include "heap.h"

using namespace std;

int main() {
	// Declare a min heap holding string items and integer keys
	BinaryHeap<string, int> minheap;

	minheap.insert("mouse", 5);
	cout << "the root node is " << minheap.min().item << endl;
	minheap.insert("cat", 3);
	cout << "the root node is " << minheap.min().item << endl;
	minheap.insert("bear", 4);
	cout << "the root node is " << minheap.min().item << endl;
	minheap.insert("bird", 4);
	cout << "the root node is " << minheap.min().item << endl;
	minheap.insert("ant", 3);
	cout << "the root node is " << minheap.min().item << endl;
	minheap.insert("elephant", 8);
	cout << "the root node is " << minheap.min().item << endl;
	minheap.popMin();
	cout << "the root node is " << minheap.min().item << endl;
	minheap.popMin();
	cout << "the root node is " << minheap.min().item << endl;
	minheap.popMin();
	cout << "the root node is " << minheap.min().item << endl;
	minheap.insert("cow", 3);
	cout << "the root node is " << minheap.min().item << endl;

	cout << minheap.size() << " elements are stored in the heap" << endl;

	// Declare another min heap holding items that are pair<int, int>
	BinaryHeap<pair<int, int>, int> minheap2;

	minheap2.insert(pair<int, int>(3, 4), 10);
	cout << "the root node is " << minheap2.min().item.first << ", " << minheap2.min().item.second << endl;
	minheap2.insert(pair<int, int>(3, 2), 5);
	cout << "the root node is " << minheap2.min().item.first << ", " << minheap2.min().item.second << endl;
	minheap2.insert(pair<int, int>(1, 2), 7);
	cout << "the root node is " << minheap2.min().item.first << ", " << minheap2.min().item.second << endl;
	minheap2.insert(pair<int, int>(2, 3), 1);
	cout << "the root node is " << minheap2.min().item.first << ", " << minheap2.min().item.second << endl;

	while (minheap2.size()>0) {
		cout << minheap2.min().key << endl;
		minheap2.popMin();
	}
	return 0;
}
