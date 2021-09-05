#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <yaml-cpp/yaml.h>

/* This program is used in bank_operations.cpp. Its job is to update the yml database with the most 
current information for a client of the bank. Every time a client makes and transaction, their 
balance is updated as well as a transaction count. */

using namespace std;

int main() {
  update_balance(45, true);
}

// Withdraw == true and deposit == false
// For withdraw_or_deposit: true == withdraw, false == deposit
  
void user_balance_update(long double balance_change_amount, string username) {

  /* This function uses the user provided log in information to update their balance within the yaml data file. */
  
  long double current_balance = 0;

  YAML::Node source = YAML::LoadFile("yml/user_accounts.yml");
  
  source["users"][username][balance] += balance_change_amount;
  ofstream fout("yml/user_accounts.yml");
  fout << source;
  f.close(); 
}

YAML::Node connect_user_to_data() {
  YAML::Node source = YAML::LoadFile("yml/user_accounts.yml");
  return source; 
}
