#include <iostream>
#include <string.h>

using namespace std;
int N,M,a,b,c,p,r;
struct road{
    int from, to, at, p,r;
};
road my_roads[20];
int dp[11][1<<11][15];;
int g[11][11];
const int INF = 999999999;

void print_bin(int p,int k){
    if(p<=0){
        return ;
    }
    print_bin(p-1,k>>1);
    cout<<k%2;
}

void work(){
    for(int i=0; i<11; i++){
        for(int j=0; j<(1<<11); j++){
            for(int k=0; k<15; k++){
                dp[i][j][k]=INF;
            }
        }
    }

    dp[0][0][0] = 0;

    for(int k=0; k<M; k++){
        for(int i=0; i<N; i++){
            for(int s= 0; s<(1<<M)-1; s++){
                if(dp[i][s][k]==INF){
                    continue;
                }
                //cout<<"dp["<<i<<"][";
                //print_bin(5,s);
                //cout<<"]["<<k<<"] = "<<dp[i][s][k]<<endl;
                //buy roads
                int ns = 0;
                for(int j=0; j<M; j++){
                    //buy all the roads at city i
                    if(my_roads[j].at == i){
                        if( ((s>>j)&1) == 0){
                            ns = (1<<j)|s;
                            dp[i][ns][k] = min(dp[i][ns][k], dp[i][s][k]+my_roads[j].p);
                        }
                    }
                }
                for(int j=0; j<M; j++){
                    //go to another city and buy the road
                    if(i==my_roads[j].from){
                        if(((s>>j)&1)==0){
                            ns = (1<<j)|s;
                            dp[i][ns][k] = min(dp[i][ns][k], dp[i][s][k]+my_roads[j].r);
                        }
                    }
                }

                //now go
                for(int j=0; j<M; j++){
                    if( ((s>>j)&1) ==1){
                        if(i==my_roads[j].from){
                            dp[my_roads[j].to][s][k+1] = min(dp[my_roads[j].to][s][k], dp[i][s][k]);
                        }
                    }
                }

            }
        }
    }
    int ans = INF;


    for(int i=0; i<((1<<M)-1); i++){
        for(int k=0; k<M; k++){
            //cout<<i<<" "<<k<<endl;
            //cout<<"dp["<<N-1<<"][";
            //print_bin(5,i);
            //cout<<"]["<<k<<"] = "<<dp[N-1][i][k]<<endl;
            if(dp[N-1][i][k] < ans){
                ans = dp[N-1][i][k];
            }
        }
    }
    if(ans==INF){
        cout<<"impossible"<<endl;
    }else{
        cout<<ans<<endl;
    }
}


int main(){
    cin>>N>>M;
    memset(g,0,sizeof(g));
    for(int i=0; i<M; i++){
        cin>>a>>b>>c>>p>>r;
        a--,b--,c--;
        g[a][b] = 1;
        my_roads[i].from = a, my_roads[i].to = b, my_roads[i].at = c, my_roads[i].p = p, my_roads[i].r = r;
    }

    work();
    return 0;
}

