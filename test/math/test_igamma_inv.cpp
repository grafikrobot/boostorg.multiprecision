///////////////////////////////////////////////////////////////
//  Copyright 2011 John Maddock. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt

#ifdef TEST_MPF_50
#define BOOST_MATH_MAX_ROOT_ITERATION_POLICY 250
#endif

#include "setup.hpp"
#include "table_type.hpp"
#define TEST_UDT

#include <boost/math/special_functions/math_fwd.hpp>
#include "test_igamma_inv.hpp"

void expected_results()
{
   //
   // Define the max and mean errors expected for
   // various compilers and platforms.
   //
   add_expected_result(
       ".*",                           // compiler
       ".*",                           // stdlib
       ".*",                           // platform
       ".*gmp_float<18>.*",            // test type(s)
       ".*small.*",                    // test data group
       ".*", 2000000000L, 300000000L); // test function
   add_expected_result(
       ".*",                         // compiler
       ".*",                         // stdlib
       ".*",                         // platform
       ".*mpfr_float_backend<18>.*", // test type(s)
       ".*small.*",                  // test data group
       ".*", 30000000L, 20000000L);  // test function
   add_expected_result(
       ".*",                       // compiler
       ".*",                       // stdlib
       ".*",                       // platform
       ".*",                       // test type(s)
       ".*small.*",                // test data group
       ".*", 10000000L, 2500000L); // test function
   add_expected_result(
       ".*",              // compiler
       ".*",              // stdlib
       ".*",              // platform
       ".*",              // test type(s)
       ".*",              // test data group
       ".*", 7000, 2000); // test function
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
   test_gamma(t, p);
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
