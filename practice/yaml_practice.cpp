#include <iostream>
#include "yaml-cpp/yaml.h"
#include <stdlib.h>
#include <fstream>

using namespace std;

int main() {
  YAML::Node source = YAML::LoadFile("../yml/user_accounts.yml");
  string me = "users";
  source[me]["whuty"]["balance"] = 3000;
  ofstream fout("../yml/user_accounts.yml");
  fout << source; 
  cout << source["users"]["whuty"]["balance"] << "\n";
  fout.close();
}
