#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
using namespace std;

int N;
char data[21][21];
bool used[21][21];

int dir[21][21][8];
int dir_cnt[21][21];
typedef pair<int, int> pii;
typedef pair<int, pii > piii;

vector< pair<int, string> > ans;

int my_d[8][2] = {{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{-1,1},{1,-1},{1,1}};

bool check(int i, int j){
    if(i>=0 && i<N && j>=0 && j<N){
        return true;
    }
    return false;
}
void search_direction(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N;j++){
            int cnt = 0;
            vector< pii > t_v;
            for(int k=0; k<8; k++){
                int nx = i+my_d[k][0];
                int ny = j+my_d[k][1];
                if(check(nx, ny)&&data[i][j]<data[nx][ny]){
                    cnt++;
                    //cout<<"at "<<i<<" "<<j<<" could go to "<<nx<<" "<<ny<<endl;
                    t_v.push_back( pii(data[nx][ny]-'a', k));
                }
            }
            sort(t_v.begin(), t_v.begin()+cnt);
            dir_cnt[i][j] = cnt;
            for(int k=0; k<cnt; k++){
                dir[i][j][k] = t_v[k].second;
            }
        }
    }
}
void dfs(int x, int y, int len, string s){
    if(len>=3){
        ans.push_back(pair<int, string>(len, s));
    }
    for(int i=0; i<dir_cnt[x][y]; i++){
        int nx = x+my_d[dir[x][y][i]][0];
        int ny = y+my_d[dir[x][y][i]][1];
        //cout<<nx<<" "<<ny<<endl;
        if(used[nx][ny]==false){
            used[nx][ny]=true;
            dfs(nx,ny,len+1, s+data[nx][ny]);
            used[nx][ny]=false;
        }
    }
}

void work(){
    ans.clear();
    search_direction();
    memset(used,0,sizeof(used));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            string tt = "";
            tt+=data[i][j];
            dfs(i,j,1, tt);
        }
    }
    sort(ans.begin(), ans.end());
    int sz = ans.size();
    string pre = "";
    for(int i=0; i<sz; i++){
        if(ans[i].second!=pre){
            pre = ans[i].second;
            cout<<ans[i].second<<endl;
        }
    }
}

int main(){
    int T;
    cin>>T;
    int blank = 0;
    while(T--){
        if(blank>=1){
            cout<<endl;
        }
        blank++;
        cin>>N;
        for(int i=0; i<N; i++){
            cin>>data[i];
        }
        work();
    }
    return 0;
}

