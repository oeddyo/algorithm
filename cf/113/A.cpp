#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> mypair;

vector <mypair> P;

bool compare(const mypair &a, const mypair &b){
    if(a.first==b.first){
        return a.second>b.second;
    }else{
        return a.first<b.first;
    }
}



int n,k;
int main(){
    cin>>n>>k;
    int a,b,c;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        P.push_back(mypair(a,b));
    }
    sort(P.rbegin(), P.rend(),compare);
    int ans=0;
    for(int i=0; i<n; i++){
        if(P[i].first==P[k-1].first && P[i].second==P[k-1].second){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
