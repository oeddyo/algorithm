#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
using namespace std;
 

typedef long long ll;
typedef struct my_node{
    ll x, y;
}point;

const int MAXN = 10500;
point points[MAXN];
int N;

vector< point > ans;


void proc( int n_points, vector< ll > pp){
    if(n_points == 0)return ;
    if(n_points == 2){
        point tmp;
        tmp.x = pp[0];
        tmp.y = pp[1];
        ans.push_back(tmp); 
        return ;
    }

    int sz = pp.size();
   
    vector<ll> left;
    vector<ll> right;

    int ls =0, rs = 0, a, b;
    while(1){
        a = rand()%sz;
        b = rand()%sz;
        if(a == b)b = (a+1)%sz;

        left.clear(); right.clear();

        //cout<<"a = "<<a<<" b = "<<b<<endl;
        
        ll x1 = points[pp[a]].x;
        ll y1 = points[pp[a]].y;
        ll x2 = points[pp[b]].x;
        ll y2 = points[pp[b]].y;
        ls = 0, rs = 0;

        for(int i=0; i<sz; i++){
            //cout<<"i = "<<i<<endl;
            if(i==a || i==b)continue;

            ll x = points[pp[i]].x;
            ll y = points[pp[i]].y;

            //cout<<(y-y1)<<" "<<(x2-x1)<<endl;
            ll _tmp = (y-y1)*(x2-x1) - (y2-y1)*(x-x1);
            if( _tmp > 0LL){
                left.push_back(pp[i]);
                ls += 1;
            }else if(_tmp < 0LL) {
                right.push_back(pp[i]);
                rs += 1;
            }
        }
        //cout<<ls<<" "<<rs<<endl;
        if( rs%2 == 1 || ls%2 == 1)continue;
        //cout<<"ok"<<endl;
        break;
    }
    
    point tmp;
    tmp.x = pp[a];
    tmp.y = pp[b];
    
    ans.push_back(tmp);
    
    proc(left.size(), left);
    proc(right.size(), right);
}


void work(){
    vector<ll> tmp;
    for(int i=0; i<N; i++){
        tmp.push_back(i);
    }

    proc(tmp.size(),  tmp ); 
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i].x+1<<" "<<ans[i].y+1<<endl;
    }
    ans.clear();

}




int main(){

    while(cin>>N){

        for(int i=0; i<N; i++){
            cin>>points[i].x>>points[i].y;
        }
        work(); 
    }

    return 0;
}

