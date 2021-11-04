#include <iostream>
#include <cstring>
#include <thread>
#include <chrono>
#include <iomanip>
#include "yamlIncludes.h"
#include <yaml-cpp/yaml.h>
#include <algorithm>

long double user_transaction() {
  
  std::string transaction_decision = "";
  while (transaction_decision != "deposit" && transaction_decision != "withdrawl") {
    std::cout << "Deposit or Withdrawl?: ";
    std::cin >> transaction_decision;
  }
   
  long double value_change = 0; 

  transform(transaction_decision.begin(), transaction_decision.end(), transaction_decision.begin(), ::tolower);
  
  if (transaction_decision == "deposit") {
    std::cout << "Enter amount to be deposited: $";
    std::cin >> value_change;
  }
  else {
    std::cout << "Enter amount to be withdrawn: $";
    std::cin >> value_change;
    value_change *= -1;
  }
  return value_change;
}

void transaction_receipt(std::string username, long double value_change) {

  // This function creates a receipt of the users transaction
  
  if (value_change < 0) {
    std::cout << "\n" << "Your withdrawl has been completed!" << "\n";
    std::cout << "----------------------------------" << "\n"; 
    std::cout << "   Withdrew: $" << value_change << "\n";
  }
  else {
    std::cout << "\n" << "Your deposit has been completed!" << "\n";
    std::cout << "--------------------------------" << "\n";
    std::cout << "   Deposited: $" << value_change << "\n";
  }

  YAML::Node source = YAML::LoadFile("../yml/dataBase.yml");

  std::cout << "   New Balance: $" << source["users"][username]["balance"].as<long double>() << "\n";
  std::cout << "\n";
}

void display_current_user_bank_information(std::string username) {
  
  YAML::Node source = YAML::LoadFile("../yml/dataBase.yml");
  
  std::cout << "\n"; 
  std::cout << "Your Current Bank Information" << "\n";
  std::cout << "-----------------------------" << "\n";
  std::cout << "  Current Balance: $" << source["users"][username]["balance"].as<long double>() << "\n";
  std::cout << "\n";
}
