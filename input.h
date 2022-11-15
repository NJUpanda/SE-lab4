#ifndef __input__
#define __input__
#include <iostream>
#include "File.h"
#include <stdio.h>
#include <unistd.h>
using namespace std;

class Path{
public:
   //基类中的纯虚函数
	virtual int operation(string path, File& f) = 0;
};
class relative : public Path{
public:
	int operation(string path, File& f){
		File tmp(path);
        f = tmp;
        return 1;
	}
};
class absolute : public Path{
public:
	int operation(string path, File& f){
    string buffer;
    buffer = getcwd(NULL, 0);
    int p = path.find(buffer);
    path.erase(p,buffer.length()+1);
    File tmp(path);
    f = tmp;
    return 1;
	}
};
class input_Factory{
public:
	Path* Create(int i){
		switch (i){
		case 1:
			return new relative;
			break;
		case 2:
			return new absolute;
			break;
		default:
			break;
		}
	}
};

#endif