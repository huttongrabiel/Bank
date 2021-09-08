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

using namespace std;

// Withdraw == true and deposit == false
// For withdraw_or_deposit: true == withdraw, false == deposit
  
void user_balance_update(long double balance_change_amount, string username) {

  /* This function uses the user provided log in information to update their balance within the yaml data file. */
  
  YAML::Node source = YAML::LoadFile("../yml/user_accounts.yml");
  
  long double balance = source["users"][username]["balance"].as<long double>();
  balance += balance_change_amount;
  source["users"][username]["balance"] = balance;

  ofstream user_accounts_file;
  user_accounts_file.open("../yml/user_accounts.yml");
  user_accounts_file << fixed << setprecision(2) << source;
  user_accounts_file.close();
} 
