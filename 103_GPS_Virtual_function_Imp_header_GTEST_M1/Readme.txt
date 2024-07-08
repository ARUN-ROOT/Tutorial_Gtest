/*
Output:
 g++ -o main main.cpp Client.cpp IGPS.cpp header.cpp
 ./main 
printCoordinates called
Calling getCoordinates
Coordinates received
Latitude: 22.71 Longitude: 8.854
*/

/* For Unit Testing
g++ ClientTest.cc Client.cpp header.cpp -o a.out -lgtest -lgtest_main -lgmock -pthread -L/home/t0101u7/05_UnitTest_Tutorial/Tutorial_Gtest/library/ -I/home/t0101u7/05_UnitTest_Tutorial/Tutorial_Gtest/library/
*/

New Files added header.h and header.cpp
so client file consume this file