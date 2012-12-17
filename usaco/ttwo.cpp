/*
ID: xieke.b1
PROB: ttwo
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <stack>
#include <vector>
#include <string.h>
#include <queue>


using namespace std;
ifstream fin("ttwo.in");
ofstream fout("ttwo.out");

const int INF = 999999999;
string mymap[12];

typedef struct _n{
    int f_x, f_y, f_d;
    int c_x, c_y, c_d;
    int minute;
}node;

int dir[4][2] = {
    {-1,0},{0,1},{1,0},{0,-1}
};

bool judge(int tx, int ty){
    if(tx<0 || ty<0 || tx>=10 || ty>=10)return false;
    if(mymap[tx][ty]=='*')return false;
    return true;
}
bool vis[11][11][4][11][11][4];

void mark(node &t){
    vis[t.f_x][t.f_y][t.f_d][t.c_x][t.c_y][t.c_d] = true;
}
bool has_visit(node &t){
    if(vis[t.f_x][t.f_y][t.f_d][t.c_x][t.c_y][t.c_d]){
        return true;
    }
    return false;
}

void print(node &t){
    cout<<"cow pos "<<t.c_x<<" "<<t.c_y<<endl;
    cout<<"farm pos "<<t.f_x<<" "<<t.f_y<<endl;

}
void work(){
    node initial;
    initial.minute=0;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(mymap[i][j]=='C'){
                initial.c_x = i;
                initial.c_y = j;
                initial.c_d = 0;
            }else if(mymap[i][j]=='F'){
                initial.f_x = i;
                initial.f_y = j;
                initial.f_d = 0;
            }
        }
    }
    print(initial);
    //queue<node> Q;
    //Q.push(initial);
    
    node cur = initial;
    mark(initial);
    while(1){
        int tx = cur.c_x + dir[cur.c_d][0];
        int ty = cur.c_y + dir[cur.c_d][1];
        if( judge(tx,ty) ){
            cur.c_x = tx;
            cur.c_y = ty;
        }else{
            cur.c_d += 1;
            cur.c_d %=4;
        }

        tx = cur.f_x + dir[cur.f_d][0];
        ty = cur.f_y + dir[cur.f_d][1];
        if(judge(tx,ty)){
            cur.f_x = tx;
            cur.f_y = ty;
        }else{
            cur.f_d +=1;
            cur.f_d %=4;
        }
        cur.minute++;
        cout<<"Now cow at "<<cur.c_x<<" "<<cur.c_y<<endl;
        cout<<"Now far at "<<cur.f_x<<" "<<cur.f_y<<endl;
        if(cur.f_x == cur.c_x && cur.f_y == cur.c_y){
            fout<<cur.minute<<endl;
            exit(0);
        }
        if(has_visit(cur) ){
            fout<<0<<endl;
            exit(0);
        }
        mark(cur);
    }

/*
    while(!Q.empty()){
        node cur = Q.front();
        //Q.pop();

        //move cow
        Q.push(cur); 
    }
*/
}

int main(){
    for(int i=0; i<10; i++){
        fin>>mymap[i];
    }
    work();
    return 0;
}

