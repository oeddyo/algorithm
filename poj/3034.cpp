#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#define INF 99999999

using namespace std;

typedef pair<int, int> mypair;
int n,d,m,max_t;

vector< mypair > M[11];
int sz[11];
int dp[11][36][36];
int map[11][36][36];

bool in_range(int &x, int &y, int &a, int &b){
    if((x-a)*(x-a)+(y-b)*(y-b) <=d*d){
        return true;
    }
    return false;
}

int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}

int get_mole_number(int t, int x,int y, int i, int j){
    if(x==i&&y==j){
        if(map[t][x][y]!=0){
            return 1;
        }else{
            return 0;
        }
    }
    int xm, ym;
    int g = gcd(abs(x-i),abs(y-j));
    if(x<i){
        xm = abs(x-i)/g;
    }else{
        xm = -abs(x-i)/g;
    }
    if(y<j){
        ym = abs(y-j)/g;
    }else{
        ym = -abs(y-j)/g;
    }
    int sum=0,tx,ty;
    for(int k=0; k<=g; k++){
        tx = x+xm*k;
        ty = y+ym*k;
        if(map[t][tx][ty]!=0){
            sum++;
        }
    }
    return sum;
}

int get_ans(int t, int x, int y){
    if(t==0){
        return 0;
    }
    if(dp[t][x][y]!=-1)return dp[t][x][y];
    int tmp_max = -INF;
    for(int i=x-d; i<=x+d; i++){
        for(int j=y-d; j<=y+d; j++){
            if(i<0 || i>=n || j<0 || j>=n)continue;
            if(!in_range(x,y,i,j)){
                continue;
            }
            int sum=0;
            sum = get_mole_number(t, x , y , i, j);
            int t_ans = get_ans(t-1, i, j);
            tmp_max = max(tmp_max, sum+t_ans);
        }
    }
    dp[t][x][y] = tmp_max;
    return tmp_max;
}


void work(){
    memset(dp,-1,sizeof(dp));
    int ans = -INF;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans = max(ans, get_ans(max_t,i,j));
        }
    }
    cout<<ans<<endl;
}

int main(){
    while(scanf("%d %d %d",&n,&d,&m)!=EOF){
        if(n==d && d==m && m==0){
            break;
        }
        int x,y,t;
        for(int i=0; i<11; i++)M[i].clear();
        memset(map,0,sizeof(map));
        for(int i=0; i<m; i++){
            scanf("%d %d %d",&x,&y,&t);
            x+=15, y+=15;
            M[t].push_back(mypair(x,y));
            max_t = max(max_t, t);
            map[t][x][y]=1;
        }
        n+=15;
        for(int i=1; i<=max_t; i++)sz[i] = M[i].size();
        work();
    }
    return 0;
}

