#include <iostream>
#include <math.h>
#include <string.h>
#include <thread>
#include <chrono>
#include <algorithm>
#include <iomanip>

using namespace std;

long double user_transaction();

int main() {
  
}

long double user_transaction() {
  
  string transaction_decision = "";
  cout << "Deposit or Withdrawl?: ";
  cin >> transaction_decision;
   
  long double value_change = 0; 

  transform(transaction_decision.begin(), transaction_decision.end(), transaction_decision.begin(), ::tolower);

  if (transaction_decision == "deposit") {
    cout << "Enter amount to be deposited: ";
    cin >> value_change;
  }
  else {
    cout << "Enter amount to be withdrawn: ";
    cin >> value_change;
    if (value_change > balance) {
      cout << "Transaction is too large, not enough money in account" << "\n";
    }
    value_change *= -1;
  }
  return value_change;
}
