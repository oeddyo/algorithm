/*
ID: xieke.b1
PROB: cowtour
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <stack>
#include <vector>
#include <string.h>
#include <cmath>
#include <iomanip>

using namespace std;
ifstream fin("cowtour.in");
ofstream fout("cowtour.out");

const double INF = 999999999;
typedef pair<int, int> pii;

const int MAXN = 160;
vector< pii > points;

int N;
string graph[MAXN];
double g[MAXN][MAXN];


double compute(int i, int j){
    
    /*
    double t1 = points[i].first-points[j].first;
    double t2 = points[i].second-points[j].second;
    return sqrt(t1*t1+t2*t2);
    */
    return sqrt(((double)points[i].first - points[j].first)*(points[i].first-points[j].first) + ((double)points[i].second-points[j].second) *(points[i].second - points[j].second));

}

void build_graph(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(graph[i][j]=='1'){
                g[i][j] = compute(i,j);
            }else{
                g[i][j] = INF;
            }
            if(i==j)g[i][j] = 0.0;
        }
    }
}

double dp[MAXN][MAXN];

void floyd(){
    for(int i=0; i<N; i++)for(int j=0; j<N; j++)dp[i][j] = g[i][j];
    //cout<<"before"<<endl;
    for(int k=0; k<N; k++){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                dp[i][j] = min( dp[i][k]+dp[k][j], dp[i][j]);
            }
        }
    }
    //cout<<"after"<<endl;
}

int color[MAXN];
bool vis[MAXN];
void dfs(int cur, int col){
    if(vis[cur])return ;
    vis[cur] = 1;
    color[cur] = col;
    for(int i=0; i<N; i++){
        if(graph[cur][i]=='1'){
            dfs(i, col);
        }
    }


}


void work(){
    memset(vis,0,sizeof(vis));
    int color_num = 1;    
    for(int i=0; i<N; i++){
        if(vis[i]==0){
            dfs(i, color_num);
            color_num ++;
        }
    }
    for(int i=0; i<N; i++){
        cout<<color[i]<<" ";
    }cout<<endl;

    build_graph();
    floyd();
    
    double ans = INF;
    double within = -INF;
    for(int i=0; i<N; i++){
        //cout<<dp[i][i]<<endl;
        for(int j=0; j<N; j++){
            if(dp[i][j]!=INF && within<dp[i][j]){
                within = dp[i][j];
            }
        }
    }
    cout<<"ans initial "<<within<<endl;

    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            if(i==j || color[i] == color[j] || graph[i][j]=='1' ){
                continue;
            }
            //connect i, j
            double tmp_max = -INF;
            double dis = compute(i,j);
            for(int a=0; a<N; a++){
                for(int b=0; b<N; b++){
                    //if(color[a] == color[b] )continue;
                    if(color[a] == color[i] && color[b] == color[j]){
                        if( dp[a][i]!=INF && dp[j][b]!=INF){
                            //if(dp[a][i]+dis+dp[j][b]>=39000)
                            //cout<<a<<"&"<<b<<" "<<i<<"&"<<j<<"-> "<<dp[a][i]+dis+dp[j][b]<<endl;
                            //ans = max( ans, dp[a][i]+dis+dp[j][b]);
                            tmp_max = max(max(tmp_max, dp[a][i]+dis+dp[j][b]), within);
                        }
                    }
                }
            }
            //cout<<tmp_max<<endl;
            ans = min(ans, tmp_max);
        }
    }

   
   /* 
    cout<<"**************"<<endl;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<dp[i][j]<<"\t";
        }cout<<endl;
    }
    cout<<"**************"<<endl;
    */
    fout.precision(6);
    fout.setf(ios::fixed, ios::floatfield);
    fout<<ans<<endl;
    //fout<<precision(6)<<fixed<<ans<<endl; 
}


int main(){
    fin>>N;
    for(int i=0; i<N; i++){
        int x,y;
        fin>>x>>y;
        points.push_back( pii(x,y));
    }
    for(int i=0; i<N; i++){
        fin>>graph[i];
        //cout<<graph[i]<<endl;
    }
    work();


    return 0;
}

