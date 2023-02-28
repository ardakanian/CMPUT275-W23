#include "account.h"
#include <iostream>

using namespace std;

void basic_class_test() {
	Account first;
	cout << first.get_balance() << endl;
	cout << first << endl;

	Account second("Omid", 1000);
	cout << second << endl;

	Account third = second;
	cout << third << endl;

	Account fourth("Zac", 1500);
	cout << fourth << endl;

	second.withdraw(600);
	cout << "Omid's account balance is " << second.get_balance() << endl;
	cout << "Zac's account balance is " << fourth.get_balance() << endl;

	if(second.transfer_to(fourth, 200)) {
		cout << "Money transfer was successful" << endl;
		cout << "Omid's account balance is " << second.get_balance() << endl;
		cout << "Zac's account balance is " << fourth.get_balance() << endl;
	} else
		cout << "Money transfer failed" << endl;

	if(second.transfer_to(fourth, 400)) {
		cout << "Money transfer was successful" << endl;
		cout << "Omid's account balance is " << second.get_balance() << endl;
		cout << "Zac's account balance is " << fourth.get_balance() << endl;
	} else
		cout << "Money transfer failed" << endl;
}

void polymorphic_inheritance_test() {
	Account first("Omid", 1000);
	Overdraft second("Omid", 1000, false, 500);
	cout << second.get_overdraft_limit() << endl;
	Account third("Zac", 1500); 

	Account* first_ptr = &first;
	// we can't write first_ptr->get_overdraft_limit()
	
	// each instance of Overdraft is an instance of Account
	// hence implicit upcasting (from Overdraft* to Account*) takes place
	Account* second_ptr = &second;

	if(first_ptr->transfer_to(third, 1250))
		cout << "Money transfer was successful" << endl;
	else
		cout << "Money transfer failed" << endl;

	if(second_ptr->transfer_to(third, 1250))
		cout << "Money transfer was successful" << endl;
	else
		cout << "Money transfer failed" << endl;
}

void virtual_destructor_test() {
	Account* third_ptr = new Overdraft("Paul", 10000, false, 500);

	delete third_ptr;
	// if the destructor was not virtual then the base destructor would be called
}

int main() {
	// basic_class_test();
	// polymorphic_inheritance_test();
	virtual_destructor_test();
	return 0;
}