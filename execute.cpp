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
#include "execute.h"
#include "testcase.h"
#include <unistd.h>
using namespace std;
int Execute(File& files)
{
    cout<<"请输入对拍次数:\n";
    int times;
    cin >> times;
    execute::complie_(files);
    for(int i = 0; i < files.get_num(); i++)
    {
        Testcase::auto_(i, files.get_stdin_path(i), times);
    }
    ofstream p;
    p.open("equal.csv",ios::out|ios::trunc);   
    p<<"file1"<<","<<"file2"<<endl; 
    p.close();
    ofstream p1;
    p1.open("inequal.csv",ios::out|ios::trunc);   
    p1<<"file1"<<","<<"file2"<<endl; 
    p1.close();
    execute::duipai_(files, times);
    execute::delete_(files);
    for(int i = 0; i < files.get_num(); i++)
    {
         Testcase::delete_(i, times);
    }
}