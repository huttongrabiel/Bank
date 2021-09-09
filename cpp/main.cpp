#include <iostream>
#include <yaml-cpp/yaml.h>
#include "yamlIncludes.h"
#include <cstring>

using namespace std;

int main() {
  string username, password;

  cout << "Enter Username: ";
  cin >> username;
  
  if (!user_in_database(username)) {
    cout << "Would you like to sign up? (Y/n)";
  }
  else {
    cout << "Login Successful!" << "\n";
  }

  cout << "\n" << "Enter Password: ";
  cin >> password;

  long double num = user_transaction();
  user_balance_update(num, username);
}
