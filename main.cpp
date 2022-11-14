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
#include "testcase.h"
#include "execute.h"
#include <unistd.h>
using namespace std;
extern int Input();
extern int Execute();
extern void Output();
File files;
int main()
{
    cout << "welcome!" << endl;
    while(!Input()){}
    //Testcase::auto_(0, files.get_stdin_path(0), 3);
    //Testcase::delete_(1, 100);
    //files.complie_(0);
    //cout<<"ok";
    //files.complie_(1);
    // files.delete_(1);
    // files.delete_(0);
    Execute();
    Output();
}