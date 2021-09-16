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
  
  if (!user_in_database(username)) {
    cout << "Usernmae does not exist. Would you like to sign up? (Y/n): ";
    cin >> user_wants_to_sign_up;
    if (user_wants_to_sign_up == "Y" || user_wants_to_sign_up == "y") {
      create_account();
    }
    else {
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

  long double value_change = user_transaction();
  user_balance_update(value_change, username);
  
  transaction_receipt(username, value_change);
}
