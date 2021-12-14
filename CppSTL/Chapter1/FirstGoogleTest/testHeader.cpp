/* This is the function that tests the functions from the header file */
#include "header.h"
// https://github.com/google/googletest/tree/main/googletest/samples
#include <gtest/gtest.h>


TEST(FactTest, smallNumber) {
	ASSERT_EQ(120, fact(5));
	ASSERT_EQ(24, fact(4));
}

TEST(FactTest, NegativeOrZero) {
	ASSERT_EQ(0, fact(-1));
	ASSERT_EQ(0, fact(0));
}

TEST(FactTest, BigNumber) {
	ASSERT_EQ(3628800, fact(10));
	ASSERT_EQ(39916800, fact(11));
	ASSERT_EQ(2432902008176640000, fact(20));
}

TEST(FiboTest, findFiboNums) {
	FIBO F(10);
	F.find_fibo();
	vector<int> correct={0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
	for(size_t i=0; i<10; i++) {
			ASSERT_EQ(correct[i], F.get_fibo_nums(i));
	}
}

/* Run test cases */ 
int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

/* CONSOLE OUTPUT

[==========] Running 4 tests from 2 test cases.
[----------] Global test environment set-up.
[----------] 3 tests from FactTest
[ RUN      ] FactTest.smallNumber
[       OK ] FactTest.smallNumber (0 ms)
[ RUN      ] FactTest.NegativeOrZero
[       OK ] FactTest.NegativeOrZero (0 ms)
[ RUN      ] FactTest.BigNumber
/home/dimkatsi91/MyDocuments/Cpp-STL-Examples/FirstGoogleTest/testHeader.cpp:20: Failure
      Expected: 2432902008176640000
To be equal to: fact(20)
      Which is: -2102132736
[  FAILED  ] FactTest.BigNumber (0 ms)
[----------] 3 tests from FactTest (0 ms total)

[----------] 1 test from FiboTest
[ RUN      ] FiboTest.findFiboNums
[       OK ] FiboTest.findFiboNums (0 ms)
[----------] 1 test from FiboTest (0 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 2 test cases ran. (1 ms total)
[  PASSED  ] 3 tests.
[  FAILED  ] 1 test, listed below:
[  FAILED  ] FactTest.BigNumber

 1 FAILED TEST


*/
