#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
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
int d1, d2, m; 

vector<int> ans;

bool can_work(int upper){
    ans.clear();
    int tmp = m*d1;
    for(int i=0; i<d2; i++){
        if(tmp <= 0){
            ans.push_back(0);
        }else if(tmp > 0 && tmp < upper){
            ans.push_back(tmp);
            tmp -= tmp;
        }else{
            ans.push_back(upper); 
            tmp -= upper;
        }
    }
    //cout<<"now tmp = "<<tmp<<endl;
    if(tmp<=0)return true;
    return false;
}




int main(){
    cin>>m>>d1>>d2;
   

    int lower = 1, upper = 100000010, mid;
    int ok = -1;
    while(lower<upper){
        mid = (lower + upper)/2;
        //cout<<lower<<" "<<upper<<" "<<mid<<endl;
        bool can = can_work(mid);
        if( can  ){
            ok = mid;
            upper = mid;
        } else{
            lower = mid + 1;
        }
    }
    can_work(ok);
    for(int i=0; i<ans.SZ-1; i++){
        cout<<ans[i]<<" ";
    }cout<<ans[ans.SZ-1]<<endl;

    return 0;
}

