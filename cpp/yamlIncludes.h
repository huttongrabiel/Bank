#ifndef BANK_INCLUDE_H
#define BANK_INCLUDE_H

void user_balance_update(long double balance_change_amount, std::string username);
long double user_transaction();
bool user_in_database(std::string);
bool username_matches_password(std::string, std::string);
void transaction_receipt(std::string, long double);
void create_account();
void update_transaction_count(std::string);
void display_current_user_bank_information(std::string);

#endif
