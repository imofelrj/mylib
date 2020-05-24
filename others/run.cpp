#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

std::string filename,filename_t,command,run,del;
std::string a="g++-9 -o",b=" ",c=" -std=c++17 -Wall",d="./",e="rm ";

int main(int argc,char * argv[]) 
{
    std::cout<<"Program started."<<std::endl;
    filename_t = argv[1]; // 读入全部
    for (int i=0;i<filename_t.size();++i)
    {
        if (filename_t[i]!='.')
            filename.push_back(filename_t[i]);
        else
            break;
    }
    command = a+b+filename+b+filename_t+c;
    std::cout<<"Your input filename is "<<filename_t<<"."<<std::endl;
    std::cout<<"Step 1 build execution file."<<std::endl;
    system(command.c_str());
    std::cout<<"Step 2 run the execution file."<<std::endl;
    std::cout<<"INPUT here"<<std::endl;
    run = d+filename;
    system(run.c_str());
    std::cout<<"Step 3 DELETE the execution file."<<std::endl;
    del = e+filename;
    system(del.c_str());
    std::cout<<"Program finished."<<std::endl;
}
