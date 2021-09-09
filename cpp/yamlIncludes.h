#ifndef BANK_INCLUDE_H
#define BANK_INCLUDE_H

void user_balance_update(long double balance_change_amount, std::string username);
long double user_transaction();
bool user_in_database(std::string);
void create_account(std::string new_username);
#endif
