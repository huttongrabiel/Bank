#include <iostream>
#include <math.h>
#include <string.h>
#include <thread>
#include <chrono>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
  long double deposit_amount, withdrawl_amount, balance;
  balance = 10000;
  
  string transaction_decision = "";
  cout << "Deposit or Withdrawl?: ";
  cin >> transaction_decision;
  
  transform(transaction_decision.begin(), transaction_decision.end(), transaction_decision.begin(), ::tolower);

  if (transaction_decision == "deposit") {
    cout << "Enter amount to be deposited: ";
    cin >> deposit_amount;
    balance += deposit_amount;
  }
  else {
    cout << "Enter amount to be withdrawn: ";
    cin >> withdrawl_amount;
    if (withdrawl_amount > balance) {
      cout << "Transaction is too large, not enough money in account" << "\n";
    }
    else {
      balance -= withdrawl_amount;
    }
  }
  cout << fixed << "Your updated balance is: " << setprecision(2) << balance << "\n";
  cout << "Have a good day" << "\n";
}
