#include <iostream>

using namespace std;
int T,M,N;
const int MAXN = 101;
string maze[MAXN];
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int head,s_x, s_y;
int vis[MAXN][MAXN][4];

bool check(int x,int y){
    if(x>=0 && x<N && y>=0 && y<N){
        return true;
    }return false;
}


int go_left(){
    memset(vis,0,sizeof(vis));
    int cur_head = head;
    int cur_x = s_x, cur_y = s_y;
    int steps = 1;
    vis[cur_x][cur_y][cur_head] = 1;
    while(maze[cur_x][cur_y]!='E'){
        int n_x = cur_x+dir[cur_head][0];
        int n_y = cur_y+dir[cur_head][1];
        if(!check(n_x, n_y) || maze[n_x][n_y]=='#'|| vis[n_x][n_y][cur_head] ==1){
            cur_head+=1;
            cur_head%=4;
            continue;
        }else{
            cur_x = n_x;
            cur_y = n_y;
            vis[n_x][n_y][cur_head] = 1;
            steps++;
        }
        cout<<n_x<<" "<<n_y<<" "<<cur_head<<endl;
    }
    return steps;
}

int go_right(){
    memset(vis,0,sizeof(vis));
    int cur_head = head;
    int cur_x = s_x, cur_y = s_y;
    cout<<"start at "<<s_x<<" "<<s_y<<endl;
    int steps = 1;
    vis[cur_x][cur_y][cur_head] = 1;
    while(maze[cur_x][cur_y]!='E'){
        int n_x = cur_x+dir[cur_head][0];
        int n_y = cur_y+dir[cur_head][1];
        cout<<n_x<<" "<<n_y<<" "<<cur_head<<endl;
        if(!check(n_x, n_y) || maze[n_x][n_y]=='#'|| vis[n_x][n_y][cur_head] ==1){
            cur_head+=3;
            cur_head%=4;
            continue;
        }else{
            cur_x = n_x;
            cur_y = n_y;
            vis[n_x][n_y][cur_head] = 1;
            steps++;
            cur_head = 1;
        }
    }
    return steps;
}


int main(){
    cin>>T;
    while(T--){
        cin>>M>>N;
        for(int i=0; i<N; i++){
            cin>>maze[i];
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(maze[i][j]=='S'){
                    s_x = i, s_y = j;
                    if(s_x==0){
                        head = 2;
                    }else if(s_x == N-1){
                        head = 0;
                    }else if(s_y == 0){
                        head = 1;
                    }else if(s_y == M-1){
                        head = 3;
                    }
                }
            }
        }
        cout<<"head is "<<head<<endl;
        cout<<"s_x s_y "<<s_x<<" "<<s_y<<endl;
        maze[s_x][s_y] = '#';
        int left_step = go_left();
        cout<<"left is "<<left_step<<endl;
        int right_step = go_right();
        cout<<"right is "<<right_step<<endl;
        cout<<left_step<<endl;
        cout<<right_step<<endl;

    }
    return 0;
}

