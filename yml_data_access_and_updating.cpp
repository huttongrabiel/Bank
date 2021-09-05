#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <yaml-cpp/yaml.h>

/* This program is used in bank_operations.cpp. Its job is to update the yml database with the most 
current information for a client of the bank. Every time a client makes and transaction, their 
balance is updated as well as a transaction count. */

using namespace std;

void update_balance(long double value_change, long int user_id, long double current_balance);
void user_id_to_bank_account_connection(long double balance_change_amount, bool withdraw_or_deposit, long int user_id);

int main() {
  update_balance(45, true);
}

// Withdraw == true and deposit == false
// For withdraw_or_deposit: true == withdraw, false == deposit
  
void user_id_to_bank_account_connection(long double balance_change_amount, bool withdraw_or_deposit, long int user_id) {

  /* This function uses the user provided log in information to update their balance within the yaml data file. */
  
  long double current_balance = 0;

  YAML::Node source = YAML::LoadFile("yml/user_accounts.yml");

  for (const auto& p : source["users"]) {
    for (const auto& key_value : p) {
      YAML::Node key = key_value.first;
      YAML::Node value = key_value.second;
      if (key.as<string>() == "account_id") {
        // We want the balance value associated with the p value here
        if (value == user_id) {
          // current_balance = value associated with this user_id so we need to continue inner loop until = to "balance"  
          long double new_balance = update_balance(user_transaction(), user_id, current_balance); // Update stored user balance based on the amount they change in user_transaction 
          value = new_balance; // Set yaml file balance = to new_balance 
        } 
      }
      else {
        continue;
      }
    }
  }


  // Outline to access user balance in yaml
  //
  // for (cont auto& p : source["users"]) {
  //  for (const auto& id : p["account_id"]) {
  //    if (id == user_id) {
  //      for (const auto& balance : id) {
  //        update_balance();
  //      }
  //    }
  //  }
  //}
  //    

  // Add function to save user last login, transaction count, etc. in addition to the update_balance
  // associated with a user 
}

void update_balance(long double value_change, long int user_id, long double current_balance) {
  current_balance += value_change;  
}
