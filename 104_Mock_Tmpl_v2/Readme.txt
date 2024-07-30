 g++ -std=c++11 -o drive_alert main.cpp IGPS.cpp Speed_header.cpp  DriveAlert_client.cpp -lpthread
 ./drive_alert 

g++ Speed_headerTest.cc DriveAlert_client.cpp IGPS.cpp  Speed_header.cpp -o a.out -lgtest -lgtest_main -lgmock -pthread -L/home/t0101u7/05_UnitTest_Tutorial/Tutorial_Gtest/library/ -I/home/t0101u7/05_UnitTest_Tutorial/Tutorial_Gtest/library/
