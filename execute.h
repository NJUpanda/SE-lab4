#ifndef __execute__
#define __execute__
#include <fstream>
#include "File.h"
struct arg_
{
    string path1;
    string path2;
    int id;
    int file1;
    int file2;
    int n;
};
struct args_
{
    string path;
    int id_;
    int i_;
};
typedef struct args_ args_;
typedef struct arg_ arg_;
class execute
{
public:
    static void* compile_single(void* args)
    {
        struct args_ data = *(struct args_*) args;
        string a = "g++ " + data.path + " -o " + to_string(data.id_) + "-" + to_string(data.i_);
        system(a.c_str());
        return 0;
    }
    static void complie_(File f)
    {
        for(int sub_i = 0 ; sub_i < f.get_num(); sub_i++)
        {
            pthread_t tids[f.get_sub_num(sub_i)];
            for(int i = 0; i < f.get_sub_num(sub_i); ++i)
            {
                args_* a = new args_;
                a->path = f.get_path(sub_i, i);  
                a->i_ = i;
                a->id_ = sub_i;
                int ret = pthread_create(&tids[i], NULL, compile_single, (void *)a);
                if (ret != 0)
                {
                    cout << "pthread_create error: error_code=" << ret << endl;
                }
            }
            for(int i = 0; i < f.get_sub_num(sub_i); ++i)
            {
                pthread_join(tids[i], NULL);
            }
        }
    }
    static void delete_(File f)
    {
        for(int sub_i = 0; sub_i < f.get_num(); sub_i++)
        {
            for(int i = 0; i < f.get_sub_num(sub_i); i++)
            {
                string path = to_string(sub_i) + "-" + to_string(i);
                remove(path.c_str());
            }
        }
    }
    static void* duipai_single(void* arg)
    {
        int equal = 1;
        struct arg_ data = *(struct arg_*) arg;
        for(int i = 0; i < data.n; i++)
        {
            string s1 = "./" + to_string(data.id) + "-" + to_string(data.file1) + " < " + "case" + to_string(data.id) + "-" + to_string(i) + ".txt" + " > " + to_string(data.id) + "-" + to_string(data.file1) + "-" + to_string(data.file2)   + "-1.txt";
            string s2 = "./" + to_string(data.id) + "-" + to_string(data.file2) + " < " + "case" + to_string(data.id) + "-" + to_string(i) + ".txt" + " > " + to_string(data.id) + "-" + to_string(data.file1) + "-" + to_string(data.file2)   + "-2.txt";
            string s3 = "diff " + to_string(data.id) + "-" + to_string(data.file1) + "-" + to_string(data.file2)  + "-1.txt " +to_string(data.id) + "-" + to_string(data.file1) + "-" + to_string(data.file2)  + "-2.txt";
            system(s1.c_str());
            system(s2.c_str());
            if(system(s3.c_str()))
            {
                equal = 0;
                break;
            }
        }
        if(equal)
        {     
            ofstream p;
            p.open("equal.csv",ios::out|ios::app);   
            p << data.path1<<","<< data.path2 <<endl; 
            p.close();
        }
        else
        {
            ofstream p;
            p.open("inequal.csv",ios::out|ios::app);   
            p << data.path1<<","<< data.path2 <<endl; 
            p.close();
        }
        string s4 = to_string(data.id) + "-" + to_string(data.file1) + "-" + to_string(data.file2)  + "-1.txt";
        string s5 = to_string(data.id) + "-" + to_string(data.file1) + "-" + to_string(data.file2)  + "-2.txt";
        remove(s4.c_str());
        remove(s5.c_str());
        pthread_exit((void*)(&equal));
    }
    static void duipai_(File& f, int times)
    {
        for(int i = 0; i < f.get_num(); i++)
        {
            int n = f.get_sub_num(i);
            int num = n*(n-1)/2;
            pthread_t tids[num];
            int p_id = 0;
            for(int j = 0; j < n-1; j++)
                for(int k = j+1; k < n; k++)
                {
                    arg_* a = new arg_;
                    a->path1 = f.get_path(i,j);
                    a->path2 = f.get_path(i,k);
                    a->id = i;
                    a->file1 = j;
                    a->file2 = k;
                    a->n = times;
                    int ret = pthread_create(&tids[p_id], NULL, duipai_single, (void *)a);
                    if (ret != 0)
                    {
                    cout << "pthread_create error: error_code=" << ret << endl;
                    }
                    p_id++;
                }
            p_id = 0;
            for(int j = 0; j < n-1; j++)
                for(int k = j+1; k < n; k++)
                {
                    int *equal;
                    pthread_join(tids[p_id], (void**)&equal);
                    if(*equal == 1)
                        f.Union(i,j,k);
                    p_id++;
                }

        }
    }
};
#endif