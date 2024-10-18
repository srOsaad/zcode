#include <bits/stdc++.h>
using namespace std;

int main(){
    int ns[]={5,6,7,41,42,81,82,83,84,85,86,91,92,93};
    int sz = sizeof(ns)/sizeof(int);

    for(int i=0;i<sz;i++){
        cout<<"Working on "<<ns[i]<<".mkv\n";
        string command = "A:\\Systems\\ffmpeg\\bin\\ffmpeg -i "+to_string(ns[i])+".mkv mov/"+to_string(ns[i])+".mov";
        system(command.c_str());
    }
}