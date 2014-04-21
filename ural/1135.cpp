#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
using namespace std;
 
#define DEBUG
#define REP(i,a) for(i=0;i<a;i++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define VE vector<int>
#define SZ size()
#define PB push_back

int N, ptr = 0;
const int MAXN = 30005;
string data[MAXN];
int szs[MAXN];
bool mark[MAXN]; 
int potential[MAXN], p_ptr = 0;

void work(){
    int ans = 0;
    for(int i=0; i<ptr; i++){
        while(1){
            //string tmp = "";
            memset(mark, 0, sizeof(mark));
            int c = 0;
            if(p_ptr==0){
                for(int j=0; j<szs[i]; j++){
                    if(j + 1 < szs[i] && data[i][j] == '>' && data[i][j+1] == '<'){
                        mark[j] = true;
                        if( 
                        potential[p_ptr++] += j;
                        j += 1;
                        c += 1;
                    }
                }
            }
            else{
                for(int j=0; j<p_ptr; j++){
                    int a = potential[j]-1;
                    int b = potential[j] + 1;

                    if(a-1>=0 && 
                }
            }
            
            for(int j=0; j<szs[i]-1; j++){
                if(mark[j] == true){
                    data[i][j] = '<';
                    data[i][j+1] = '>';
                    j += 1;
                }
            }

            //data[i] = tmp;
            if(c==0)break;
            ans += c;
        }
    }

    cout<<ans<<endl;
}

int main(){
   
    scanf("%d\n", &N);

    //getchar();
    char t;
    
    string tmp = "";
    for(int i=0; i<N; i++){
        t = getchar();
        if(t == '\n'){
            /* 
            szs[ptr] = tmp.length();
            data[ptr] = tmp;
            ptr += 1;
            tmp = "";
            */
            i -= 1;
        }else if(t=='>' || t=='<') {
            tmp += t; 
        }else{
            i -= 1;
        }

    }

    data[ptr++] = tmp;
    for(int i=0; i<ptr; i++){
        szs[i] = data[i].length();
    } 
    /*
    
    while(cin>>tmp){

        string tmp2 = "";
        for(int i=0; i<tmp.size(); i++){
            if(tmp[i] == '>' || tmp[i] == '<')
                tmp2 += tmp[i];
        }


        tmp = tmp2;
        data[ptr] = tmp;
        szs[ptr] = tmp.length();
        //c += data[ptr].length();
        ptr ++ ;
    }
    */
    work();


   return 0;
}

