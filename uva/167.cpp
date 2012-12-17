#include <iostream>
#include <cmath>
#include <iomanip>
#include <string.h>
using namespace std;

int data[8][8], K, ans = -1;
bool used[8];
int col[8];
void dfs(int cur, int sum){
    if(cur==8){
        ans = max(sum,ans);
        return ;
    }
    for(int i=0; i<8; i++){
        //iterate all the columns
        if(used[i])continue;
        bool ok = true;
        for(int j=0; j<cur; j++){
            int x = j, y = col[j];
            if( abs(cur-x) == abs(y-i)){
                ok = false;
                break;
            }
        }
        if(ok){
            used[i] = true;
            col[cur] = i;
            dfs(cur+1, sum+data[cur][i]);
            used[i] = false;
            col[cur] = -1;
        }
    }
}

void work(){
    memset(used,0,sizeof(used));
    memset(col, -1, sizeof(col));
    ans = -1;
    dfs(0, 0);
    cout<<setw(5)<<ans<<endl;
}

int main(){
    cin>>K;
    for(int i=0; i<K; i++){
        for(int a = 0; a<8; a++)for(int b=0; b<8; b++)cin>>data[a][b];
        work();
    }
    return 0;
}

