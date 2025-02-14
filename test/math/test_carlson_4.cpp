///////////////////////////////////////////////////////////////
//  Copyright 2011 John Maddock. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt

#include "setup.hpp"
#include "table_type.hpp"
#define TEST_UDT
#define TEST4

#include <boost/math/special_functions/math_fwd.hpp>
#include "test_carlson.hpp"

void expected_results()
{
   //
   // Define the max and mean errors expected for
   // various compilers and platforms.
   //
   add_expected_result(
       ".*",                      // compiler
       ".*",                      // stdlib
       ".*",                      // platform
       ".*",                      // test type(s)
       "RG: two values the same", // test data group
       ".*", 10000, 700);         // test function
   add_expected_result(
       ".*",             // compiler
       ".*",             // stdlib
       ".*",             // platform
       ".*",             // test type(s)
       ".*RJ.*",         // test data group
       ".*", 2700, 250); // test function
   add_expected_result(
       ".*",          // compiler
       ".*",          // stdlib
       ".*",          // platform
       ".*",          // test type(s)
       ".*",          // test data group
       ".*", 40, 20); // test function
   //
   // Finish off by printing out the compiler/stdlib/platform names,
   // we do this to make it easier to mark up expected error rates.
   //
   std::cout << "Tests run with " << BOOST_COMPILER << ", "
             << BOOST_STDLIB << ", " << BOOST_PLATFORM << std::endl;
}

template <class T>
void test(T t, const char* p)
{
   test_spots(t, p);
}

BOOST_AUTO_TEST_CASE(test_main)
{
   using namespace boost::multiprecision;
   expected_results();
   //
   // Test at:
   // 18 decimal digits: tests 80-bit long double approximations
   // 30 decimal digits: tests 128-bit long double approximations
   // 35 decimal digits: tests arbitrary precision code
   //
   ALL_TESTS
}
