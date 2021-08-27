//Post-lab 1
//Name: Gizella Wade
//ID; grw7b
//Due Date: 02/19/21

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H


#include <iostream>
using namespace std;

class bankAccount{


public:

bankAccount();

bankAccount(double amount);

~bankAccount();

double withdraw(double amount);

double deposit(double amount);

double getBalance() const;
void setBalance(const double& amount);

 friend std:: ostream& operator<<(std::ostream& output, const bankAccount& obj);
 

private:

double balance;


};


#endif 
