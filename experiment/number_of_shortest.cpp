#include <iostream>
#include <vector>
#include <queue>

using namespace std;


const int MAXN = 100;
typedef pair<int, int> pii;

vector< int> G[MAXN];

bool visited[MAXN];
int cnt[MAXN];

void work(){
    queue< pii > Q;

    Q.push( pii(0, 1) );
    memset(cnt, 0, sizeof(cnt));
    visited[0] = 1;
    
    while(1){
        queue< pii > _tmp;
        vector<int> mark;
        while(!Q.empty()){
            pii cur = Q.front();Q.pop();
            for(int i=0; i<G[cur.first].size(); i++){
                int next = G[cur.first][i];
                int v = cur.second;
                
                if(visited[next]==0){
                    _tmp.push( pii(next, v) );
                    cnt[next] += v;
                    mark.push_back(next);
                }
            }


        }
        for(int i=0; i<mark.size(); i++){
            visited[mark[i]] = 1;
        }
        
        if(_tmp.size() == 0)break;
        Q = _tmp;
        
        cout<<"-------------"<<endl;
        for(int i=0; i<=7; i++){
            cout<<i<<" "<<cnt[i]<<endl;
        }
    }

}

int main(){

    G[0].push_back(1);
    G[0].push_back(2);
    G[0].push_back(3);
    G[1].push_back(2);
    G[1].push_back(5);
    G[2].push_back(4);
    G[3].push_back(4);
    G[4].push_back(5);
    G[4].push_back(6);
    G[5].push_back(6);
    G[6].push_back(7);


    work();

    return 0;
}

