#include <iostream>
#include <queue>
#include <stdio.h>
#include <map>
#include <set>
#include <vector>
#include <string.h>
using namespace std;

//string d;

int d[9];
typedef struct node{
    long long int state_int;
    short state[9];
    int f, step,p;
    int id;
}st;

st my_states[400000];

st start;

int get_f(short *state){
    int sh = 1;
    int sum = 0;
    for(int i=0; i<9; i++){
        if(state[i]!=sh){
            sum++;
        }
        sh++;
    }
    return sum;
}
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int path[400000];
int pre[400000];
int closed_table[400000];
int open[400000];
const int MAXN = 1000003;

typedef pair<int, long long int> mypair;
vector< mypair > h_table[MAXN];

int is_in(long long int k){
    int p = k%((long long int )MAXN);
    int sz = h_table[p].size();
    for(int i=0; i<sz; i++){
        if(h_table[p][i].second==k){
            return h_table[p][i].first;
        }
    }
    return -1;
}
void insert(long long int k, int cnt){
    int p = k%((long long int )MAXN);
    h_table[p].push_back(mypair(cnt, k));
}


long long int get_hash(short *a){
    long long int sum = 0;
    for(int i=0; i<9; i++){
        sum = sum*10+a[i];
    }
    return sum;
}

void print_state(node &a){
    for(int i=0; i<9; i++){
        cout<<a.state[i];
    }cout<<endl;
}
void print_path(int p){
    if(pre[p]!=-1){
        print_path(pre[p]);
        if(path[p]==0){
            cout<<'d';
        }else if(path[p]==1){
            cout<<'u';
        }else if(path[p]==2){
            cout<<'r';
        }else if(path[p]==3){
            cout<<'l';
        }
    }
}
struct cmp{
    bool operator () (int u, int v){
        return my_states[u].f > my_states[v].f;
    }
};



void work(){
    for(int i=0; i<400000; i++){
        pre[i]=-1;
        closed_table[i]=0;
        open[i] = 0;
    }
    //map<long long int, int> mymap;
    for(int i=0; i<9; i++){
        my_states[0].state[i] = d[i];
    }
    int cur, next, final,tmp;
    int cnt = 0;
    my_states[0].id = cnt;
    my_states[0].state_int = get_hash((my_states[0].state));
    my_states[0].f = get_f(my_states[0].state);
    my_states[0].step = 0;
    priority_queue <int, vector<int>, cmp> Q;
    Q.push(my_states[0].id);
    //mymap[my_states[cur].state_int] = cnt;
    insert(my_states[0].state_int, cnt);
    cnt++;
    int ans = -1;
    //map<long long int, int>::iterator it;
    short inter_state[9];
    while(!Q.empty()){
        cur = Q.top();
        Q.pop();
        //cout<<my_states[cur].state_int<<endl;
        if(my_states[cur].state_int == 123456789LL){
            ans = my_states[cur].step;
            final = cur;
            break;
        }
        int tentative_g_score = my_states[cur].step+1;
        int h_score;
        //expand here
        int pos = my_states[cur].p;
        closed_table[my_states[cur].id] = 1;
        open[my_states[cur].id] = 0;
        for(int i=0; i<4; i++){
            int x = pos/3+dir[i][0], y = pos%3+dir[i][1];
            if(x>=0 && x<3 && y>=0 && y<3){
                //memcpy(inter_state, my_states[cur].state,sizeof(short)*9);
                //cout<<sizeof(my_states[cur])<<endl;
                for(int k=0; k<9; k++){
                    inter_state[k]=my_states[cur].state[k];
    	        }
                swap(inter_state[x*3+y], inter_state[pos]);
                long long int state_int = get_hash(inter_state);
                //it = mymap.find(state_int);
                int it = is_in(state_int);
                bool tentative_is_better = false;
                //if(it==mymap.end()){
                if(it==-1){
                    next = cnt;
                    insert(state_int, next);
                    cnt++;
                }else{
                    next = it;
                }
                if(closed_table[next]==1){
                    continue;
                }
                if(open[next] == 0){
                    open[next] = 1;
                    tentative_is_better = true;
                }else if(tentative_g_score < my_states[next].step){
                    tentative_is_better = true;
                }else{
                    tentative_is_better = false;
                }

                if(tentative_is_better){
                    memcpy(my_states[next].state, inter_state, sizeof(inter_state));
                    my_states[next].id = next;
                    my_states[next].state_int = state_int;
                    pre[my_states[next].id] = my_states[cur].id;
                    path[my_states[next].id] = i;
                    my_states[next].step = tentative_g_score;
                    //my_states[next].f = tentative_g_score + my_states[next].h;
                    my_states[next].f = tentative_g_score + get_f(inter_state);
                    my_states[next].p = x*3+y;
                }
                Q.push(next);
            }
        }
        }
        
        if(ans==-1){
            cout<<"unsolvable"<<endl;
        }else{
            print_path(my_states[final].id);
            cout<<endl;
        }
}
        
    int main(){
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                char c;
                cin>>c;
                if(c=='x'){
                    d[i*3+j]=9;
                    //start.p = i*3+j;
                    my_states[0].p = i*3+j;
                }else{
                    d[i*3+j]=c-'0';
                }
            }
        }
        work();
        return 0;
    }

