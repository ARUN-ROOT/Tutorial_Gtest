step 1: Copy libgtest.a libgtest_main.a into current project directory
    cp libgtest* /home/t0101u7/05_UnitTest_Tutorial/Tutorial_Gtest/02_UT_class/
step 2: Link the Library
    g++ main.cpp -o GTestExample -lgtest -lgtest_main -pthread -L/home/t0101u7/05_UnitTest_Tutorial/Tutorial_Gtest/02_UT_class/ -I/home/t0101u7/05_UnitTest_Tutorial/Tutorial_Gtest/02_UT_class/
step 3:./GTestExample