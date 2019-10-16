#define BOOST_TEST_MODULE test_ip_filter

#include "ip_lib.h"
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_ip_filter)

BOOST_AUTO_TEST_CASE(test_ip_filter_split)
{
    BOOST_CHECK(split("113.162.145.156	111	0", '\t').size() == 3);
    BOOST_CHECK(split("113.162.145.156	111	0", '\t').at(0) == "113.162.145.156");
}

BOOST_AUTO_TEST_CASE(octet_find)
{
    struct sockaddr_in antelope;
    inet_aton("68.45.152.8",&antelope.sin_addr);
    BOOST_CHECK(find_ip_where_octet(antelope.sin_addr.s_addr,45) == "68.45.152.8");
    inet_aton("68.46.152.8",&antelope.sin_addr);
    BOOST_CHECK(find_ip_where_octet(antelope.sin_addr.s_addr,45).size() == 0);
}

BOOST_AUTO_TEST_SUITE_END( )
