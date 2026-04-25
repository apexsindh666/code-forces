#include<bits/stdc++.h>
using namespace std;

struct Team {
    string name;
    int pts=0, gd=0, gs=0;
};

int main(){
    int n;
    cin>>n;
    vector<Team> teams(n);
    map<string,int> idx;
    for(int i=0;i<n;i++){
        cin>>teams[i].name;
        idx[teams[i].name]=i;
    }
    int m=n*(n-1)/2;
    while(m--){
        string line;
        cin>>line;
        // format: name1-name2 num1:num2
        // find the dash that separates teams (not part of a name — names are alpha only)
        int dashPos=-1;
        for(int i=0;i<(int)line.size();i++){
            if(line[i]=='-'){dashPos=i;break;}
        }
        string t1=line.substr(0,dashPos);
        string t2=line.substr(dashPos+1);
        string score;
        cin>>score;
        int colon=score.find(':');
        int g1=stoi(score.substr(0,colon));
        int g2=stoi(score.substr(colon+1));
        
        int i1=idx[t1], i2=idx[t2];
        teams[i1].gs+=g1; teams[i1].gd+=g1-g2;
        teams[i2].gs+=g2; teams[i2].gd+=g2-g1;
        if(g1>g2){teams[i1].pts+=3;}
        else if(g1<g2){teams[i2].pts+=3;}
        else{teams[i1].pts+=1;teams[i2].pts+=1;}
    }
    
    sort(teams.begin(),teams.end(),[](const Team&a,const Team&b){
        if(a.pts!=b.pts) return a.pts>b.pts;
        if(a.gd!=b.gd)  return a.gd>b.gd;
        return a.gs>b.gs;
    });
    
    vector<string> qualified;
    for(int i=0;i<n/2;i++) qualified.push_back(teams[i].name);
    sort(qualified.begin(),qualified.end());
    for(auto&s:qualified) cout<<s<<"\n";
}