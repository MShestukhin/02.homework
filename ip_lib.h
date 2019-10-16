#ifndef IP_LIB_H
#define IP_LIB_H
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <ifaddrs.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iterator>
#include <functional> // for std::greater, std::less

std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

std::string find_ip_where_octet(uint32_t v,int oct){
    if (((v) & 0xff)==oct){
        return inet_ntoa(*(struct in_addr*)&v);
    }
    else if(((v>>8) & 0xff) == oct){
        return inet_ntoa(*(struct in_addr*)&v);
    }
    else if (((v>>16) & 0xff) ==oct){
        return inet_ntoa(*(struct in_addr*)&v);
    }
    else if (((v>>24) & 0xff) == oct){
        return inet_ntoa(*(struct in_addr*)&v);
    }
    else
        return "";
}

#endif // IP_LIB_H
