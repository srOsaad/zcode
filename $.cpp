#include<iostream>
#include <sys/stat.h>
using namespace std;

bool exists(string folder_loc){
    struct stat sb;
    return (stat(folder_loc.c_str(), &sb) == 0);
}

int main(int argc, char* argv[]){
    int i=1;
    while(i<argc){
        string file(argv[i]);
        
        if(!exists("p:/Apps (console)/"+file)){
            cout<<"False app "<<file;
            if(i<argc-1) cout<<'\n';
            i++;
            continue;
        }

        string command("p: && cd p:/Apps (console)/"+file+" && app");
        system(command.c_str());
        if(i<argc-1) cout<<'\n';
        i++;
    }
    return 0;
}