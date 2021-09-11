#include <iostream>
#include <cstring>
#include <thread>
#include <chrono>
#include <iomanip>
#include "yamlIncludes.h"
#include <yaml-cpp/yaml.h>

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

void transaction_receipt(string username, long double value_change, string transaction_decision) {

  // This function creates a receipt of the users transaction

  cout << "You're " << transaction_decision << "has been completed!" << "\n";
  
  if (transaction_decision == "withdrawl") {
   cout << "You withdrew " << value_change << " from your account" << "\n";
  }
  else {
   cout << "You deposited " << value_change << " into your account" << "\n";
  }

  YAML::Node source = YAML::LoadFile("../yml/user_accounts.yml");

  cout << "Your updated balance is: " << source["users"][username]["balance"].as<long double>() << "\n";
}
