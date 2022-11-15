#include <string>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <stdlib.h>
#include <limits.h>
#include "File.h"
#include "input.h"
#include <unistd.h>
using namespace std;

int Input(File& files)
{
    string a;
    int type;
    cout << "1.relative path 2.absolute path   please input:" << endl;
    cin >> a;
    if(a.compare("1") == 0)
        type = 1;
    else if (a.compare("2")==0)
        type = 2;
    else{
        return 0;
    }
    input_Factory* factory = new input_Factory();
    string p;
    cout << "please input the path:"<<endl;
    cin >> p;
    DIR *pDir;
    struct dirent* ptr;
    if(!(pDir = opendir(p.c_str()))){
        cout<<"Folder doesn't Exist!"<<endl;
        return 0;
    }
    factory->Create(type)->operation(p, files);
    return 1;
}