#include <iostream>
#include <cmath>
#include <string.h>
#include <queue>
#include <iomanip>      // std::setprecision

using namespace std;

double fs, gs;
const int MAXN = 2000;

int N;
double loc[MAXN][2];

double graph[MAXN][MAXN];

double euc_dis(double lat1, double lng1, double lat2, double lng2){
    return sqrt((lat1-lat2)*(lat1-lat2) + (lng1-lng2)*(lng1-lng2));
}


double dis[MAXN];
bool visited[MAXN];
double tmp[MAXN];
int track[MAXN];
const double INF = 99999999999.9;

void dij(int start, int end){
    for(int i=0; i<MAXN; i++){
        dis[i] = INF;
    }
    memset(visited, 0, sizeof(visited));

    dis[start] = 0;
    track[0] = -1;

    while(1){
        double t = INF;
        int cur = -1;
        for(int i=0; i<=N+1; i++){
            if(dis[i]<t && visited[i]==false){
                cur = i;
                t = dis[i];
            }
        }
        if(cur==-1)break;

        int update_from = -1;
        for(int i=0; i<MAXN; i++){
            if(graph[cur][i]!=INF && visited[i]==false && dis[cur]+graph[cur][i] < dis[i]){
                dis[i] =  dis[cur] + graph[cur][i];
                update_from = i;
                track[i] = cur;
            }
        }
        visited[cur] = true;

    }


    vector<int> ans;
    int pos = end;
    while(pos!=-1){
        ans.push_back(pos);
        pos = track[pos];
    }

    cout<<setprecision(8)<<fixed<<dis[end]<<endl;
    cout<<ans.size()-2;
    for(int i=ans.size()-2; i>=1; i--){
        cout<<" "<<ans[i];
    }
    cout<<endl;
}


void work(){
    dij(0, N+1);
}

int main(){

    cin>>fs>>gs;
    cin>>N;

    for(int i=0; i<MAXN; i++){
        for(int j=0; j<MAXN; j++){
            graph[i][j ] = INF;
        }
    }

    for(int i=1; i<=N; i++){
        cin>>loc[i][0]>>loc[i][1];
    }

    while(1){
        int from, to;
        cin>>from>>to;

        if(from==0 && to==0)break;

        graph[from][to] = graph[to][from] = euc_dis(loc[from][0], loc[from][1], loc[to][0], loc[to][1])/gs;


    }

    cin>>loc[0][0]>>loc[0][1];
    cin>>loc[N+1][0]>>loc[N+1][1];

    for(int i=0; i<=N+1; i++){
        for(int j=0; j<=N+1; j++){
          graph[i][j] = graph[j][i] = min(euc_dis(loc[i][0], loc[i][1], loc[j][0], loc[j][1])/fs, graph[j][i]);
        }
        //graph[0][i] = graph[i][0] = euc_dis(loc[0][0], loc[0][1], loc[i][0], loc[i][1])/fs;
        //graph[N+1][i] = graph[i][N+1] = euc_dis(loc[N+1][0], loc[N+1][1], loc[i][0], loc[i][1])/fs;
    }




    /*
    for(int i=0; i<=N+1; i++){
        cout<<"node "<<i<<endl;
        for(int j=0; j<=N+1; j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    work();



    return 0;
}
