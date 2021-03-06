#include <iostream>
#include "yamlIncludes.h"
#include <yaml-cpp/yaml.h>
#include <fstream>

void create_account() {
  // If a user does not have an account when user_in_database() is called in main.cpp 
  // it will trigger this function which will sign a user up with all necessary information
  // and add the user to the yml database
  // Info needed from user: username,  
  int next_account_id = 2;
  
  // Collecting all necessary information
  std::string username, password, retyped_password, first_name, last_name;
  std::cout << "New Username: ";
  std::cin >> username;
 
  while (user_in_database(username)) {
    std::cout << "Username taken." << "\n";
    std::cout << "New username: ";
    std::cin >> username; 
  }

  std::cout << "New Password: ";
  std::cin >> password;
  std::cout << "Retype New Password: ";
  std::cin >> retyped_password;

  while (password != retyped_password) {
    std::cout << "Passwords do not match, please try again." << "\n";

    std::cout << "New Password: ";
    std::cin >> password;

    std::cout << "Retype New Password: ";
    std::cin >> retyped_password;
  }

  std::cout << "First Name: ";
  std::cin >> first_name;
  std::cout << "Last Name: ";
  std:: cin >> last_name; 

  std::ofstream user_accounts_file;
  user_accounts_file.open("../yml/user_accounts.yml", std::ios_base::app | std::ios_base::in);
   
  user_accounts_file << "\n  " << username << ": ";
  user_accounts_file << "\n    account_id: " << next_account_id;
  user_accounts_file << "\n    first_name: " << first_name;
  user_accounts_file << "\n    last_name: " << last_name;
  user_accounts_file << "\n    balance: 0";
  user_accounts_file << "\n    password: " << password;
  user_accounts_file.close();
}
