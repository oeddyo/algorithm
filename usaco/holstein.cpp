/*
ID: xieke.b1
PROG: holstein
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

ofstream fout("holstein.out");
ifstream fin ("holstein.in");
int N,V;
const int INF = 999999999;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define all(c) (c).begin(), (c).end()
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 

map< pii, int> mymap;
const int MAXN = 30;
vi p[MAXN];
vi needs;

bool exceed(int s){
    vi tmp(V,0);
    for(int i=0; i<N; i++){
        if( ((1<<i)&s) != 0){
            for(int j=0; j<V; j++){
            tmp[j]+=p[i][j];
            }
        }
    }
    /*
    cout<<"now s is "<<s<<endl;
    cout<<"needs is "<<endl;
    for(int j=0; j<V; j++){
        cout<<needs[j]<<" ";
    }cout<<endl;
    cout<<"tmp is "<<endl;
    for(int j=0; j<V; j++){
        cout<<tmp[j]<<" ";
    }cout<<endl;
    */
    for(int j=0; j<V; j++){
        if(tmp[j]<needs[j]){
            return false;
        }
    }
    return true;
}


void work(){
    int ans = INF;
    int state = -1;
    for(int s=0; s<(1<<N); s++){
        int num = __builtin_popcount(s);
        if(exceed(s) ){
            //ans = min(ans, num);
            if( ans>num){
                ans = num;
                state = s;
            }
        }
    }

    vi ans_v;
    for(int i=0; i<N; i++){
        if( (state&(1<<i)) !=0){
            ans_v.push_back(i+1);
        }
    }

    fout<<ans;
    for(int i=0; i<ans_v.size(); i++){
        fout<<" "<<ans_v[i];
    }fout<<endl;

}

int main(){
    fin>>V;
    for(int i=0; i<V; i++){
        int t;
        fin>>t;
        needs.push_back(t);
    }
    fin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<V; j++){
            int t;
            fin>>t;
            p[i].push_back(t);
        }
    }
    work();
    return 0;
}

