#ifndef __testcase__
#define __testcase__
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include <stdlib.h>
#include<time.h>
#include<sstream>
using namespace std;
class Testcase
{
public:
	static void delete_(int id, int n)
	{
		for(int i = 0; i < n; i++)
		{
			string path = "case"+ to_string(id) + "-" + to_string(i) + ".txt";
			remove(path.c_str());
		}
	}
	static void auto_(int id, string path, int n)
	{
		delete_(id, n);
		int num = 0;
		ifstream ifs(path);
		vector<string> s;
		string str;
		while (ifs >> str)
		{
			num++;
			s.push_back(str);
		}
		ifs.close();
		srand((unsigned)time(NULL));
		for (int i = 0; i < num; i++)
		{
			
			str = s[i];
			if (str[0] == 'i')
			{
				int a = 0, b = 0;
				int left = str.find('(');
				int right = str.find(')');
				int comma = str.find(',');
				string l = str.substr(left + 1, comma - left - 1);
				string r = str.substr(comma + 1, right - comma - 1);
				stringstream str1;
				str1 << l;
				str1 >> a;
				str1.clear();
				str1 << r;
				str1 >> b;
				int i = 0;
				
				for(int j = 0; j < n; j++)
				{
					ofstream testcase("case"+ to_string(id) + "-" + to_string(j) + ".txt", ios::app);
					i = rand() % (b - a + 1) + a;
					testcase << i << " ";
					testcase.close();
				}
				
			}
			if (str[0] == 'c')
			{

				for(int j = 0; j < n; j++)
				{
					ofstream testcase("case"+ to_string(id) + "-" + to_string(j) + ".txt", ios::app);
					char letter = rand() % 26 + 65;
					if (rand() % 2) {
						letter += 32;
					}
					testcase << letter << " ";
					testcase.close();
				}

			}
			if (str[0] == 's')
			{
				cout << str;
				int a = 0, b = 0;
				int left = str.find('(');
				int right = str.find(')');
				int comma = str.find(',');
				string l = str.substr(left + 1, comma - left - 1);
				string r = str.substr(comma + 1, right - comma - 1);
				stringstream str1;
				str1 << l;
				str1>> a;
				str1.clear();
				str1 << r;
				str1 >> b;
				int j = 0;
				j = rand() % (b - a + 1) + a;
				for(int j = 0; j < n; j++)
				{
					ofstream testcase("case"+ to_string(id) + "-" + to_string(j) + ".txt", ios::app);
					string str2;
					for (int i = 0; i < j; i++)
					{
						char letter = rand() % 26 + 65;
						if (rand() % 2) {
							letter += 32;
						}
						str2.push_back(letter);
					}
					testcase << str2 << " ";
					testcase.close();
				}

			}
		}
	}
};


#endif