#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;


map<string, int> mymap;
vector <int> ans;
int N,M;
const int MAXN = 240;

int test_case=0;
string alco[MAXN];
int in_degree[MAXN];
int g[MAXN][MAXN];

typedef pair<int, int> pii;

void work(){
    priority_queue <int, vector <int> , greater<int> > zero;
    for(int i=0; i<N; i++){
        if(in_degree[i]==0){
            zero.push((i));
        }
    }
    while(!zero.empty()){
        int cur = zero.top();
        zero.pop();
        ans.push_back(cur);
        for(int i=0; i<N; i++){
            if(g[cur][i]){
                in_degree[i]-=g[cur][i];
                if(in_degree[i]==0){
                    zero.push(i);
                }
            }
        }
    }

    cout<<"Case #"<<test_case<<": Dilbert should drink beverages in this order:";

    for(int i=0; i<N; i++){
        cout<<" "<<alco[ans[i]];
    }
    cout<<"."<<endl;
}

void init(){
    memset(g,0,sizeof(g));
    memset(in_degree, 0, sizeof(in_degree));
    ans.clear();
    mymap.clear();
}

int main(){
    int blank = 0;
    while(cin>>N){
        init();
        /*if(blank!=0){
            cout<<endl;
        }*/
        test_case++;
        blank++;
        string s;
        string s1,s2;
        for(int i=0; i<N; i++){
            cin>>s;
            alco[i] = s;
            mymap[s] = i;
        }
        cin>>M;
        for(int i=0; i<M; i++){
            cin>>s1>>s2;
            g[mymap[s1]][mymap[s2]]++;
            in_degree[ mymap[s2] ] ++;
        }
        work();
        cout<<endl;
    }

    return 0;
}

