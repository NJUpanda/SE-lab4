#include <iostream>
#include "File.h"
using namespace std;
void Output(File files)
{
    cout << "请输入查看的文件夹编号:";
    int id;
    cin >> id;
    for(int i = 0; i < files.get_sub_num(id); i++)
    {
        cout << i << ":" << files.get_path(id, i) << endl;
    }
    files.Print(id);
    cout << "是否结束? y or n" << endl;
    string a;
    cin >> a;
    if(a.compare("n") == 0)
        Output(files);
}