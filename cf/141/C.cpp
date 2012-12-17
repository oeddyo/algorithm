#include <iostream>
#include <string.h>
#include <vector>
#include <map>

using namespace std;


const int INF = 999999999;
const int MAXN = 501;
int N,M;
char g[MAXN][MAXN];

int get_f(int left_r, int left_c, int l){
    if(l==2){
        int p[4][2] = {{left_r, left_r}, {left_r, left_r+1}, {left_r+1, left_r}, {left_r+1, left_r+1}};
        int cnt = 0;
        for(int i=0; i<4; i++){
            if(g[p[i][0]][p[i][1]]=='*'){
                cnt++;
            }
        }
        if(cnt!=1)return 0;
        for(int i=0; i<4; i++){
            if(g[p[i][0]][p[i][1]]=='*'){
                return i+1;
            }
        }
    }


    l = l/2;
    int p[4][2] = {
        {left_r, left_c},
        {left_r, left_c+l},
        {left_r+l, left_c},
        {left_r+l, left_c+l}
    };

    for(int i=0; i<4; i++){
        if( black(p[i][0], p[i][1], l) ){
            bool ok = true;
            for(int j=0; j<4; j++){
                if(i!=j){
                    bool ok = get_f(p[j][0], p[j][1], l); 
                    if(!get_f(p[pj][0], p[j][1], l)){
                        ok = false;
                        break;
                    }
                }
            }


        if( get_f(p[i][0], p[i][1], l) == false){
            return false;
        }
    }


}


void work(){

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            for(int l=2; i+l-1<N && j+l-1<M; l*=2){
                bool is_f = get_f(i,j, l);
            }
        }
    }
}


int main(){
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>g[i][j];
        }
    }
    work();
    
    return 0;
}

