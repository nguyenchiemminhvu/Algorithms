#include <iostream>
#include <fstream>
#include <string>
#include <queue>
using namespace std;

#define TEMP_FILE_NAME std::string("temp_file")
#define STR(x) std::to_string((x))

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

void AppendFileData(std::fstream &fs, std::string file_name, std::string data)
{
    fs.open(file_name, std::ios_base::out | std::ios_base::app);
    if (!fs.is_open())
        return;

    fs << data << std::endl;
    fs.close();
}

void CloseFile(std::fstream &fs)
{
    if (fs.is_open())
    {
        fs.close();
    }
}

void ClearTempFiles(int curTempFileSize)
{
    for (int i = 0; i < curTempFileSize; i++)
    {
        std::remove(std::string(TEMP_FILE_NAME + STR(i)).c_str());
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
    std::fstream fs_temp;
    while ((bytes = ReadLine(fs, line, ll_byte_limit)) != 0)
    {
        curTempFileSize += bytes;
        if (curTempFileSize > ll_byte_limit)
        {
            curTempFileSize = bytes;
            curTempFileIdx++;
        }

        AppendFileData(fs_temp, TEMP_FILE_NAME + STR(curTempFileIdx), line);
    }

    CloseFile(fs);
    system("pause");
    ClearTempFiles(curTempFileSize);

    return 0;
}