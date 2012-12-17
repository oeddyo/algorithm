#include <iostream>
#include <queue>
#include <stdio.h>
#include <map>
#include <set>
using namespace std;

//string d;

int d[9];
typedef struct node{
    long long int state_int;
    short state[9];
    //string state;
    //string path;
    int f, step,p;
    int id;
    bool operator< ( const node &a){
        if(a.f == this->f){
            return a.step > this->step;
        }else{
            return a.f<this->f;
        }
        return false;
    }
}st;

st *start;

int get_f(node &a){
    int sh = 1; 
    int sum = 0;
    for(int i=0; i<9; i++){
        if(a.state[i]!=sh){
            sum++;
        }
        sh++;
    }
    return sum;
}

int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int path[400000];
int pre[400000]; 
long long int get_hash(node &a){
    long long int sum = 0;
    for(int i=0; i<9; i++){
        sum = sum*10+a.state[i];
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

void work(){
    for(int i=0; i<400000; i++){
        pre[i]=-1;
    }

    map<long long int, int> closed;
    for(int i=0; i<9; i++){
        start->state[i] = d[i];
    }

    int cnt = 0;
    start->f = get_f(*start);
    priority_queue <node*> Q;
    start->id = cnt;
    start->state_int = get_hash(*start);
    closed[start->state_int] = cnt++; 

    Q.push(start);

    node *cur, *next,*final;
    int ans = -1;
    while(!Q.empty()){
        cur = Q.top();
        Q.pop();
        //print_state(*cur);
        if(cnt>=10)break;
        cout<<"new one ->>>>>>>>"<<endl;
        if(cur->state_int == 123456789LL){
            ans = cur->step;
            final = cur;
            break;
        }
        //expand here
        int pos = cur->p;
        int original_f = cur->f;
        for(int i=0; i<4; i++){
            int x = pos/3+dir[i][0], y = pos%3+dir[i][1];
            if(x>=0 && x<3 && y>=0 && y<3){
                cout<<"now x and y are "<<x<<" "<<y<<endl;
                next = (node *) malloc(sizeof(node));
                memcpy(next, cur, sizeof(node));
                swap(next->state[x*3+y], next->state[pos]);
                next->state_int = get_hash(*next);
                //long long int state_int = get_hash(*cur);
                cout<<"current state is ";
                print_state(*cur);
                cout<<"next state is ";
                print_state(*next);
                cout<<"cur and next state_int "<<cur->state_int<<" "<<next->state_int<<endl;
                if(closed.find(next->state_int)!=closed.end()){
                    continue;
                }
                closed[next->state_int] = cnt;
                next->id = cnt;
                cnt++;
                int nnext = next->id;
                int ccur = cur->id;
                pre[nnext] = ccur;
                path[nnext] = i;
                next->step = cur->step+1;
                next->f = get_f(*next)+next->step;
                next->p = x*3+y;
                Q.push(next);
            }
        }
    }
    if(ans==-1){
        cout<<"unsolvable"<<endl;
    }else{
        cout<<final->step<<endl;
        cout<<"_----"<<endl;
        print_path(closed[final->state_int]);
        cout<<endl;
    }
}


int main(){
    start  = (node *) malloc(sizeof(node));
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            char c;
            cin>>c;
            if(c=='x'){
                d[i*3+j]=9;
                start->p = i*3+j;
            }else{
                d[i*3+j]=c-'0';
            }
        }
    }
    work();
    return 0;
}

