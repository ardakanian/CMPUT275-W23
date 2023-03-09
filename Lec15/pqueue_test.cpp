#include <iostream>
#include <utility>		// std::pair
#include <queue>		// std::priority_queue
#include <vector>		// std::vector
#include <functional>	// std::greater & std::less

using namespace std;

// Create a new type name for pair<string, int> 
typedef pair<string, int> PSI;

// Objects of this class are called "function objects" 
// because the function call operator is defined for them
class ComparableGreater {
public:
	// Define the function call operator: operator()
	bool operator() (const PSI& lhs, const PSI& rhs) const {
		return (lhs.second > rhs.second); // used in min heap
	}
};

// Objects of this class are called "function objects" 
// because the function call operator is defined for them
class ComparableLess {
public:
	bool operator() (const PSI& lhs, const PSI& rhs) const {
		return (lhs.second < rhs.second); // used in max heap
	}
};

int main() {
	// The second parameter passed to the constructor 
	// is a container for storinig elements in priority_queue.
	// Passing std::greater<T> as the third template parameter will
	// cause the smallest item to appear as the top()
	// std::greater<T> is a 'function object' for performing comparisons.
	priority_queue<int, std::vector<int>, std::greater<int>> minheap;
	
	minheap.push(70);
	minheap.push(30);
	minheap.push(20);
	minheap.push(50);
	minheap.push(40);

	// Print items in sorted order (from smallest to largeest)
	while (!minheap.empty()) {
		cout << minheap.top() << endl;
		minheap.pop();
	}

	// std:greater<Pair<F,S>> compares first and second elements
	// of two pairs lexicographically by operator<
	// i.e. it compares the first elements and only if they are 
	// equivalent, it compares the second elements
	priority_queue<PSI, std::vector<PSI>, greater<PSI>> minheap2;

	minheap2.push(PSI("mouse", 5));
	cout << "the root node is " << minheap2.top().first << endl;
	minheap2.push(PSI("cat", 3));
	cout << "the root node is " << minheap2.top().first << endl;
	minheap2.push(PSI("bear", 4));
	cout << "the root node is " << minheap2.top().first << endl;
	minheap2.push(PSI("bird", 4));
	cout << "the root node is " << minheap2.top().first << endl;
	minheap2.push(PSI("ant", 3));
	cout << "the root node is " << minheap2.top().first << endl;
	minheap2.push(PSI("elephant", 8));
	cout << "the root node is " << minheap2.top().first << endl;
	minheap2.pop();
	cout << "the root node is " << minheap2.top().first << endl;
	minheap2.pop();
	cout << "the root node is " << minheap2.top().first << endl;
	minheap2.pop();
	cout << "the root node is " << minheap2.top().first << endl;
	minheap2.push(PSI("cow", 3));
	cout << "the root node is " << minheap2.top().first << endl;

	cout << minheap2.size() << " elements are in the heap" << endl;

	// Only care about the second element when comparing two pairs?
	// ComparableGreater (or ComparableLess) is a function object
	priority_queue<PSI, std::vector<PSI>, ComparableGreater> heap;
	// priority_queue<PSI, std::vector<PSI>, ComparableLess> heap;

	heap.push(PSI("mouse", 5));
	cout << "the root node is " << heap.top().first << endl;
	heap.push(PSI("cat", 3));
	cout << "the root node is " << heap.top().first << endl;
	heap.push(PSI("bear", 4));
	cout << "the root node is " << heap.top().first << endl;
	heap.push(PSI("bird", 4));
	cout << "the root node is " << heap.top().first << endl;
	heap.push(PSI("ant", 3));
	cout << "the root node is " << heap.top().first << endl;
	heap.push(PSI("elephant", 8));
	cout << "the root node is " << heap.top().first << endl;
	heap.pop();
	cout << "the root node is " << heap.top().first << endl;
	heap.pop();
	cout << "the root node is " << heap.top().first << endl;
	heap.pop();
	cout << "the root node is " << heap.top().first << endl;
	heap.push(PSI("cow", 3));
	cout << "the root node is " << heap.top().first << endl;

	cout << heap.size() << " elements are in the heap" << endl;

	return 0;
}

