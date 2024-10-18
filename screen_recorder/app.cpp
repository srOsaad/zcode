#include <bits/stdc++.h>
using namespace std;  
  
int main()  
{  
    time_t now = time(0);
    tm* ltm = localtime(&now); 
    string fileName="Record_"+to_string(ltm->tm_min)+"_"+to_string(ltm->tm_hour)+"_"+to_string(ltm->tm_mday)+"_"+to_string(1 + ltm->tm_mon)+"_"+to_string(1900 + ltm->tm_year)+".mkv";
    string command="A:/systems/ffmpeg/bin/ffmpeg -framerate 30 -probesize 42M -f gdigrab -i desktop "+fileName;
    string cmd="E: && cd E:/Videos/Captures && "+command;
    //system("E: && cd E:/Videos/Captures");
    system(cmd.c_str());
}  