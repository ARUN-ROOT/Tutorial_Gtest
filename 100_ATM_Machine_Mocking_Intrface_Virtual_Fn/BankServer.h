#pragma once

class IBankServer {
 public:
  virtual ~IBankServer() {}
  virtual void connect() = 0;
  virtual int GetBal(int AccNo) = 0;
};
