#include <iostream>
#include <string>
using namespace std;

int main(int argc, char **argv)
{
    if (argc != 4)
        return -1;
    
    std::string str_file_input(argv[1]);
    std::string str_file_output(argv[2]);
    std::string str_byte_limit(argv[3]);
    long long int ll_byte_limit = std::stoll(str_byte_limit);

    

    return 0;
}