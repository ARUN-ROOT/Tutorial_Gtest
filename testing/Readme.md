# Practise_gtest
# In this Unit GTest Automatically download , Unit Test Performed  and Code Coverage Shown
mkdir build 

cd build 

cmake -G "Unix Makefiles" ../  

cmake --build . --target MDBundleTest 

cmake --build . --target MDBundleTest_coverage 

./MDBundleTest --gtest_output=xml:Report.xml && cmake --build . --target MDBundleTest_coverage MDBundleTest_coverage_xml -j 10 

 
