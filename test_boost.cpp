#include "lib.h"

#define BOOST_TEST_MODULE test_main

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_suite_version)

    BOOST_AUTO_TEST_CASE(test_version_valid)
    {
        BOOST_CHECK(library1::version() > 0);
    }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(test_suite_square)

    BOOST_AUTO_TEST_CASE(square_zero_test)
    {
        BOOST_REQUIRE_EQUAL(library1::square(0), 0);
    }

    BOOST_AUTO_TEST_CASE(square_negative_test)
    {
        BOOST_REQUIRE_EQUAL(library1::square(-2), 4);
    }

    BOOST_AUTO_TEST_CASE(square_pozitive_test)
    {
        BOOST_REQUIRE_EQUAL(library1::square(2), 4);
    }

BOOST_AUTO_TEST_SUITE_END()
