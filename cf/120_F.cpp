#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <fstream>

using namespace std;

int T, N;
const int MAXN = 105;
vector<int> G[MAXN];
bool visited[MAXN];

typedef pair<int, int> pii;

int work(){
    int cur_max_dis = 0;
    for(int start=0; start<N; start++){
        memset(visited, 0, sizeof(visited));
        queue< pii > Q;
        pii init(start, 0);
        Q.push(init);
        while(!Q.empty()){
            pii cur = Q.front();
            Q.pop();
            cur_max_dis = max(cur_max_dis, cur.second);
            visited[cur.first] = 1;
            int sz = G[cur.first].size();
            for(int i=0; i<sz; i++){
                int next = G[cur.first][i];
                if(visited[next]==false){
                    pii next_node(next, cur.second+1);
                    Q.push(next_node);
                }
            }
        }
    }
    return cur_max_dis;
}


int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt"); 
    fin>>T;
    int ans = 0;
    for(int spider = 0; spider <T; spider++){
        fin>>N;
        for(int i=0; i<MAXN; i++){
            G[i].clear();
        }

        for(int i=0; i<N-1; i++){
            int a, b;
            fin>>a>>b;
            a--,b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        //cout<<"ready "<<endl;
        int cur = work();
        ans += cur;
    }
    fout<<ans<<endl;

    return 0;
}

