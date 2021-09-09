#include <iostream>
#include <ymlIncludes.h>
#include <yaml-cpp/yaml.h>
#include <fstream>

void create_account(string new_username) {
  // If a user does not have an account when user_in_database() is called in main.cpp 
  // it will trigger this function which will sign a user up with all necessary information
  // and add the user to the yml database

  YAML::Node source = YAML::LoadFile("../yml/user_accounts.yml");
  source["users"].push_back(new_username);
}
