//Post-lab 1
//Name: Gizella Wade
//ID; grw7b
//Due Date: 02/19/21                                                                                                                                                                              

#include "bankAccount.h"
#include <iostream>
using namespace std;                                                                                                                                                

bankAccount::bankAccount() {
	balance = 0.00;

}

bankAccount::bankAccount(double amount) {
        balance = amount;
}

bankAccount::~bankAccount() {
       
        
}


double bankAccount::getBalance() const {
    return balance;
}

void bankAccount::setBalance(const  double& amount) {
    balance = amount;
}


double bankAccount::withdraw(double amount){
  
//withdraws money, if it is less than the current total balance, and returns new balance
  if ( amount > balance){
    return balance;
   }

  else{
    balance -= amount;
    return balance;
  }



}

//deposits money and returns new balance
double bankAccount::deposit(double amount){
  balance += amount;
      return balance;

}

