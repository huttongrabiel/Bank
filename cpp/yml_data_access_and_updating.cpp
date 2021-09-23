#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <yaml-cpp/yaml.h>
#include "yamlIncludes.h"
#include <cstring>
#include <fstream>
#include <iomanip>
/* This program is used in bank_operations.cpp. Its job is to update the yml database with the most 
current information for a client of the bank. Every time a client makes and transaction, their 
balance is updated as well as a transaction count. */

// Withdraw == true and deposit == false
// For withdraw_or_deposit: true == withdraw, false == deposit
  
void user_balance_update(long double balance_change_amount, std::string username) {

  /* This function uses the user provided log in information to update their balance within the yaml data file. */
  
  YAML::Node source = YAML::LoadFile("../yml/user_accounts.yml");
  
  long double balance = source["users"][username]["balance"].as<long double>();
  balance += balance_change_amount;
  source["users"][username]["balance"] = balance;

  std::ofstream user_accounts_file;
  user_accounts_file.open("../yml/user_accounts.yml");
  user_accounts_file << std::fixed << std::setprecision(2) << source;
  user_accounts_file.close();
}

bool user_in_database(std::string username) {
  // This function checks whether the given user value is in the database and prompts them to sign up if not
  
  YAML::Node source = YAML::LoadFile("../yml/user_accounts.yml");
   
  // Iterate through each source["users"][username] and see if an account exists that matches the entered username
  
  bool flag = false;

  for (const auto& p : source["users"]) {
    YAML::Node seq = p.first;
    if (username == seq.as<std::string>()) {
      flag = true;
    }
  }
  return flag;
}

bool username_matches_password(std::string username, std::string password) {

  // This function confirms the username to the password
  
  YAML::Node source = YAML::LoadFile("../yml/user_accounts.yml");
  
  if (source["users"][username]["password"].as<std::string>() == password) {
    return true;
  }
  else {
    return false;
  }
}

void update_transaction_count(std::string username) {

  YAML::Node source = YAML::LoadFile("../yml/user_accounts.yml");

  long unsigned int transaction_count = source["users"][username]["transaction_count"].as<long unsigned int>();
  transaction_count++;
  source["users"][username]["transaction_count"] = transaction_count;

  std::ofstream user_accounts_file;
  user_accounts_file.open("../yml/user_accounts.yml");
  user_accounts_file << source;
  user_accounts_file.close();
}
