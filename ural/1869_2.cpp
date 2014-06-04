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
const int INF = 999999999;
int data[MAXN][MAXN];
int N;

void trans(){
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            swap(data[i][j], data[j][i]);
        }
    }
}

int single_ride(){
    int n_cur = 0;
    int ans = -INF;

    for(int row=0; row<N; row++){
        for(int i=row+1; i<N; i++){
            n_cur += data[row][i];
        }
        for(int i=row-1; i>=0; i--){
            n_cur -= data[i][row];
        }
        if(n_cur > ans*36){
            if(n_cur%36==0){
                ans = n_cur/36;
            }else{
                ans = n_cur/36 + 1;
            }
        }
    }
    return ans;
}


int judge(){
    int ans = -INF;
    int ans1 = single_ride();
    trans();
    int ans2 = single_ride();
    return max(ans1, ans2);
}


void work(){
    cout<<judge()<<endl;
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

