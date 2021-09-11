#include <iostream>
#include <cstring>
#include <thread>
#include <chrono>
#include <iomanip>
#include "yamlIncludes.h"
#include <yaml-cpp/yaml.h>
#include <algorithm>

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

void transaction_receipt(string username, long double value_change) {

  // This function creates a receipt of the users transaction

  if (value_change < 0) {
    cout << "\n" << "Your withdrawl has been completed!" << "\n"; 
    cout << "   Withdrew: " << value_change << "\n";
  }
  else {
    cout << "Your deposit has been completed!" << "\n";
    cout << "   Deposited: " << value_change << "\n";
  }

  YAML::Node source = YAML::LoadFile("../yml/user_accounts.yml");

  cout << "   Balance: " << source["users"][username]["balance"].as<long double>() << "\n";
}
