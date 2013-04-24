#include <iostream>
#include <cstring>
#include <cstdio>


using namespace std;
int T;
string S[4];


int checkRow(int row){
    int x = 0, y = 0, t = 0;
    for(int i=0; i<4; i++){
        if(S[row][i] == 'X' ){
            x++;
        }else if(S[row][i]== 'O'){
            y++;
        }else if(S[row][i]=='T'){
            t++;
        }
    }
    // 0-> x, 1->y, 2->nothing
    if(x==4){
        return 0;
    }
    if(y==4){
        return 1;
    }
    if(x==3 && t==1){
        return 0;
    }else if(y==3 && t==1){
        return 1;
    }
    return 2;
}

int checkCol(int col){
    int x = 0, y = 0, t = 0;
    for(int i=0; i<4; i++){
        if(S[i][col] == 'X' ){
            x++;
        }else if(S[i][col]== 'O'){
            y++;
        }else if(S[i][col]=='T'){
            t++;
        }
    }
    // 0-> x, 1->y, 2->nothing
    if(x==4){
        return 0;
    }
    if(y==4){
        return 1;
    }
    if(x==3 && t==1){
        return 0;
    }else if(y==3 && t==1){
        return 1;
    }
    return 2;
}

int checkLeftDiag(){
    int x = 0, y = 0, t = 0;
    for(int i=0; i<4; i++){
        if(S[i][i] == 'X' ){
            x++;
        }else if(S[i][i]== 'O'){
            y++;
        }else if(S[i][i]=='T'){
            t++;
        }
    }
    // 0-> x, 1->y, 2->nothing
    if(x==4){
        return 0;
    }
    if(y==4){
        return 1;
    }
    if(x==3 && t==1){
        return 0;
    }else if(y==3 && t==1){
        return 1;
    }
    return 2;
}

int checkRightDiag(){
    int x = 0, y = 0, t = 0;
    for(int i=0; i<4; i++){
        if(S[i][3-i] == 'X' ){
            x++;
        }else if(S[i][3-i]== 'O'){
            y++;
        }else if(S[i][3-i]=='T'){
            t++;
        }
    }
    // 0-> x, 1->y, 2->nothing
    if(x==4){
        return 0;
    }
    if(y==4){
        return 1;
    }
    if(x==3 && t==1){
        return 0;
    }else if(y==3 && t==1){
        return 1;
    }
    return 2;
}


void work(){
    //diag
    bool empty = false;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(S[i][j]=='.')empty=true;
        }
    }
    bool x = false, y = false;
    for(int i=0; i<4; i++){
        int r = checkRow(i);
        if(r==0){
            x = true;
        }else if(r==1){
            y = true;
        }
    }
    for(int i=0; i<4; i++){
        int r = checkCol(i);
        if(r==0){
            x=true;
        }else if(r==1){
            y = true;
        }
    }
    int r = checkLeftDiag();
    if(r==0)x = true;
    if(r==1)y = true;

    r = checkRightDiag();
    if(r==0)x = true;
    if(r==1)y = true;

    //cout<<"res = "<<x<<" "<<y<<" "<<empty<<endl;

    if((x && y && empty==false) || (x==false && y==false && empty==false)){
        cout<<"Case #"<<T<<": Draw"<<endl;
    }else if(x==true && y==false){
        cout<<"Case #"<<T<<": X won"<<endl;
    }else if(x==false && y==true){
        cout<<"Case #"<<T<<": O won"<<endl;
    }else if(x==false && y==false && empty==true){
        cout<<"Case #"<<T<<": Game has not completed"<<endl;
    }
}


int main(){
    int n_case;
    cin>>n_case;
    for(T = 1; T<=n_case; T++){
        for(int i=0; i<4; i++){
            cin>>S[i];
        }
        work();
    }
    return 0;
}

