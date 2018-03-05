#include "misc.h"
#include <iostream>
#include <fstream>
#ifdef _WIN32
#include <shlwapi.h>
#endif

using namespace std;

const std::string currentDateTime()
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d-%H-%M-%S", &tstruct);

    return buf;
}

std::string replace(std::string source_str, std::string substr, std::string new_substr)
{
    std::string out = source_str;
    int inx;
    while (true)
    {
        inx = out.find(substr);
        if (inx == out.npos)
        {
            break;
        }
        out.replace(inx, substr.size(), new_substr);
    }
    return out;
}

std::string getFilenameWithoutPath(const std::string& filename)
{
    int pos_p = filename.find_last_of("\\");
    if (pos_p != std::string::npos)
    {
        return filename.substr(pos_p + 1);
    }
    pos_p = filename.find_last_of("/");
    if (pos_p != std::string::npos)
    {
        return filename.substr(pos_p + 1);
    }
    return filename;
}

void GetFileNameFromDir(std::string strDir, std::vector<std::string>& vFileDirList)
{
#ifdef _WIN32
    WIN32_FIND_DATAA ffd;
    //LARGE_INTEGER filesize;
    std::string szDir;
    //size_t length_of_arg;
    HANDLE hFind = INVALID_HANDLE_VALUE;
    DWORD dwError = 0;


    szDir = strDir + "\\*";
    hFind = FindFirstFileA(szDir.c_str(), &ffd);

    if (INVALID_HANDLE_VALUE == hFind)
    {
        cout << "get file name error" << endl;
        return;
    }
    do
    {
        if (!(ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
        {
            std::string filename = ffd.cFileName;//(const char*)
            std::string filedir = filename;
            vFileDirList.push_back(filedir);
        }
    }
    while (FindNextFileA(hFind, &ffd) != 0);


    dwError = GetLastError();
    if (dwError != ERROR_NO_MORE_FILES)
    {
        cout << "FindFirstFile error" << endl;
        return;
    }
    FindClose(hFind);
#else
    DIR* dir;
    struct dirent* ptr;
    dir = opendir(strDir.c_str());
    while ((ptr = readdir(dir)) != NULL)
    {
        string path = string(ptr->d_name);
        vFileDirList.push_back(path);
    }
    closedir(dir);
    //sort(vFileDirList.begin(), vFileDirList.end());
#endif
}

vector<string> get_files(string& img_folder, string img_list_file)
{
    vector<string> files;
    if (GetFileAttributesA(img_folder.c_str()) == FILE_ATTRIBUTE_DIRECTORY)
        //if (1)
    {
        // check the image list file
        ifstream fs;
        fs.open(img_list_file);
        if (fs.is_open())
        {
            while (!fs.eof())
            {
                string fln;
                fs >> fln;
                files.push_back(fln);
            }
            fs.close();
        }
        else
        {
            GetFileNameFromDir(img_folder, files);
        }
    }
    else
    {
        files.push_back(img_folder);
    }
    return files;
}


bool fileExist(const std::string& filename)
{
    if (filename.length() <= 0)
    {
        return false;
    }

    std::fstream file;
    bool ret = false;
    file.open(filename.c_str(), std::ios::in);
    if (file)
    {
        ret = true;
        file.close();
    }
    return ret;
}

bool compareLogical(const string& first, const string& second)
{
    bool ordered = first > second;
#ifdef _WIN32
    //auto widen = [](string text)
    //{
    //    locale loc("");
    //    vector<wchar_t> buffer(text.size());
    //    use_facet< std::ctype<wchar_t> >(loc).widen(text.data(), text.data() + text.size(), &buffer[0]);
    //    return wstring(&buffer[0], buffer.size());
    //};

    //wstring lhs = widen(first);
    //wstring rhs = widen(second);
    //ordered = StrCmpLogicalW(lhs.c_str(), rhs.c_str()) < 0;
#endif
    return ordered;
}