///////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2002 - 2011.
//  Copyright 2011 John Maddock. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt
//
// This work is based on an earlier work:
// "Algorithm 910: A Portable C++ Multiple-Precision System for Special-Function Calculations",
// in ACM TOMS, {VOL 37, ISSUE 4, (February 2011)} (C) ACM, 2011. http://doi.acm.org/10.1145/1916461.1916469

#include "setup.hpp"
#include "table_type.hpp"

#include <boost/math/special_functions/math_fwd.hpp>
#include "test_beta.hpp"

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
       ".*gmp.*",                 // test type(s)
       "Beta Function: Medium.*", // test data group
       "beta", 2300, 1000);       // test function
   add_expected_result(
       ".*",                         // compiler
       ".*",                         // stdlib
       ".*",                         // platform
       ".*gmp.*",                    // test type(s)
       "Beta Function: Divergent.*", // test data group
       "beta", 2200, 1000);          // test function
   add_expected_result(
       ".*",                             // compiler
       ".*",                             // stdlib
       ".*",                             // platform
       ".*mpfr_float_backend\\<18\\>.*", // test type(s)
       "Beta Function: Small.*",         // test data group
       "beta", 1000, 750);               // test function
   add_expected_result(
       ".*",                     // compiler
       ".*",                     // stdlib
       ".*",                     // platform
       ".*",                     // test type(s)
       "Beta Function: Small.*", // test data group
       "beta", 12, 8);            // test function
   add_expected_result(
       ".*",                      // compiler
       ".*",                      // stdlib
       ".*",                      // platform
       ".*",                      // test type(s)
       "Beta Function: Medium.*", // test data group
       "beta", 1000, 750);        // test function
   add_expected_result(
       ".*",                         // compiler
       ".*",                         // stdlib
       ".*",                         // platform
       ".*",                         // test type(s)
       "Beta Function: Divergent.*", // test data group
       "beta", 1000, 700);           // test function
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
   test_beta(t, p);
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
