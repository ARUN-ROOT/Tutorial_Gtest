#pragma once

class IAddInterface {
 public:
  virtual ~IAddInterface() = default;
  virtual int add(int a, int b) = 0;
};

class Add : public IAddInterface {
 public:
  int add(int a, int b) override;
};