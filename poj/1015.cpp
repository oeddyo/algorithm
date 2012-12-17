#include <iostream>
#include <vector>
using namespace std;

int n,m;
const int MAXN = 205;
int d[MAXN][3];
const int MMAX = 1000;
const int INF = 999999999;
bool dp[MAXN][21][MMAX];
int magic = 500;
int dp_cnt[MAXN][21][MMAX];
int rec[MAXN][21][MMAX][2];

typedef struct n{
    int i,j,k;
}node;
node pre[MAXN][21][MMAX];

void work(){
    for(int i=0; i<MAXN; i++)for(int j=0; j<21; j++)for(int k=0; k<MMAX; k++){
        dp[i][j][k]=0;
        dp_cnt[i][j][k]=-INF;
        pre[i][j][k].i = -1, pre[i][j][k].j = -1, pre[i][j][k].k=-1;
    }


    for(int i=0; i<=n; i++){
        dp[i][0][magic]=1;
        dp_cnt[i][0][magic] = 0;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m&&j<=i; j++){
            for(int k=0; k<MMAX; k++){
                int t = k-d[i][2];
                if(t>=0&&t<MMAX&&dp[i-1][j-1][t]){
                    dp[i][j][k] = 1;
                    if(dp_cnt[i-1][j-1][t]+d[i][0]+d[i][1] > dp_cnt[i][j][k]){
                        dp_cnt[i][j][k] = dp_cnt[i-1][j-1][t]+d[i][0]+d[i][1];
                        rec[i][j][k][0] = rec[i-1][j-1][t][0]+d[i][0];
                        rec[i][j][k][1] = rec[i-1][j-1][t][1]+d[i][1];
                    }
                    pre[i][j][k].i = i-1;
                    pre[i][j][k].j = j-1;
                    pre[i][j][k].k = t;
                }
                if(dp[i-1][j][k]){
                    dp[i][j][k]=1;
                    if(dp_cnt[i-1][j][k] > dp_cnt[i][j][k]){
                        dp_cnt[i][j][k] = dp_cnt[i-1][j][k];
                        rec[i][j][k][0] = rec[i-1][j][k][0];
                        rec[i][j][k][1] = rec[i-1][j][k][1];
                    }
                    pre[i][j][k].i = i-1;
                    pre[i][j][k].j = j;
                    pre[i][j][k].k = k;
                }
                if(dp[i][j][k])    
                {
                    cout<<i<<" "<<j<<" "<<k-magic<<" ok "<<endl;
                    cout<<"now cnt "<<dp_cnt[i][j][k]<<endl;
                }
            }
        }
    }

    int ans = INF;
    int cnt_sum = -INF;
    int sum_a, sum_b;
    int k_pos = -1;

    for(int i=1; i<=n; i++){
        for(int k=0; k<MMAX; k++){
            if(dp[n][m][k]){
                if(abs(k-magic)<ans){
                    cout<<n<<" "<<m<<" "<<k<<endl;
                    ans = abs(k-magic);
                    sum_a = rec[n][m][k][0];
                    sum_b = rec[n][m][k][1];
                    k_pos = k;
                }else if(abs(k-magic)==ans){
                    if(dp_cnt[n][m][k]>cnt_sum){
                        cnt_sum = dp_cnt[n][m][k];
                        sum_a = rec[n][m][k][0];
                        sum_b = rec[n][m][k][1];
                        k_pos = k;
                    }
                }
            }
        }
    }
    cout<<"k_pos is "<<k_pos<<endl;

    vector<int> ans_list;
    int i = n, j=m, k = k_pos;
    while(i!=-1 && j!=-1 && k!=-1){
        cout<<i<<" "<<j<<" "<<k-magic<<endl;
        ans_list.push_back(i);
        int t_i = pre[i][j][k].i;
        int t_j = pre[i][j][k].j;
        int t_k = pre[i][j][k].k;
        i = t_i, j=t_j, k=t_k;
    }
    for(int i=0; i<ans_list.size(); i++){
        cout<<ans_list[i]<<" ";
    }cout<<endl;
    cout<<ans<<endl;
    cout<<sum_a<<" "<<sum_b<<endl;
}


int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>d[i][0]>>d[i][1];
        d[i][2] = d[i][0]-d[i][1];
    }
    work();

    return 0;
}

