///////////////////////////////////////////////////////////////
//  Copyright 2011 John Maddock. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt

#include "setup.hpp"
#include "table_type.hpp"
#define TEST_UDT

#include <boost/math/special_functions/math_fwd.hpp>
#include "test_erf.hpp"

void expected_results()
{
   //
   // Define the max and mean errors expected for
   // various compilers and platforms.
   //
   add_expected_result(
       ".*",                 // compiler
       ".*",                 // stdlib
       ".*",                 // platform
       ".*gmp_float<18>.*",  // test type(s)
       "Erf Function:.*",    // test data group
       "erfc?", 2200, 1500); // test function
   add_expected_result(
       ".*",                     // compiler
       ".*",                     // stdlib
       ".*",                     // platform
       ".*gmp_float<18>.*",      // test type(s)
       "Inverse Erf.*",          // test data group
       "erfc?_inv", 2200, 1500); // test function
#ifdef BOOST_INTEL
   add_expected_result(
       ".*",                  // compiler
       ".*",                  // stdlib
       ".*",                  // platform
       "float128",            // test type(s)
       "Erf Function:.*",     // test data group
       "erfc?", 15000, 1000); // test function
#endif
   add_expected_result(
       ".*",                 // compiler
       ".*",                 // stdlib
       ".*",                 // platform
       ".*cpp_bin_float.*",  // test type(s)
       "Erf Function:.*",    // test data group
       "erfc?", 3000, 1000); // test function
   add_expected_result(
       ".*",                        // compiler
       ".*",                        // stdlib
       ".*",                        // platform
       ".*mpfr_float_backend<0>.*", // test type(s)
       ".*",                        // test data group
       ".*", 600, 100);             // test function
   add_expected_result(
       ".*",               // compiler
       ".*",               // stdlib
       ".*",               // platform
       ".*",               // test type(s)
       "Erf Function:.*",  // test data group
       "erfc?", 300, 200); // test function
   add_expected_result(
       ".*",                 // compiler
       ".*",                 // stdlib
       ".*",                 // platform
       ".*",                 // test type(s)
       "Inverse Erf.*",      // test data group
       "erfc?_inv", 60, 20); // test function
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
   test_erf(t, p);
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
