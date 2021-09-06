#ifndef BANK_INCLUDE_H
#define BANK_INCLUDE_H
#include <cstring>

void user_balance_update(long double balance_change_amount, string username);
YAML::Node connect_to_yml_data();
long double user_transaction();

#endif
