#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cmath>

using namespace std;

const int INF = 999999999;
const int MAXN = 100005;
int data[MAXN];
int N;

map<int, int> up;
map<int, int> down;
map<int, int> count_same;
set<int> colors;


void work(){
    //double half = N*1.0/2;
    int half = ceil(N*1.0/2);
    set<int>::iterator it;
    int min_moves = INF;
    for(it = colors.begin(); it!=colors.end(); it++){
        //cout<<"seeing "<<*it<<endl;
        //cout<<"up is "<<up[*it]<<" down is "<<down[*it]<<" cnt_same is "<<count_same[*it]<<endl;

        if( up[*it] >= half ){
            min_moves = min(min_moves, 0);
        }else if( up[*it] + down[*it] - count_same[*it] >= half){
            //cout<<"in "<<endl;
            int need_flip = half - up[*it];
            //min_moves = min(min_moves, down[*it] - count_same[*it]);
            min_moves = min(min_moves, need_flip);
        }
    }
    if(min_moves == INF){
        cout<<"-1"<<endl;
    }else{
        cout<<min_moves<<endl;
    }
}

int main(){
    cin>>N;
    int f, s;
    for(int i=0; i<N; i++){
        cin>>f>>s;
        if(up.find(f)==up.end()){
            up[f]=1;
        }else{
            up[f]++;
        }
        if(down.find(s) == down.end()){
            down[s] = 1;
        }else{
            down[s]++;
        }
        colors.insert(f);
        colors.insert(s);
        if(s==f){
            if( count_same.find(s)!=count_same.end() ){
                count_same[s] += 1;
            }else{
                count_same[s] = 1;
            }
        }
    }
    
    work();
    return 0;
}

