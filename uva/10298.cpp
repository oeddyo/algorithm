#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>

using namespace std;



const int MAXN = 1000010;
const int INF = 99999999;
char S[MAXN];
int failure[MAXN];

void build_failure(){
    memset(failure,0,sizeof(failure));

    int M = strlen(S);
    int j;
    for(int i=2; i<=M; i++){
        j = failure[i-1];
        for(;;){
            if(S[i-1]==S[j]){
                failure[i] = j+1;
                break;
            }
            if(j==0){failure[i] = 0;break;}
            
            j = failure[j];
        }
    }
    /*
    for(int i=0; i<=M; i++){
        cout<<failure[i]<<" ";
    }cout<<endl;
    */
    int tmp = INF;
    if(M%(M-failure[M])==0){
        tmp = min(M-failure[M], tmp);
    }
    int ans;
    if(tmp==INF){
        ans = 1;
    }else{
        ans = M/tmp;
    }
    cout<<ans<<endl;
}


void work(){
    build_failure();

}



int main(){
    while(1){
        scanf("%s",S);
        if(S[0]=='.')break;
        work();

    }


    return 0;
}

