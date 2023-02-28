#include <string>
using namespace std;

class Account {
   public:
      Account(const char * name, double opening) { account_holder = name; balance = opening; };
      void withdraw(double amt) { if(amt<=balance) balance-=amt; };
   protected:
      double balance; 
      string account_holder;
};

class Overdraft: public Account {
   public:
      Overdraft(const char * name, double opening, double over) : Account(name, opening), limit(over) {};
      int get_limit() { return limit; };
      void withdraw(double amt) { if(amt<=balance+limit) balance-=amt; };
   private:
      double limit;
};

int main() {
   Overdraft obj("test", 100.0, 10.0);
   return 0;
}