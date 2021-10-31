#include <iostream>
#include "yamlIncludes.h"
#include <vector>
#include <ctime>
#include <cstdlib>

int main() { // int main for now so that we can test this function

  /* What I want to do with this function

    * Create the ability for users to take a loan
    * This will require: 
      * Interest Rate Variables
      * Required Reserve Amount
      * Bank Super user in yaml database that holds the bank information and cannot be modified 
      through the user interface (require direct access to file or some sort of special access code
      like an ssh key)
      * Time function to see when to charge interest on loans
        * Grab time from a library is better than local time due to portability
    
    * Assign user an interest rate. Check in the databse if they have an assigned interest rate. If they do,
    DO NOT ALLOW THEM TO CHANGE IT!!!!!

  */

  srand(time(NULL));

  long double bankBalance = 40000000; // start the bank with 40 million
  // can increase above variable when we feel like tanking the economy

  std::vector<float> interestRates = {1.5, 8.3, 3.4, 2.8}; // lmao imagine getting the 8.3
  int randIndex = rand() % 4; // gets random value between 0 and 3
  
  float assignedInterestRate = interestRates[randIndex]; // picks random interest rate number

  long double reserveRequirement = 0.10 * bankBalance;

  
}
