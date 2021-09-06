#include <iostream>
#include <yaml-cpp/yaml.h>
#include "../include/yamlIncludes.h"
#include <cstring>

using namespace std;

int main() {
  string username = "whuty";
  user_transaction();
  user_balance_update(450.36, username);
  connect_to_yml_data();
}
