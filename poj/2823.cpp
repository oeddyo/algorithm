#include <iostream>
#include <queue>

#define MAXN 1000002
using namespace std;

typedef pair<int, int> mypair;
priority_queue<mypair, vector<mypair>, greater<mypair> > min_heap;
priority_queue<mypair, vector<mypair>, less<mypair> > max_heap;

int N,K, data[MAXN];
int max_ans[MAXN], min_ans[MAXN];
int cnt_max=0, cnt_min = 0;
void work(){
    for(int i=0; i<K-1; i++){
        min_heap.push(mypair( data[i], i));
        max_heap.push(mypair( data[i], i));
    }
    for(int i=K-1; i<N; i++){
        min_heap.push(mypair(data[i],i));
        max_heap.push(mypair(data[i],i));
        while(1){
            mypair t = max_heap.top();
            if(t.second + K > i){
                max_ans[cnt_max++] = t.first;
                break;
            }else{
                max_heap.pop();
                continue;
            }
        }
        while(1){
            mypair t = min_heap.top();
            if(t.second + K > i){
                min_ans[cnt_min++] = t.first;
                break;
            }else{
                min_heap.pop();
                continue;
            }
        }
    }
    for(int i=0; i<cnt_min-1; i++){
        printf("%d ",min_ans[i]);
    }
    printf("%d\n",min_ans[cnt_min-1]);
    for(int i=0; i<cnt_max-1; i++){
        printf("%d ",max_ans[i]);
    }
    printf("%d\n",max_ans[cnt_max-1]);
}

int main(){
    scanf("%d %d",&N,&K);
    for(int i=0; i<N; i++)scanf("%d",&data[i]);
    work();
return 0;
}

