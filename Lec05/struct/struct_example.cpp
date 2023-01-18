/*
	One more example of a struct and how to access members of a struct
	if you only have a pointer to the struct.
*/

#include <iostream>

using namespace std;

struct Student {
	char name[40];
	int grade;
};


// Display the name and grade of a student.
void display_struct(Student a_student) {
	cout << "Name: " << a_student.name << endl
 		 << "Grade: " << a_student.grade << endl
 		 << endl;
}

int main() {
	// Initialize a single struct with the character array zac.name
	// initially containing the characters "Zac Friggstad\0" (NULL terminator)
	Student zac = {"Zac Friggstad", 92};

	display_struct(zac);

	// get an alias for the variable "zac"
	// NOTE: both this variable and the variable zac now refer
	// the exact struct in memory
	Student& identity_thief = zac;

	// The identity thief will now change how my name appears
	identity_thief.name[2] = 'k';

	// notice how the name held by the struct variable zac changes
	// because we changed it with an alias
	// so be careful using aliases! only use them when necessary
	// or else the code can get difficult to follow
	display_struct(zac);

	// now get a pointer to zac and to the identity thief
	Student* zac_ptr = &zac;
	Student* thief_ptr = &identity_thief;

	// just demonstrating they are pointing to the same location,
	// because the variables were aliases
	if (zac_ptr == thief_ptr) {
		cout << "The pointers are the same" << endl << endl;
	}

	// FINALLY, let us change the grade using the pointer.
	// Recall a->b is the same as (*a).b
	// It dereferences the pointer first and then access the member "b".
	zac_ptr->grade = 78;

	display_struct(zac);
	// would be the same as display_struct(*zac_ptr)

	return 0;
}