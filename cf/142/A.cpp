#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAXN = 10001;
int S,N;

typedef struct _node{
    int x, y;
}dragon;

dragon dragons[MAXN];

bool cmp(const dragon &a, const dragon &b){
    if(a.x==b.x){
        return a.y>b.y;
    }else{
        return a.x<b.x;
    }
}


void work(){
    sort(dragons, dragons+N, cmp);
    /*
    for(int i=0; i<N; i++){
        cout<<dragons[i].x<<" "<<dragons[i].y<<endl;
    }
    */
    bool ok =true;
    for(int i=0; i<N; i++){
        if(S<=dragons[i].x){
            ok = false;
            break;
        }else{
            S+=dragons[i].y;
        }
    }
    if(ok){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}

int main(){
    cin>>S>>N;
    for(int i=0; i<N; i++){
        cin>>dragons[i].x>>dragons[i].y;
    }
    work();
    return 0;
}

