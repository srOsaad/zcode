#include <bits/stdc++.h>
using namespace std;

void readVec(vector<string> vec){
    for(auto i : vec) cout<<i<<'\n';
}
vector<string> getCommandText(string command){
    vector<string> out;
    string line;
    ofstream cup("garbadge.txt");
    cup.close();
    command+=" >> garbadge.txt";
    system(command.c_str());
    ifstream read("garbadge.txt");
    
    while (getline(read,line))
    {
        out.push_back(line);
    }
    read.close();
    return out;
}

bool tagOutputInLine(string line, string tag, string *out){
    if(line.size()<tag.size()) {return 0;}
    for(int i=0;i<line.size()-tag.size();i++){
        if(line[i]==tag[0] && tag==line.substr(i,tag.size())){
            while(line[i]!=':'){i++;}
            i++;
            while(line[i]==' '){i++;}
            (*out)=line.substr(i,line.size()-i);
            return 1;
        }
    }
    return 0;
}

int main(){
    vector<string> profiles, pass, outlines;
    string tag1="All User Profile", tag2="Key Content",
    temp;
    int sp;
    outlines = getCommandText("netsh wlan show profiles");

    for(auto l : outlines) if(tagOutputInLine(l,tag1,&temp)) profiles.push_back(temp);


    for(int i=0;i<profiles.size();i++) {
        temp="netsh wlan show profile \""+profiles[i]+"\" key=clear";
        outlines = getCommandText(temp.c_str());
        //readVec(outlines);
        for(auto l : outlines) if(tagOutputInLine(l,tag2,&temp)){ pass.push_back(temp); break; }
        if(i+1!=pass.size()) {pass.push_back("-_-");}
    }

    ofstream finishing("id_pass.txt");
    for(auto l : profiles) sp=max(sp,int(l.size()));
    sp+=2;
    for(int i=0;i<profiles.size();i++) {
        finishing<<profiles[i];
        for(int l=0;l<sp-profiles[i].size();l++) finishing<<' ';
        finishing<<pass[i]<<'\n';
    }
    finishing.close();
    system("del garbadge.txt");
    return 0;
}