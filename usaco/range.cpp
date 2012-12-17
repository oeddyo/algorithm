/*
ID: xieke.b1
PROB: range
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string.h>
#include <cmath>

using namespace std;

ifstream fin("range.in");
ofstream fout("range.out");

typedef pair<int, int> pii;
const int MAXN = 251;
const int INF = 999999999;
bool sq[MAXN][MAXN];
bool dp[MAXN][MAXN][MAXN];
string t;
int N;

int sq_ans[MAXN];
bool vis[MAXN][MAXN];


void fill_right(int x, int y, int bound_x, int &bound_y){
    for(int i=x; i<=bound_x; i++){
        vis[i][bound_y+1] = 1;
    }
    bound_y+=1;
}
void fill_down(int x, int y, int &bound_x, int bound_y){
    for(int i=x; i<=bound_y; i++){
        vis[bound_x+1][i] = 1;
    }
    bound_x+=1;
}

void bfs(int &x, int &y){
    int bound_x=x, bound_y=y;
    
    while(1){
    cout<<"bound_x: "<<bound_x<<" bound_y: "<<bound_y<<endl;
    bool right_ok = true;
    if( bound_y + 1 <N){
        right_ok = true;
        for(int i=x; i<=bound_x; i++){
            if( vis[i][bound_y+1]==0 && sq[i][bound_y+1]==1){
                continue;
            }else{
                right_ok = false;break;
            }
        }
    }else{
        right_ok = false;
    }
    
    bool down_ok ;
    if( bound_x + 1 <N ){
        down_ok = true;
        for(int i=y; i<=bound_y; i++){
            if( vis[bound_x+1][i]==0 && sq[bound_x+1][i]==1 ){
                continue;
            }else{
                down_ok = false;
                break;
            }
        }
    }else{
        down_ok = false;
    }

    bool next_ok=false;
    if( bound_y + 1 <N && bound_x + 1 <N && sq[bound_x+1][bound_y+1]==1 && vis[bound_x+1][bound_y+1]==0 ){
        next_ok = 1;
    }
    cout<<"three values are "<<right_ok<<" "<<down_ok<<" "<<next_ok<<endl; 
    if( right_ok+down_ok==0){
        x = bound_x - x+1;
        y = bound_y - y+1;
        return ;
    }

    if( right_ok && down_ok && next_ok){
        fill_right(x,y,bound_x,bound_y);
        fill_down(x, y, bound_x, bound_y);
        vis[bound_x][bound_y] = 1;
    }else if( right_ok ){
        fill_right(x,y,bound_x, bound_y);
    }else if( down_ok ){
        fill_down(x,y,bound_x, bound_y); 
    }
        
    }

}

vector< pii > ans_pii;


/*
long long int cc[MAXN][MAXN];

long long int get_c(int n, int k){
    if(cc[n][k]!=-1)return cc[n][k];
    if(k==0){
        return 1;
    }
    long long left = get_c(n-1, k);
    long long right = get_c(n-1,k-1);
    cc[n][k] = left+right;
    return cc[n][k];
}
*/

long long int get_ans(){
    //memset(cc,-1,sizeof(cc));
    long long int final_ans = 0; 
    for(int i=0; i<ans_pii.size(); i++){
        int rows = ans_pii[i].first;
        int cols = ans_pii[i].second;
        for(int s = 2; s<=N; s++){
            if(s>rows || s>cols){
                break;
            }
            sq_ans[s] +=  (rows-s+1)*(cols-s+1) ;
        }
    }
    for(int i=0; i<N; i++){
        if(sq_ans[i]!=0){
            cout<<i<<" "<<sq_ans[i]<<endl;
        }
    }

    
    //return final_ans;
}

void work(){
    memset(sq_ans, 0, sizeof(sq_ans));
    memset(vis,0,sizeof(vis));

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(vis[i][j]==0 && sq[i][j]==1 ){
                int t_x = i;
                int t_y = j;
                bfs(t_x,t_y);
                cout<<"adding at position "<<i<<" "<<j<<" and get values "<<t_x<<" "<<t_y<<endl;
                if( t_x>=2 && t_y>=2)
                    ans_pii.push_back( pii(t_x, t_y) );
            }
        }
    }
    cout<<get_ans()<<endl;
}


int main(){
    fin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            char t;
            fin>>t;
            sq[i][j] = t-'0';
            cout<<sq[i][j];
        }cout<<endl;
    }
    work();
    return 0;
}

