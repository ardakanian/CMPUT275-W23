#include <iostream>
#include <vector>
#include <algorithm>  // sort

using namespace std; 
// Be careful! There's a function called 
// binary_search in namespace std

void bsearch(vector<int>& sorted_array, int q) {
	int high = sorted_array.size(), low = 0, mid;
	while (low < high) {
		mid = (high + low)/2;
		if (sorted_array[mid] == q) {
			// index of the integer in sorted_array
			cout << mid << endl;
			return;
		} else if (sorted_array[mid] > q) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}
	cout << "Not found" << endl;
	return;
}

int main() {
	int count, query;
	cin >> count;

	vector<int> sorted_array(count);
	for (int& i : sorted_array)
		cin >> i;

	// sort integers in non-descending order
	sort(sorted_array.begin(), sorted_array.end());
	for(int i : sorted_array)
		cout << i << " ";
	cout << endl;

	cin >> query;
	bsearch(sorted_array, query);

	return 0;
}
