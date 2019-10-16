#include <cassert>
#include "ip_lib.h"

int main()
{
    try
    {
        std::vector<uint32_t> ip_pool;

        for(std::string line; std::getline(std::cin, line);)
        {
            std::vector<std::string> v = split(line, '\t');
            struct sockaddr_in antelope;
            int addr=inet_aton(v.at(0).c_str(),&antelope.sin_addr);
            int Ip1,Ip2,Ip3,Ip4;
            if(addr)
                ip_pool.push_back(antelope.sin_addr.s_addr);
        }

        // TODO reverse lexicographically sort

        std::sort(ip_pool.begin(), ip_pool.end(), [](uint32_t a, uint32_t b){
            if(((a) & 0xff) != ((b) & 0xff)) {
                return ((a) & 0xff) > ((b) & 0xff);
            }
            else if (((a>>8) & 0xff) != ((b>>8) & 0xff)) {
                return ((a>>8) & 0xff) > ((b>>8) & 0xff);
            }
            else if (((a>>16) & 0xff) != ((b>>16) & 0xff)) {
                return ((a>>16) & 0xff) > ((b>>16) & 0xff);
            }
            else {
                 return ((a>>24) & 0xff) > ((b>>24) & 0xff);
            }
        });

        for(const auto&  v : ip_pool){
            std::cout<<inet_ntoa(*(struct in_addr*)&v)<<std::endl;
        }


        // 222.173.235.246
        // 222.130.177.64
        // 222.82.198.61
        // ...


        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // TODO filter by first byte and output

        for(const auto&  v : ip_pool){
            if(((v) & 0xff)==1)
                std::cout<<inet_ntoa(*(struct in_addr*)&v)<<std::endl;
        }

        // ip = filter(1)

        // 1.231.69.33
        // 1.87.203.225
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // TODO filter by first and second bytes and output
        // ip = filter(46, 70)

        for(const auto&  v : ip_pool){
            if(((v) & 0xff)==46 && ((v>>8) & 0xff)==70)
                std::cout<<inet_ntoa(*(struct in_addr*)&v)<<std::endl;
        }

        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76

        // TODO filter by any byte and output
        // ip = filter_any(46)

        for( const auto&  v : ip_pool){
            std::string ip=find_ip_where_octet(v,45);
            if(ip.size())
                std::cout<<ip<<std::endl;
        }

        // 186.204.34.46
        // 186.46.222.194
        // 185.46.87.231
        // 185.46.86.132
        // 185.46.86.131
        // 185.46.86.131
        // 185.46.86.22
        // 185.46.85.204
        // 185.46.85.78
        // 68.46.218.208
        // 46.251.197.23
        // 46.223.254.56
        // 46.223.254.56
        // 46.182.19.219
        // 46.161.63.66
        // 46.161.61.51
        // 46.161.60.92
        // 46.161.60.35
        // 46.161.58.202
        // 46.161.56.241
        // 46.161.56.203
        // 46.161.56.174
        // 46.161.56.106
        // 46.161.56.106
        // 46.101.163.119
        // 46.101.127.145
        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76
        // 46.55.46.98
        // 46.49.43.85
        // 39.46.86.85
        // 5.189.203.46
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
