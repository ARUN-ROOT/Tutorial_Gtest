#include "BankServer.h"

class YourConcreteBankServer : public IBankServer {
 public:
  YourConcreteBankServer() {}  // Default constructor

  virtual void connect() override {
    // Implement your logic to connect to the bank server (e.g., network connection, authentication)
    // For this example, we'll simulate a successful connection
    // Return 0 to indicate successful connection (you can define your own codes)
  }

  virtual int GetBal(int AccNo) override {
    // Implement your logic to retrieve account balance from the bank server
    // For this example, we'll simulate a balance of 1000 for account 12345
    if (AccNo == 12345) {
      return 1000;
    } else {
      return -1;  // Indicate invalid account or error retrieving balance
    }
  }
};
