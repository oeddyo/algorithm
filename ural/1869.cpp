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

const int MAXN = 105;
int data[MAXN][MAXN];
int N;

void trans(){
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            swap(data[i][j], data[j][i]);
        }
    }
}

bool single_ride(int car){
    int n_cur = 0;
    for(int row=0; row<N; row++){
        for(int i=row+1; i<N; i++){
            n_cur += data[row][i];
        }
        for(int i=row-1; i>=0; i--){
            n_cur -= data[i][row];
        }
        if(n_cur > car*36){
            return false;
        }
    }
    return true;
}


bool judge(int car){
    bool ok=false;
    if(single_ride(car)){
        trans();
        if(single_ride(car)){
            ok = true;
        }
            trans(); 
    }
    if(ok)return true;
    return false;
}


void work(){
    int car = 10;
    //cout<<car<<" "<<judge(car)<<endl;

    int low = 0, high = 100000000;

    int ans = -1;
    while(low<high){
        //cout<<"low "<<low<<" high "<<high<<endl;
        int mid = (high+low)/2;
        if(judge(mid)){
            ans = mid;
            high = mid;
        }else{
            low = mid+1;
        }
    }
    cout<<ans<<endl;

}


int main(){
   
    cin>>N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>data[i][j];
        }
    }
    work();



    return 0;
}

