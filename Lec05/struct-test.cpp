/*
	A simple demonstration of structure variables in C/C++
	
	Course: CMPUT 275
	Omid Ardakanian, University of Alberta (2023)
*/

#include <iostream>

struct Point2D {								// structure is a compound data type
	int x = 0;
	int y = 0;
	char label [8] = "origin";
} pointA, pointB[2];							// declaring variables of this type

int main() {
	std::cout << sizeof pointA << std::endl;	// we don't talk about padding in this course
	pointB[0].x = 2;							
	pointB[1].x = -1;
	pointA.x = 1;
	Point2D * ptr = &pointB[1];					// pointer to Point2D structure
	std::cout << pointB[1].x << std::endl;		// dot operator used w/ variable
	std::cout << ptr->x << std::endl;			// arrow operator used w/ pointer

	return 0;
}