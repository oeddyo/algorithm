/*
ID: xieke.b1
PROG: milk3
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

ofstream fout("milk3.out");
ifstream fin ("milk3.in");
vector<int> s;
vector<int> szs;
bool vis[21][21][21];
vector<int> ans;

void dfs(){
    if(vis[s[0]][s[1]][s[2]]){
        return ;
    }
    if(s[0]==0){
        ans.push_back(s[2]);
    }
    cout<<s[0]<<" "<<s[1]<<" "<<s[2]<<endl;
    vis[s[0]][s[1]][s[2]] = true;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i==j)continue;
            //int from = s[i];
            //int to = s[j];
            
            int pour = min( s[i], szs[j]-s[j]);
            s[i] -=pour;
            s[j] +=pour;

            dfs();
            s[i] += pour;
            s[j] -= pour;
        }
    }

}

void work(){
    memset(vis,0,sizeof(vis));
    dfs();
    sort(ans.begin(), ans.end());
    for(int i=0; i<ans.size()-1; i++){
        fout<<ans[i]<<" ";
    }
    fout<<ans[ans.size()-1]<<endl;

}


int main(){
    for(int i=0; i<3; i++){
        int t;
        fin>>t;
        szs.push_back(t);
    }
    s.push_back(0);
    s.push_back(0);
    s.push_back(szs[2]);

    work();
    
    return 0;
}

