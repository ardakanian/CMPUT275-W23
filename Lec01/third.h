/*
	A demonstration of a header file with header guards.
	
	A header file may contain both function declaration and definition.


	Course: CMPUT 275
	Omid Ardakanian
*/

#ifndef THIRD_H
#define THIRD_H

bool compare(int a, int b) {
	if (b > a) return false;
	else return true;
}

#endif