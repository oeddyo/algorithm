#include <iostream>
#include <queue>
#include <string.h>
#include <map>
using namespace std;

int K,N,R;
typedef pair<int,int> mypair;

const int MAXN = 101;
const int INF = 999999999;
bool open[MAXN];
bool closed[MAXN];

vector < pair<int, mypair> > g[MAXN];
typedef struct mynode{
    int s;
    int money;
    int id;
    bool operator < (const mynode &a) const{
        return a.s > s;
    }

}node;

void work(){
    priority_queue<node> Q;
    node start;
    start.s = 0, start.money = K, start.id = 0;
    Q.push(start);
    node cur, next;
    int ans = INF,cur_money, next_money;
    while(!Q.empty()){
        cur = Q.top();
        Q.pop();
       // cout<<"now id is "<<cur.id<<endl;
        if(cur.id==N-1){
            ans = min(ans,cur.s);
        }
        int sz = g[cur.id].size();
        cur_money = cur.money;
        //cout<<"current money is "<<cur_money<<endl;
        for(int i=0; i<sz; i++){
            //cout<<"will cost "<<g[cur.id][i].second.second<<endl;
            next_money = cur_money - g[cur.id][i].second.second;
//            cout<<"seeing "<<g[cur.id][i].first<<" with money "<<next_money<<endl;
            if(next_money<0)continue;
            next.id = g[cur.id][i].first;;
            next.money = next_money;
            next.s = cur.s + g[cur.id][i].second.first;
            Q.push(next);
        }
    }
    if(ans==INF){
        cout<<"-1"<<endl;
    }else{
        cout<<ans<<endl;
    }
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
