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

const int MAXN = 1000005;
int A[MAXN];
int B[MAXN];
int ans[MAXN];
int N;


int main(){
    cin>>N;

    for(int i=0; i<N; i++){
        cin>>A[N-i-1]>>B[N-i-1];
    }
    

    
    int more=0;
    for(int i=0; i<N; i++){
        int c = A[i] + B[i] + more;
        if(c>=10){
            ans[i] = c%10;
            more = 1;
        }else{
            ans[i] = c;
            more = 0;
        }
    
    }

    for(int i=N-1; i>=0; i--){
        cout<<ans[i];
    }cout<<endl;


    return 0;
}

