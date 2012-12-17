#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int MAXN = 10000;
const int INF = 99999999;
long long int N;
int ans[MAXN];

int main(){
    cin>>N;
    if(N%2==1){
        cout<<-1<<endl;
        return 0;
    }else{
        for(int i=1; i<=N; i+=2){
            ans[i] = i+1;
            ans[i+1] = i;
        }
    }
    for(int i=1; i<N; i++){
        cout<<ans[i]<<" ";
    }
    cout<<ans[N]<<endl;

    return 0;
}

