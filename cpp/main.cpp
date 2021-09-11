#include <iostream>
#include <yaml-cpp/yaml.h>
#include "yamlIncludes.h"
#include <cstring>

using namespace std;

int main() {
  string username, password;

  cout << "Enter Username: ";
  cin >> username;
  cout << "Enter Password: ";
  cin >> password;

  if (user_in_database(username) && username_matches_password(username, password)) {
    cout << "Login Successful!" << "\n";
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
