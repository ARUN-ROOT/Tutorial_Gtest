#pragma once

class AddInterface {
 public:
  virtual ~AddInterface() = default;
  virtual int add(int a, int b) = 0;
};

class Add : public AddInterface {
 public:
  int add(int a, int b) override;
};