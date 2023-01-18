/*
	An implementation of the Quick Select algorithm for finding the k'th largest value
	in an unsorted array.

	Running time: probably O(n) in the sense that quick sort probably runs in O(n log n) time.

	The full program asks the user for the size of the array they want to check and the index k.

	It fills the array with random values and then finds the k'th largest value using quick_select().
	The running time in milliseconds is reported.

	Then it sorts a copy of the original array and compares the k'th element of that array
	with the value found by quick_select(). This is also timed for comparison with quick_select().

	Uses some C++11 features, meaning you might need to compile with the flag -std=c++11 if you are
	not using the CMPUT 275 virtual machine.

	Course: CMPUT 275, University of Alberta
	Zac Friggstad, 2021
*/



// Using pass-by-reference means we actually swap the values in the variables that
// were passed as arguments to the function call.
// Yes, I know an equivalent function is in <algorithm>, but this is here as an explicit example
// of pass-by-reference.
void swap_vals(int& x, int& y) {
	int z = x;
	x = y;
	y = z;
}


// ASSUMPTION: num >= 1 and that array[] has length at least num
// performs the partition procedure from quick sort (from CMPUT 274)
// returns the index of the pivot
int partition(int array[], int num) {
	// swap the pivot to the end of the array
	swap_vals(array[num/2], array[num - 1]);

	int lo_index = 0, hi_index = num - 2;

	// invariant: throughout the algorithm we have
	// array[i] < array[num-1] for every i < lo_index and
	// array[j] >= array[num-1] for every j > hi_index
	while (lo_index <= hi_index) {
		if (array[lo_index] < array[num - 1]) {
			lo_index++;
		}
		else if (array[hi_index] >= array[num - 1]) {
			hi_index--;
		}
		else {
			// just swap their values, the next iteration will adjust indices
			swap_vals(array[lo_index], array[hi_index]);
		}
	}

	// move the pivot to its proper location
	swap_vals(array[num - 1], array[hi_index + 1]);
	return hi_index + 1;
}


// assumes the array[] has length at least num and that 0 <= k < num
// returns the element at index k of the sorted version of the first "num" elements of array[]
int quick_select(int array[], int num, int k) {
	// select a pivot and rearrange the array around this pivot
	int pivot_index = partition(array, num);

	if (k == pivot_index) {
		// BASE CASE: if the pivot landed exactly at the index we are looking for, just return it
		return array[k];
	}
	else if (k < pivot_index) {
		// if the index of the pivot is > k, then we just search the part of the array
		// that is left of the pivot
		return quick_select(array, pivot_index, k);
	}
	else {
		// search the part of the array that is right of the pivot
		// the value k changes because we are skipping over some items
		int skipped = pivot_index+1;
		return quick_select(array + skipped, num - skipped, k - skipped);
	}
}
