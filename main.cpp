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
extern int Input(File& files);
extern int Execute(File& files);
extern void Output(File files);
int main()
{
    File files;
    cout << "welcome!" << endl;
    while(!Input(files)){}//start input
    Execute(files);
    Output(files);
}