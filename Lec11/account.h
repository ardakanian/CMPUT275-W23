#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <string>
using namespace std;

class Account {
private:
	string acc_holder;
	static int number_acc_holder;
	int acc_number;
	double balance;
	bool dormant;
public:
	Account();
	virtual ~Account();
	Account(const char * name, double balance = 0.0, bool dormant = false);
	Account(const Account & acc);

	double get_balance() const;
	bool get_status() const { return dormant; };
	string get_account_holder() const;
	int get_account_number() const;
	void set_balance(double val);
	virtual bool withdraw(double val);
	bool deposit(double val);
	bool close_account();
	bool transfer_to(Account & receiver, double val);

	friend ostream & operator<< (ostream & out, Account & acc);
};

class Overdraft : public Account {
private:
	double limit;
	
public:
	Overdraft();
	~Overdraft();
	Overdraft(const char * name, double balance = 0.0, bool dormant = false, double overdraft = 0);

	double get_overdraft_limit() const;
	void set_overdraft_limit(double overdraft);
	bool withdraw(double amount);
};
#endif