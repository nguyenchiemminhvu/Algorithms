#include <iostream>
#include <fstream>
#include <string>
#include <queue>
using namespace std;

#define TEMP_FILE_NAME "temp_file"

void OpenFile(std::fstream &fs, std::string file_name, std::ios_base::openmode om)
{
    fs.open(file_name, om);
}

size_t ReadLine(std::fstream &fs, std::string &line, long long int limited_bytes)
{
    if (!fs.is_open())
        return 0;

    if (fs.eof())
        return 0;

    char * temp = new char[limited_bytes];
    fs.getline(temp, limited_bytes, '\n');
    line.assign(temp);
    delete[] temp;

    return line.length();
}

void CloseFile(std::fstream &fs)
{
    if (fs.is_open())
    {
        fs.close();
    }
}

int main(int argc, char **argv)
{
    if (argc != 4)
        return -1;
    
    std::string str_file_input(argv[1]);
    std::string str_file_output(argv[2]);
    std::string str_byte_limit(argv[3]);
    long long int ll_byte_limit = std::stoll(str_byte_limit);

    std::fstream fs;
    OpenFile(fs, str_file_input, std::ios_base::in);

    std::string line;
    size_t bytes;
    int curTempFileIdx = 0;
    int curTempFileSize = 0;
    while ((bytes = ReadLine(fs, line, ll_byte_limit)) != 0)
    {
        std::cout << bytes << " " << line << std::endl;
    }

    CloseFile(fs);

    return 0;
}