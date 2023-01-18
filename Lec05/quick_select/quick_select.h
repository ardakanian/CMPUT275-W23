/*
	quick_select header file

	OBSERVE: We did not include the prototype for swap() or partition()
	that are in the file quick_select.cpp

	The reason is that those are helper functions for the implementation of
	quick_select(), but they are not intended to be part of our (very small)
	"quick_select" library.

	Course: CMPUT 275, University of Alberta
	Zac Friggstad, 2021
*/

#ifndef _QUICK_SELECT_H_
#define _QUICK_SELECT_H_

// assumes the array[] has length at least num and that 0 <= k < num
// returns the element at index k of the sorted version of the first "num" elements of array[]
// runs in O(n) time in the sense that quick_sort runs in O(n log n) time (i.e. probably unless
// we have terrible luck with our partition steps)
int quick_select(int array[], int num, int k);

#endif