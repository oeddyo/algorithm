#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int K,N,R;
typedef pair<int,int> mypair;

const int MAXN = 101;
bool open[MAXN];
bool closed[MAXN];

vector < pair<int, mypair> > g[MAXN];
struct node{
    int s;
    int money;
};
node my_states[MAXN];

struct cmp{
    bool operator () (const int &a, const int &b){
        return my_states[a].s > my_states[b].s;
    }
};

void work(){
    my_states[0].s = 0;
    my_states[0].money = K;
    priority_queue<int, vector<int> , cmp> Q;
    Q.push(0);
    int cur, next,cur_money;
    int ans = -1;
    while(!Q.empty()){
        cur = Q.top();
        Q.pop();
        //cout<<"cur is "<<cur<<" and money:"<<my_states[cur].money<<endl;
        if(cur==N-1){
            ans = my_states[cur].s; 
            break;
        }
        open[cur] = 0;
        //closed[cur] = 1;
        cur_money = my_states[cur].money; 
        int sz = g[cur].size();
        for(int i=0; i<sz; i++){
            next = g[cur][i].first;
            if(closed[next]){
                continue;
            }
            if(cur_money - g[cur][i].second.second<0){
                continue;
            }
            int tentative = my_states[cur].s+g[cur][i].second.first;
            bool tentative_is_better = false;
            if(open[next]==0){
                open[next]=1;
                tentative_is_better=true;
            }else if(tentative < my_states[next].s){
                tentative_is_better=true;
            }
            if(tentative_is_better){
                my_states[next].s = tentative;
                my_states[next].money = cur_money - g[cur][i].second.second;
                Q.push(next);
                //cout<<"cur: "<<cur<<" -> next: "<<next<<endl;
            }
        }
    }
    cout<<ans<<endl;
}

int main(){
    cin>>K;
    cin>>N;
    cin>>R;
    for(int i=0; i<R; i++){
       int a,b,c,d;
       cin>>a>>b>>c>>d;
       a--,b--;
       g[a].push_back( pair<int, mypair>(b,mypair(c,d)) );
    }
    work();
    return 0;
}