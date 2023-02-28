#include "account.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

#define START_ID 1000000
int Account::number_acc_holder = 0;

// Account methods
Account::Account() 
{
	number_acc_holder++;
	acc_number = number_acc_holder + START_ID;
	cout << "Account's explicit default constructor is called" << endl;
}

Account::~Account() 
{
	number_acc_holder--;
	cout << "Account's explicit destructor is called. Number of account holders is: " << number_acc_holder << endl;
}

Account::Account(const char * name, double balance, bool dormant)
{
	number_acc_holder++;
	acc_number = number_acc_holder + START_ID;
	acc_holder = name;
	this->balance = balance;
	this->dormant = dormant;
	cout << "Account's parameterized constructor is called" << endl;
}

Account::Account(const Account & acc)
{
	number_acc_holder++;
	acc_number = number_acc_holder + START_ID;
	acc_holder = acc.acc_holder;
	balance = acc.balance;
	dormant = acc.dormant;
	cout << "Account's copy constructor is called" << endl;
}
	
double Account::get_balance() const
{
	if (!dormant)
		return balance;
	else
		return 0;
}

string Account::get_account_holder() const
{
	return acc_holder;
}

int Account::get_account_number() const
{
	return acc_number;
}

void Account::set_balance(double val)
{
	balance = val;
}

bool Account::withdraw(double val)
{
	if (val <= balance) {
		balance -= val;
		return true;
	}
	return false;
}

bool Account::deposit(double val)
{
	balance += val;
	return true;
}

bool Account::close_account() {
	if (dormant)
		return false;

	withdraw(balance);
	dormant = true;
	return true;
}

bool Account::transfer_to(Account & receiver, double val)
{
	if (dormant || receiver.dormant){
		cout << "Sender's or receiver's account is dormant" << endl;
		return false;
	}
	bool flag = withdraw(val);

	if (flag) receiver.deposit(val);
	else {
		cout << "Not enough funds to transfer" << endl;
		return false;
	}	

	return true;
}

ostream& operator<< (ostream & out, Account & acc)
{
	out << "Account ID: " << acc.acc_number << ", account name: " << acc.acc_holder << ", balance: " << acc.balance;
	return out;
}

// Overdraft methods
Overdraft::Overdraft() : Account()
{
	cout << "Overdraft's explicit default constructor is called" << endl;
}

Overdraft::~Overdraft() 
{
	cout << "Overdraft's explicit destructor is called" << endl;
}

Overdraft::Overdraft(const char * name, double balance, bool dormant, double overdraft) : Account(name, balance, dormant)
{
	limit = overdraft;
	cout << "Overdraft's parameterized constructor is called" << endl;
}

double Overdraft::get_overdraft_limit() const
{
	return limit;
}

void Overdraft::set_overdraft_limit(double overdraft)
{
	limit = overdraft;
}

bool Overdraft::withdraw(double amount)
{
	if (amount <= get_balance()) {
		Account::withdraw(amount);  // withdraw();   oops! recursive call
		return true;
	}
	else if (amount <= get_balance() + limit) {
		set_balance(get_balance() - amount);
		return true;
	}
	return false;
}
