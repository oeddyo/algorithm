#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int A,B,T;
int cnt = 0;
int primes[10000];


typedef struct mynode{
    int f,h,step;
    int num;
}node;
node states[10000];

struct cmp{
    bool operator () (const int &a, const int &b){
        if( states[a].f == states[b].f){
            return states[a].step > states[b].step;
        }else{
            return states[a].f > states[b].f;
        }
    }
};

void preprocess(){
    for(int i=1000; i<=9999; i++){
        bool is_prime = true;;
        for(int k=2; k*k<=i; k++){
            if(i%k==0){
                is_prime = false;
                break;
            }
        }
        if(is_prime){
            primes[i] = 1;
        }
    }
}

int get_h(int s){
    int t = B;
    int sum = 0;
    while(s){
        if(s%10 == t%10){
            sum++;
        }
        t/=10, s/=10;
    }
    return sum;
}



bool open[10000], closed[10000];
typedef pair<int, int> mypair;
void work(){
    memset(open,0,sizeof(open));
    memset(closed,0,sizeof(closed));
    priority_queue<int, vector<int> , cmp> Q;
    //mypair cur, next;
    open[A] = 1;
    Q.push(A);
    states[A].num = A, states[A].h = get_h(A), states[A].f = 0+states[A].h, states[A].step = 0;
    int cur, next, cur_number, next_number;
    int ans = -1;
    while(!Q.empty()){
        cur = Q.top();
        Q.pop();
        if(states[cur].num==B){
            ans = states[cur].step; 
            break;
        }
        open[cur] = 0;
        closed[cur] = 1;
        cur_number = states[cur].num;
        int tentative = 1 + states[cur].step,h;
        for(int i=1; i<=1000; i*=10){
            for(int j=0; j<=9; j++){
                //int number = states[next].num;
                int origi_num = (cur_number/i)%10;
                next_number = (cur_number - origi_num*i)+j*i;
                next = next_number;
                if((next_number>9999 && next_number<1000) || primes[next_number]==0  ){
                    continue;
                }
                if(closed[next_number]==1){
                    continue;
                }
                bool tentative_is_better;
                if(open[next_number]==0){
                    open[next_number]=1;
                    h = get_h(next_number);
                    states[next].h = h;
                    tentative_is_better=true;
                }else if(tentative<states[next].step){
                    tentative_is_better=true;
                }else{
                    tentative_is_better=false;
                }

                if(tentative_is_better){
                    states[next].f = tentative + h;
                    states[next].step = tentative;
                    states[next].num = next_number;
                    Q.push(next);
                }
            }
        }
    }
    if(ans==-1){
        cout<<"Impossible"<<endl;
    }else{
        cout<<ans<<endl;
    }
}

int main(){
    cin>>T;
    memset(primes,0,sizeof(primes));
    preprocess();
    while(T--){
        cin>>A>>B;
        work();
    }

    return 0;
}

