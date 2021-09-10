#include <iostream>
#include "yamlIncludes.h"
#include <yaml-cpp/yaml.h>
#include <fstream>

int main() {
  // If a user does not have an account when user_in_database() is called in main.cpp 
  // it will trigger this function which will sign a user up with all necessary information
  // and add the user to the yml database
  std::string new_username = "raphael";
  YAML::Node source = YAML::LoadFile("../yml/user_accounts.yml");
  source["users"][new_username].push_back(source["users"][new_username]["account_id"]);

  std::ofstream user_accounts_file;
  user_accounts_file.open("../yml/user_accounts.yml");
  user_accounts_file << source;
  user_accounts_file.close();
}
