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
int main()
{
    File files;
    cout << "welcome!" << endl;
    while(!Input()){}//start input
    Execute(files);
    Output(files);
}