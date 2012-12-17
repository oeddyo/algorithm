#include <iostream>
#include <stdio.h>

#define MAXN 200
#define INF 999999999
using namespace std;

string str;
int dp[MAXN][MAXN];
int print_ans(int i, int j){
    if(dp[i][j]!=INF){
        return dp[i][j];
    }
    if(i>j){
        return 0;
    }
    if(i==j){
        return 1;
    }
    int t_min = INF;
    int pos = -2;
    if((str[i]=='(' && str[j]==')') || (str[i]=='['&&str[j]==']')){
        t_min = print_ans(i+1,j-1);
    }
        for(int k=i; k<j; k++){
             int t1 = print_ans(i,k);
             //cout<<"t1 is "<<t1<<endl;
             int t2 = print_ans(k+1,j);
             //cout<<"t2 is "<<t2<<endl;
             if(t1+t2<t_min){
                 t_min = t1+t2;
                 pos = k;
             }
        }

        dp[i][j]=t_min;
        return t_min;
}
void print(int i,int j){
    //cout<<"seeing "<<i<<" "<<j<<endl;
    int t_min = INF;
    int pos = -1;
    if(i>j)return;
    if(dp[i][j]==0){
        for(int k=i; k<=j; k++)cout<<str[k];
        return ;
    }

    if(i==j){
        if(str[i]=='('||str[i]==')'){
            cout<<"()";
        }else if(str[i]=='['||str[i]==']'){
            cout<<"[]";
        }
        return ;
    }
    if((str[i]=='(' && str[j]==')') || (str[i]=='['&&str[j]==']')){
        //cout<<str[i];
        t_min = print_ans(i+1,j-1);
        //cout<<str[j];
        pos = -1;
    }
    for(int k=i; k<j; k++){
        int t1=print_ans(i,k);
        int t2=print_ans(k+1,j);
        if(t1+t2<t_min){
            t_min = t1+t2;
            pos=k;
        }
    }
    if(pos==-1){
        cout<<str[i];
        print(i+1,j-1);
        cout<<str[j];
    }else{
        print(i,pos);
        print(pos+1,j);
    }
}

int main(){
    //while(cin>>str){
    cin>>str;
    for(int i=0; i<MAXN; i++)for(int j=0; j<MAXN; j++)dp[i][j]=INF;
    int sz = str.size();
    //cout<<print_ans(0,sz-1)<<endl; 
    print_ans(0,sz-1);
    print(0,sz-1);
    cout<<endl;
    return 0;
}
