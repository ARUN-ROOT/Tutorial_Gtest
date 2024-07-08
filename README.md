# Tutorial_Gtest

# Basic Understanding
# Read First
https://www.geeksforgeeks.org/gtest-framework/

## ------------------------------------------------------ Installation -----------------------------------------------------------
## -------------------------------------------------------------------------------------------------------------------------------

# installing Gtest on Ubuntu from Command Line and Source
https://www.youtube.com/watch?v=6dqFqh3UbPY

https://www.youtube.com/watch?v=7LhEe0QCo-E


#
sudo apt-get install libgmock-dev
cd /usr/src/googletest/googlemock/
sudo mkdir build
sudo cmake ..
sudo make

cd /usr/src/googletest/googlemock/build/lib/
ls


copy all content libgmock.a libgmock_main.a libgtest.a libgtest_main.a
sudo cp lib* /usr/lib/
#


## Videos : --------------------------------------------- Videos -------------------------------------------------------------------
## ---------------------------------------------------------------------------------------------------------------------------------


# -YT - Cognitive Programmer - GTest Tutorial : Google C++ Testing GTest GMock Framework -by Cognitive Programmer

https://www.youtube.com/playlist?list=PL_dsdStdDXbo-zApdWB5XiF2aWpsqzV55


# -YT - Gtest Mock the Calender Interface 
https://www.youtube.com/watch?v=yY6moICK22c

# -YT - Arisaif  Tutorial
Gtest Basic and Mocking virtual Function 

https://www.youtube.com/watch?v=JJqRlSTQlh4&list=TLPQMTUwNjIwMjT002CCUnw1tA&index=2

# -YT -UlasDikme - Test Driven Development - TDD - GoogleTest Introduction with CMake LINUX - C++ - GMOCK
https://www.youtube.com/watch?v=zfgFphZ63UY&t=307s


## -------------------------------------------------------------------------------------------------------------------------------------

# From Command Lines
g++ ClientTest.cc Client.cpp -o a.out -lgtest -lgtest_main -lgmock -pthread -L/home/t0101u7/05_UnitTest_Tutorial/Tutorial_Gtest/library/ -I/home/t0101u7/05_UnitTest_Tutorial/Tutorial_Gtest/library/