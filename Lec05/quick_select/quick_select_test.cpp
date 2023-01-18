/*
	Tests the implementation of quick_select.

	Times the function and also compares timing with just sorting the entire array and returning a[k].

	Usage:
	./quick_select_test <NUM>
	where <NUM> is the length of the array you want to test.
	The array will be filled with random integers and a random index k will be selected.

	Some concepts appear here that have not yet been covered:
	 - Dynamic memory (next lecture)
	 - Using chrono   (not a required course concept, but you can see an example of how to use it)
	 - Returning something other than 0 from main (not a required course concept but it is good to think about)

	Course: CMPUT 275, University of Alberta
	Zac Friggstad, 2021
*/

#include <iostream>
#include <cstdlib>   // for rand()
#include <algorithm> // for sort()
#include <cassert>   // for assert()
#include <chrono>    // for timing things

#include "quick_select.h"

using namespace std;

// We haven't covered some concepts used in this main() yet.
// For now, just focus on understanding why quick_select works.
// IN PARTICULAR: we will cover new[] and delete[] next lecture.
int main(int argc, char** argv) {
	if (argc != 2) {
		cout << "Usage: quick_select_test <size_of_array>" << endl;
		
		// The operating system can use this return value to see something went wrong.
		// Useful for things we don't cover in this course. For example: bash scripts.
		return 1; 
	}

	int num = atoi(argv[1]);
	assert(num >= 1);

	int *array, *backup; // pointers to the start of the arrays we will use

	// the array and backup array are dynamically allocated on the heap (next lecture...)
	// because we cannot allocate very large arrays on the stack
	array = new int[num];
	backup = new int[num];

	cout << "Filling an array with " << num << " random values..." << endl;

	for (int i = 0; i < num; i++) {
		array[i] = rand();    // generates a single random signed 32-bit random integer
		backup[i] = array[i]; // copying this array so our comparison with the sorting method is fair
	}

	// generate a random index in the range [0, num)
	int k = rand() % num;

	// compute the kth value using quick_select and time how long it takes
	// STYLE COMMENT: use auto sparingly. If you are using a simple type like "int" or even
	// "string", then state it explicitly for readability.
	// Here, it is ok to use auto because the type name is a bit long and we never explicilty use the type
	// anyway (the only time we use these variables involves another cast anyway)
	auto start_quick_select = chrono::high_resolution_clock::now();
	int kth_value = quick_select(array, num, k);
	auto end_quick_select = chrono::high_resolution_clock::now();

	cout << endl
		 << "quick_select took "
		 << chrono::duration_cast<chrono::milliseconds>(end_quick_select - start_quick_select).count()
		 << " milliseconds" << endl;

	cout << "The value at index " << k << " in the sorted array is: " << kth_value << endl << endl;

	cout << "Double checking with the built-in sorting algorithm" << endl;

	// sort the copy of the array using a built-in sorting algorithm (discussed later in the course)
	// and time how long it takes
	auto start_sorting_method = chrono::high_resolution_clock::now();
	sort(backup, backup+num);
	auto end_sorting_method = chrono::high_resolution_clock::now();

	// checks that the answer from quick_select was correct
	assert(kth_value == backup[k]);

	cout << "All good! The sorting method took "
		 << chrono::duration_cast<chrono::milliseconds>(end_sorting_method - start_sorting_method).count()
		 << " milliseconds" << endl;

	// free up the dynamically-allocated arrays (good style, even though our program is terminating)
	delete[] array;
	delete[] backup;

	return 0;
}
