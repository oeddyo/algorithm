#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <cmath>
#include <stack>
#include <map>
#include <set>
using namespace std;
 
#define DEBUG
#define REP(i,a) for(i=0;i<a;i++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define VE vector<int>
#define SZ size()
#define PB push_back

const int MAXN = 10001;
int n, m;
double p;

const double eps = 1e-9;

struct node{
    int p;
    int weight;
    int idx;
}L[MAXN];
int cmp(const struct node &a, const struct node &b){
    return a.p>b.p;
}

double ans[MAXN];
int ans_idx = 0;
void work(){
    
    std::cout.precision(15);
    std::cout<<std::fixed;

    sort(L, L+n, cmp);
    
    bool ok = true;
    if(L[0].p<p || L[n-1].p > p){
        ok = false;
    }
    
    double cur_p = 0, pure;
    int pos = -1, sum_weight = 0;

    ans_idx = 0;
    for(int i=0; i<n; i++){
        int w_sum = sum_weight + L[i].weight;
        pure = (sum_weight*cur_p + L[i].weight*L[i].p)*1.0/w_sum;
        //cout<<"now pure = "<<pure<<endl;
        if(pure - p < eps && sum_weight + L[i].weight>= m){
            pos = i;
            //cout<<"breaking "<<endl;
            break;
        }
        //ans.push_back( L[i].weight );
        ans[L[i].idx] = L[i].weight;
        ans_idx += 1;
        sum_weight += L[i].weight;
        cur_p = pure;
    }
    if(pos == -1){
        ok = false;
    }
    
    double add;
    if(fabs(p-L[pos].p) <= 0){
        add = L[pos].weight;
    }else{
        add = (cur_p - p)*1.0*sum_weight/(p-L[pos].p);
    }

    /*
    cout<<"sum_weight = "<<sum_weight<<endl;
    cout<<"melt = "<<melt_sum<<endl;
    */
    if(add + sum_weight < m){
        ok = false;
    }
    
    if(ok==false){
        cout<<"NO"<<endl;
        return ;
    }

    double melt_sum =  add;
    for(int i=0; i<ans_idx; i++){
        melt_sum += ans[i];
    }
    cout<<"YES"<<endl;
    for(int i=0; i<ans_idx; i++){
        double tmp = ans[i]*m*1.0/melt_sum;
         cout<<tmp<<endl;

    }
    cout<<add<<endl;
}



int main(){
    
    
    cin>>n>>m>>p;

        for(int i=0; i<n; i++){
            cin>>L[i].weight;
            cin>>L[i].p;
            //L[i].p/= 1000.0;
            p*= 1.0;
            L[i].idx = i;
        }
        work();
    return 0;
}

