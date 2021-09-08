#include <iostream>
#include <math.h>
#include <cstring>
#include <thread>
#include <chrono>
#include <algorithm>
#include <iomanip>
#include "yamlIncludes.h"

using namespace std;

long double user_transaction() {
  
  string transaction_decision = "";
  while (transaction_decision != "deposit" && transaction_decision != "withdrawl") {
    cout << "Deposit or Withdrawl?: ";
    cin >> transaction_decision;
  }
   
  long double value_change = 0; 

  transform(transaction_decision.begin(), transaction_decision.end(), transaction_decision.begin(), ::tolower);
  
  if (transaction_decision == "deposit") {
    cout << "Enter amount to be deposited: ";
    cin >> value_change;
  }
  else {
    cout << "Enter amount to be withdrawn: ";
    cin >> value_change;
    value_change *= -1;
  }
  return value_change;
}
