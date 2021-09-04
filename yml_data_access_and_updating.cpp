#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <yaml-cpp/yaml.h>

/* This program is used in bank_operations.cpp. Its job is to update the yml database with the most 
current information for a client of the bank. Every time a client makes and transaction, their 
balance is updated as well as a transaction count. */

using namespace std;

void update_balance(long double balance_change_amount, bool withdraw_or_deposit);

int main() {
  update_balance(45, true);
}

// Withdraw == true and deposit == false
// For withdraw_or_deposit: true == withdraw, false == deposit
  
void update_balance(long double balance_change_amount, bool withdraw_or_deposit) {

  /* This function uses the user provided log in information to update their balance within the yaml data file. */
  
  long double current_balance = 0;

  YAML::Node users = YAML::LoadFile("yml/user_accounts.yml");
  cout << users << "\n";

  // The following is simply an outline because I do not know the syntax for specifying which part of our
  // yaml file to use
  
// for (int item : users["users"] {
//    if (users["account_id"] == user_id {
//        current_balance = users["account_id"]["current_balance"];
//    }
//  }
      
//  if (withdraw_or_deposit) {
//    current_balance += balance_change_amount;
//  }
//  else {
//    current_balance -= balance_change_amount;
//  }
}
