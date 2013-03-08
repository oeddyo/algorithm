#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef pair<int, int> pii; 

const int MAXN = 100001;
const int INF = 999999999;
pii d[MAXN];
int N;

bool mycmp(const pii & a, const pii & b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    return a.second<b.second;
}

void work(){
    int ans = 0;
    int cur = -INF;
    for(int i=0; i<N; i++){
        if(cur+1<=d[i].first){
            cur = d[i].second;
            ans+=1;
        }
    }
    cout<<ans<<endl;

}


int main(){
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        scanf("%d %d",&d[i].first, &d[i].second);
    }
    sort(d,d+N,mycmp);
    /*
    for(int i=0; i<N; i++){
        cout<<d[i].first<<" "<<d[i].second<<endl;
    }
    */

    work();


    return 0;
}

