#include <iostream>
#include <yaml-cpp/yaml.h>
#include "yamlIncludes.h"
#include <cstring>

using namespace std;

int main() {
  string username, password, user_wants_to_sign_up;

  cout << "Enter Username: ";
  cin >> username;
  
  if (!user_in_database(username)) {
    cout << "Would you like to sign up? (Y/n): ";
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
    cout << "Login Successful!" << "\n";
  }

  cout << "\n" << "Enter Password: ";
  cin >> password;

  long double num = user_transaction();
  user_balance_update(num, username);
}
