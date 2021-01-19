#include <iostream>
#include <fstream>
#include <string>
#include <queue>
using namespace std;

#define TEMP_FILE_NAME std::string("temp_file")
#define STR(x) std::to_string((x))

template <class T>
class MergeSort
{
public:
    static void Sort(std::vector<T> &arr)
    {
        SortUtil(arr, 0, arr.size() - 1);
    }

private:

    static void SortUtil(std::vector<T> &arr, int left, int right)
    {
        if (left < right)
        {
            int mid = (left + right) / 2;
            SortUtil(arr, left, mid);
            SortUtil(arr, mid + 1, right);
            MergeUtil(arr, left, mid, right);
        }
    }

    static void MergeUtil(std::vector<T> &arr, int left, int mid, int right)
    {
        std::vector<T> arrLeft(mid - left + 1);
        std::vector<T> arrRight(right - mid);

        int arrIndex = left;
        for (int i = 0; i < mid - left + 1; i++)
            arrLeft[i] = arr[arrIndex++];
        for (int i = 0; i < right - mid; i++)
            arrRight[i] = arr[arrIndex++];
        
        arrIndex = left;
        int leftIndex = 0;
        int rightIndex = 0;

        while (leftIndex < mid - left + 1 && rightIndex < right - mid)
        {
            if (arrLeft[leftIndex] <= arrRight[rightIndex])
            {
                arr[arrIndex] = arrLeft[leftIndex];
                leftIndex++;
            }
            else
            {
                arr[arrIndex] = arrRight[rightIndex];
                rightIndex++;
            }
            arrIndex++;
        }

        while (leftIndex < mid - left + 1)
        {
            arr[arrIndex] = arrLeft[leftIndex];
            leftIndex++;
            arrIndex++;
        }

        while (rightIndex < right - mid)
        {
            arr[arrIndex] = arrRight[rightIndex];
            rightIndex++;
            arrIndex++;
        }
    }
};

namespace FileManager
{
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
}

void SortDataInTempFiles(int curTempFileIdx)
{
    
}

void MergeTempFiles(int curTempFileIdx, std::string output_file_name)
{

}

void ClearTempFiles(int curTempFileIdx)
{
    for (int i = 0; i < curTempFileIdx; i++)
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
    FileManager::OpenFile(fs, str_file_input, std::ios_base::in);

    std::fstream fs_temp;
    std::string line;
    size_t bytes;
    int curTempFileIdx = 0;
    int curTempFileSize = 0;
    while ((bytes = FileManager::ReadLine(fs, line, ll_byte_limit)) != 0)
    {
        curTempFileSize += bytes;
        if (curTempFileSize > ll_byte_limit)
        {
            curTempFileSize = bytes;
            curTempFileIdx++;
        }

        FileManager::AppendFileData(fs_temp, TEMP_FILE_NAME + STR(curTempFileIdx), line);
    }

    FileManager::CloseFile(fs);

    system("pause");

    SortDataInTempFiles(curTempFileIdx);

    system("pause");

    MergeTempFiles(curTempFileIdx, str_file_output);

    system("pause");

    ClearTempFiles(curTempFileSize);

    return 0;
}