
/**
 *
 
 g++ main.cpp  -o gtestout -lgtest -lgmock -lgtest_main -lgmock_main -pthread -L/home/t0101u7/05_UnitTest_Tutorial/Tutorial_Gtest/library/
 
 *
 *  
  g++ main.cpp -o a.out -lgtest -lgtest_main -lgmock -pthread -L/home/t0101u7/05_UnitTest_Tutorial/Tutorial_Gtest/library/ -I/home/t0101u7/05_UnitTest_Tutorial/Tutorial_Gtest/library/

 * https://www.youtube.com/watch?v=vxCH4AuVRgo&list=TLPQMTUwNjIwMjT002CCUnw1tA&index=1
 *
 *
 */

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "AtmMachine.h"
#include "BankServer.h"

class MockBankServer : public IBankServer {
 public:
  MOCK_METHOD(void, connect, (), (override));
  MOCK_METHOD(int, GetBal, (int), (override));
};

class Myclass_TF : public ::testing::Test {
 protected:
  // Pointer instance
  AtmMachine *atm_machine;
  MockBankServer *MockBankServerObj;
  void SetUp() override {
    // Arrange
    // This order important
    MockBankServerObj = new MockBankServer();
    atm_machine = new AtmMachine(MockBankServerObj);  // Address Passing

    std::cout << "Alive" << std::endl;
  }
  void TearDown() override {
    delete MockBankServerObj;
    delete atm_machine;
    std::cout << "Dead" << std::endl;
  }
};

TEST_F(Myclass_TF, testcasse) {
  // MockBankServer MockBankServerObj;
  // AtmMachine atm_machine(&MockBankServerObj);
  std::cout << "1.1" << std::endl;
  // EXPECT_CALL(MockBankServerObj, connect()).Times(1);
  ON_CALL(*MockBankServerObj, connect()).WillByDefault(::testing::Return());

  std::cout << "1.2" << std::endl;
  // EXPECT_CALL(MockBankServerObj, GetBal(12345)).Times(10).WillRepeatedly(::testing::Return(100));
  // EXPECT_CALL(MockBankServerObj, GetBal(12345))
  //     .Times(::testing::AtMost(2))  // Expect at most two calls
  //     .WillOnce(::testing::Return(100));

  ON_CALL(*MockBankServerObj, GetBal(12345)).WillByDefault(::testing::Return(100));

  std::cout << "1.3" << std::endl;
  //This function need Two mock connect and getBalance
  int result = atm_machine->withdraw(12345, 50);
  std::cout << "1.4" << std::endl;
  EXPECT_TRUE(result);
  std::cout << "1.5" << std::endl;
}

int main(int argc, char **argv) {
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}
/*
g++ ClientTest.cc Client.cpp -o a.out -lgtest -lgtest_main -lgmock -pthread -L/home/t0101u7/05_UnitTest_Tutorial/Tutorial_Gtest/library/ -I/home/t0101u7/05_UnitTest_Tutorial/Tutorial_Gtest/library/
*/