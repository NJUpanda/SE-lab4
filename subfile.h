#ifndef __subfile__
#define __subfile__
#include "subfile.h"
#include <string>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <stdlib.h>
#include <limits.h>
#include <pthread.h>
using namespace std;

class subfile
{
    int id;
    int num;
    string name;
    vector<string> file_name;
    vector<string> file_path;
public:
    subfile(string path, int Id):id(Id)
    {
        DIR *pDir;
        struct dirent* ptr;
        if(!(pDir = opendir(path.c_str()))){
            cout<<"Folder doesn't Exist!"<<endl;
            return;
        }
        while((ptr = readdir(pDir))!=0) {
            if (strcmp(ptr->d_name, ".") != 0 && strcmp(ptr->d_name, "..") != 0 && strcmp(ptr->d_name, "stdin_format.txt") != 0){           
                file_path.push_back(path + "/" + ptr->d_name);
                file_name.push_back(ptr->d_name);
        }
        }
        closedir(pDir);
        num = file_name.size();
    }
    int get_id()
    {
        return id;
    }
    int get_num()
    {
        return num;
    }
    string get_name(int f_id)
    {
        return file_name[f_id];
    }
    string get_path(int f_id)
    {
        return file_path[f_id];
    }
};
#endif