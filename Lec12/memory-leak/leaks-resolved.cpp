/*
    An illustration of 3 types of memory leaks 
    And how they are resolved

    Course: CMPUT 275
    Omid Ardakanian, University of Alberta (2023)
*/

#include <iostream>
using std::cout; 
using std::endl;

int* leaky();
void dummy();

int main() {
    dummy();
    
    int* temp;
    for (int i = 0; i < 100; i++) {
        temp = leaky();
        // pointer to the allocated memory will be lost
        
        cout << "code is: " << *temp << endl;
        delete temp;
    }

    int** a = new int*[2];
    a[0] = new int;
    a[1] = new int;
    delete a[0];
    delete a[1];

    delete [] a;
    a = nullptr;

    return 0;
}

int* leaky() {
    int* number = new int;
    *number = 10;

    return number;
}

void dummy() {
    // static local variable will retain its value 
    // even after it goes out of scope
    static int *ptr;

    ptr = new int[5];
    for (int i=0; i<5; i++) {
        ptr[i] = 0;
    }

    cout << "code is: " << *ptr << endl;
    delete [] ptr;
}
