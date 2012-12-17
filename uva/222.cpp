#include <iostream>

using namespace std;

const int MAXN = 52;
double dis[MAXN], D;
double price[MAXN];
int K;
double ans;
const double INF = 99999999;

double mpg, cost_original, g_p;

bool dfs(double cur_dis, int cur_pos, double money, double gas){
    if(cur_pos == K){
        ans = min(ans, money);
        return true;
    }
    cout<<"now  at "<<cur_pos<<" money is "<<money<<" "<<gas<<endl;
    for(int i=cur_pos+1; i<=K; i++){
        if(gas*mpg>= dis[i] - cur_dis){
            double gas_left = gas - (dis[i]-cur_dis)/mpg;
            if(gas_left < g_p/2 || (gas_left>g_p/2 && i+1<=K-1 && gas_left*mpg<dis[i+1]-dis[i])){
                dfs(dis[i], i, money+(g_p-gas)*price[i]+200, g_p);
            }
            /*
            if(gas_left > g_p/2 ){
                if((i+1<=K-1 && gas_left*mpg<dis[i+1]-dis[i])){

                }
            }
            */
        }
    }
}

void work(){
    ans = INF;
    dfs(0,-1, cost_original*100, g_p);
    cout<<ans<<endl;
}

int main(){
    while(cin>>D){
        cin>>g_p>>mpg>>cost_original>>K;
        for(int i=0; i<K; i++){
            cin>>dis[i]>>price[i];
        }
        price[K] = 0, dis[K] = D; 
        work();
    }
    return 0;
}

