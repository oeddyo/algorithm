#include <iostream>
#include <queue>
#include <vector>

using namespace std;


int N, M;
const int MAXN = 10001;
int data[MAXN];


int main(){
    cin>>N>>M;

    priority_queue<int> max_Q;
    priority_queue<int, vector<int> , greater<int> > min_Q;

    for(int i=0; i<M; i++){
        int t;
        cin>>t;
        max_Q.push(t);
        min_Q.push(t);
    }
    int cnt = N;
    int max_ans = 0;
    int min_ans = 0;
    while(cnt--){
        int cur = max_Q.top();
        max_Q.pop();
        max_ans += cur;
        cur -= 1;
        if(cur>0){
            max_Q.push(cur);
        }
    }
    
    cnt = N;
    while(cnt--){
        int cur = min_Q.top();
        min_Q.pop();
        min_ans += cur;
        cur -= 1;
        if(cur>0){
            min_Q.push(cur);
        }
    }
    cout<<max_ans<<" "<<min_ans<<endl;

    return 0;
}

