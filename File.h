#ifndef __File__
#define __File__
#include "subfile.h"
#include "Equivalence.h"
#include <string>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <stdlib.h>
#include <limits.h>
using namespace std;
class File
{
    int num;
    vector<string> subpath;
    vector<subfile> sub;
    vector<UFSets> ufsets;
public:
    File(){}
    File(File& f)
    {
        num = f.num;
        sub = f.sub;
        subpath = f.subpath;
        ufsets = f.ufsets;
    }
    File(string path)
    {
        DIR *pDir;
        struct dirent* ptr;
        if(!(pDir = opendir(path.c_str()))){
            cout<<"Folder doesn't Exist!"<<endl;
            return;
        }
        while((ptr = readdir(pDir))!=0) {
            if (strcmp(ptr->d_name, ".") != 0 && strcmp(ptr->d_name, "..") != 0 && strcmp(ptr->d_name, "stdin_format.txt") != 0){           
                subpath.push_back(path + "/" + ptr->d_name);
        }
        }
        closedir(pDir);
        num = subpath.size();
        for(int i = 0; i < num; i++)
        {
            subfile s(subpath[i],i);
            sub.push_back(s);
        }
        for(auto i:sub)
        {
             UFSets u(i.get_num());
             ufsets.push_back(u);
        }
    }
    int get_num()
    {
        return num;
    }
    int get_sub_num(int id)
    {
        return sub[id].get_num();
    }
    string get_stdin_path(int id)
    {
        return subpath[id] + "/stdin_format.txt";
    }
    string get_path(int id, int f_id)
    {
        return sub[id].get_path(f_id);
    }
    string get_name(int id, int f_id)
    {
        return sub[id].get_name(f_id);
    }
    void Union(int id, int f1, int f2)
    {

        ufsets[id].Union(f1, f2);

    }
    void Print(int id)
    {
        ufsets[id].Print();
    }
};
#endif