/*

#include <iostream>
#include "BankServer.h"
#include "BankServerConcrete.h"

using namespace std;

class AtmMachine {
 private:
  // Option 1: Use a raw pointer with null check
  // IBankServer* pBankObj = nullptr;

  // Option 2: Use a concrete BankServer implementation in the constructor (replace with your actual implementation)
  IBankServer* pBankObj = new YourConcreteBankServer();

  // Option 3: Use std::unique_ptr for automatic memory management
  // std::unique_ptr<IBankServer> pBankObj;

 public:
  // Constructor with null check for option 1
  AtmMachine(IBankServer* pBankObjConstructor) : pBankObj(pBankObjConstructor) {}

  // Constructor for option 2 (uncomment if using)
  // AtmMachine() : pBankObj(new YourConcreteBankServer()) {}

  int withdraw(int accNo, int value) {
    if (pBankObj != nullptr) {  // Check for null pointer before accessing
      std::cout << "Getting Pointer occur" << std::endl;
      pBankObj->connect();
      int availableBal = pBankObj->GetBal(accNo);
      return availableBal >= value;
    } else {
      // Handle the case where pBankObj is null (e.g., return an error code)
      std::cout << "Nullpointer occur" << std::endl;
      return -1;  // Example: return an error code indicating null pointer
    }
  }
};*/

#include <iostream>
#include "BankServer.h"

class AtmMachine {
 private:
  IBankServer *pBankObj;

 public:
  AtmMachine(IBankServer *pBankObjConstructor) : pBankObj(pBankObjConstructor) {}
  ~AtmMachine() {}

  int withdraw(int accNo, int value) {
    if (pBankObj) {  // Check for null pointer before accessing
      std::cout << "Getting Pointer occur" << std::endl;
      std::cout << "xxxxx" << std::endl;
      pBankObj->connect();
      std::cout << "yyyyy" << std::endl;
      int availableBal = pBankObj->GetBal(accNo);
      std::cout << "zzz" << std::endl;
      return availableBal >= value;
    } else {
      // Handle the case where pBankObj is null
      std::cout << "Nullpointer occur" << std::endl;
      return 0;
    }
  }
};
