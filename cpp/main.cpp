#include <iostream>
#include <yaml-cpp/yaml.h>
#include "yamlIncludes.h"
#include <cstring>

using namespace std;

int main() {
  string username, password, user_wants_to_sign_up;

  cout << "Enter Username: ";
  cin >> username;
  
  if (user_in_database(username)) {
    cout << "Enter Password: ";
    cin >> password;
  }

  if (user_in_database(username) && username_matches_password(username, password)) {
    cout << "Login Successful!" << "\n";
  }
  
  // Shield your eyes because lines 24-49 are about to get weird. Here's the breakdown:
  // We read in a username and if it does not exist we prompt them to create an account,
  // if they don't respond either Y, y, N, or n to the prompt, we require them to continue
  // until they have selected one of those four values,
  // next if they select decide to sign up we call our create_account() function,
  // otherwise they get sent on their way with a nice little goodbye return 0 
  // if the username they provide is already in our database then we have them 
  // provide a password and then they can login, this is a terrible idea 
  // because their is no call back to the sign up step if they orginally provide
  // a username that exists but is not their user, will fix 
  else if (!user_in_database(username)) {
    cout << "Username does not exist. Would you like to sign up? (Y/n): ";
    cin >> user_wants_to_sign_up;
    while (user_wants_to_sign_up != "n" && user_wants_to_sign_up != "N" && user_wants_to_sign_up != "Y" && user_wants_to_sign_up != "y") {
      cout << "Please enter: Y, y, N, or n." << "\n";
      cout << "Username does not exist. Would you like to sign up? (Y/n): ";
      cin >> user_wants_to_sign_up;
    } 
    if (user_wants_to_sign_up == "Y" || user_wants_to_sign_up == "y") {
      create_account();
    }
    else if (user_wants_to_sign_up == "n") {
      cout << "Well maybe one day you'll join us, until then, goodbye!" << "\n"; 
      return 0;
    }
  }
  else {
    while (!(user_in_database(username) && username_matches_password(username, password))) {
      cout << "Username or Password Incorrect, Try Again" << "\n";
      cout << "Enter Username: ";
      cin >> username;
      cout << "Enter Password: ";
      cin >> password;
    }
    cout << "Login Successful!" << "\n";
  }
  
  display_current_user_bank_information(username);
  long double value_change = user_transaction();
  user_balance_update(value_change, username);
  update_transaction_count(username);
  transaction_receipt(username, value_change);
}
