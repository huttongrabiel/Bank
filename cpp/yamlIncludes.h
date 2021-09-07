#ifndef BANK_INCLUDE_H
#define BANK_INCLUDE_H

void user_balance_update(long double balance_change_amount, std::string username);
YAML::Node connect_to_yml_data();
long double user_transaction();

#endif
