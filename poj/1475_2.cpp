#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int r,c;
const int MAXN = 21;
const int MYMOD = 999983;
char maze[MAXN][MAXN];
int b_r, b_c, p_r, p_c, e_r, e_c;
int global_cnt = 0;

typedef struct n{
    int br,bc;
    int pr,pc;
    int step;
    int id;
    int walk;
}node;
int pre[MYMOD*3][2];
char moves[8] = {'N','E','S','W','n','e','s','w'};
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

bool vis[MAXN][MAXN][MAXN][MAXN];
bool check(int _r, int _c){
    if(_r<0 || _r>=r || _c<0 || _c>=c|| maze[_r][_c]=='#'){
        return false;
    }return true;
}
string ans_path = "";
void get_path(int cur){
    if(pre[cur][0]==-1){
        return ;
    }
    ans_path+=moves[ pre[cur][1] ];
    get_path(pre[cur][0]);
}

bool is_in(node &cur){
    if(vis[cur.br][cur.bc][cur.pr][cur.pc]){
        return true;
    }return false;
}

void work(){
    memset(pre,-1,sizeof(pre));
    global_cnt = 0;
    ans_path = "";
    node start;
    start.br = b_r, start.bc = b_c, start.pr = p_r, start.pc = p_c, start.step=0, start.id = global_cnt++, start.walk=1;

    queue<node> Q;
    Q.push(start);
    int ans = -1;
    node cur, next;
    int ans_state;
    vis[start.br][start.bc][start.pr][start.pc] = 1;
    while(!Q.empty()){
        cur = Q.front();
        Q.pop();
        //cout<<"people at "<<cur.pr<<" "<<cur.pc<<", box at "<<cur.br<<" "<<cur.bc<<endl;
        //print(cur);
        if(cur.br == e_r && cur.bc == e_c){
            ans = cur.step;
            ans_state = cur.id;
            break;
        }
        int nr, nc, nbr, nbc,nstep,nwalk;
        nbr = cur.br, nbc = cur.bc;
        for(int i=0; i<4; i++){
            nr = cur.pr+dir[i][0];
            nc = cur.pc+dir[i][1];
            if(check(nr,nc)){
                //move box
                bool move_box=false;
                if(nr==cur.br && nc==cur.bc){
                    nbr= cur.br+dir[i][0];
                    nbc= cur.bc+dir[i][1];
                    move_box = true;
                    //cout<<"move to "<<nbr<<" "<<nbc<<endl;
                    if(!check(nbr, nbc)){
                        move_box = false;
                        nbr = cur.br, nbc = cur.bc, nr = cur.pr, nc = cur.pc, nstep--;
                    }
                }else{
                    nbr = cur.br, nbc = cur.bc;
                }
                if(move_box){
                    nstep = cur.step+1;
                }else{
                    nstep = cur.step;
                }
                nwalk = cur.walk+1;
                next.pr = nr, next.pc = nc, next.br = nbr, next.bc = nbc, next.step = nstep, next.walk = nwalk;
                if(is_in(next)==false){
                    next.id = global_cnt++;
                    Q.push(next);
                    vis[next.br][next.bc][next.pr][next.pc] = 1;
                    if(move_box){
                        pre[next.id][0] = cur.id;
                        pre[next.id][1] = i;
                        //next.path = cur.path+move_path[i];
                    }else{
                        pre[next.id][0] = cur.id;
                        pre[next.id][1] = i+4;
                        //next.path = cur.path+no_move_path[i];
                    }
                    //cout<<"pre of "<<next.id <<" is "<<cur.id<<endl;
                }
            }
        }
    }
    if(ans==-1){
        cout<<"Impossible."<<endl;
    }else{
        get_path(ans_state);
        reverse(ans_path.begin(), ans_path.end());
        cout<<ans_path<<endl;
    }
}

int main(){
    int cnt_case = 1;
    //while(scanf("%d%d",&r,&c)!=EOF){
    while(cin>>r>>c){
        if(r==0&&c==0)break;
       // getchar();
        //cout<<"r and c are "<<r<<" "<<c<<endl;
        for(int i=0; i<r; i++){
            cin>>maze[i];
            for(int j=0; j<c; j++){
        //        scanf("%c",&maze[i][j]);
                if(maze[i][j]=='T'){
                    e_r = i, e_c = j;
                }else if(maze[i][j]=='B'){
                    b_r = i, b_c = j;
                }else if(maze[i][j]=='S'){
                    p_r = i, p_c = j;
                //    cout<<"people at "<<p_r<<" "<<p_c<<endl;
                }
            }
            //getchar();
        }
        /*
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cout<<maze[i][j];
            }cout<<endl;
        }
        cout<<endl;
*/
        cout<<"Maze #"<<cnt_case<<endl;
        work();
        cnt_case++;
        cout<<endl;
    }
    return 0;
}
