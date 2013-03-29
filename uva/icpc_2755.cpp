#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 205010;
const int INF = 999999997;


char Str[MAXN];
//string Str;

struct entry{
    int nr[2], p;
}L[MAXN];

int P[20][MAXN], N, stp, T;

int mycmp(struct entry a, struct entry b){
    return a.nr[0]==b.nr[0]?(a.nr[1]<b.nr[1]?1:0):(a.nr[0]<b.nr[0]?1:0);
}

void build_sa(){
    N = strlen(Str);
    //N = Str.length();
    for(int i=0; i<N; i++){
        P[0][i] = Str[i]-'.';
    }

    int cnt;
    for(stp=1, cnt=1; cnt>>1 < N; stp++, cnt<<=1){
        for(int i=0; i<N; i++){
            L[i].nr[0] = P[stp-1][i];
            L[i].nr[1] = i+cnt<N?P[stp-1][i+cnt]:-1;
            L[i].p = i;
        }
        sort(L, L+N, mycmp);
        for(int i=0; i<N; i++){
            P[stp][L[i].p] = i>0 && L[i].nr[0]==L[i-1].nr[0] && L[i].nr[1]==L[i-1].nr[1]?P[stp][L[i-1].p]:i;
        }
    }
}

int lcp(int x, int y){
    int k, ret = 0;
    if(x==y)return N-x;
    for(k=stp-1; k>=0 && x<N && y<N; k--){
        if(P[k][x]==P[k][y]){
            x+=1<<k, y+= 1<<k, ret+=1<<k;
        }
    }
    return ret;
}

int mapping[MAXN];
int height[MAXN];

void myprint(int start, int end){
    for(int i=start; i<end; i++)cout<<Str[i];
}


void work(){
    int initial_length = N/2;
    for(int i=0; i<N; i++){
        mapping[P[stp-1][i]] = i;
    }
  /* 
    cout<<"mapping is "<<endl;
    for(int i=0; i<N; i++){
        cout<<mapping[i]<<" ";
    }cout<<endl;
    cout<<"sorted result is :"<<endl;
    
    for(int i=0; i<N; i++){
        myprint(mapping[i], strlen(Str));
        cout<<endl;
    }
*/

    /*
    height[0] = 0;
    for(int i=1; i<N; i++){
        height[i] = lcp( mapping[i], mapping[i-1] );
    }*/

    int position;
    for(int i=0; i<N; i++){
        if(mapping[i]<initial_length){
            //cout<<"first is at "<<i<<" with value "<<mapping[i]<<endl;
            position = i;
            break;
        }
    }
    //cout<<"position is ";
    //myprint(mapping[position], strlen(Str));
    //cout<<endl;
    
    int ans = mapping[position]; 
    for(int i=position+1; i<N; i++){
        /*
        cout<<"lcp of ";
        myprint(mapping[position], strlen(Str));
        cout<<" and ";
        myprint(mapping[i], strlen(Str));
        */
        int tmp = lcp(mapping[position], mapping[i]);
        if(tmp>=initial_length){
            ans = mapping[i];
            continue;
        }else{
            break;
        }
    }
    cout<<ans<<endl;
}

int main(){
    scanf("%d",&T);
    //cin>>T;
    int nothing;
    char buf[MAXN];
    while(T--){
        Str[0] = '\0';
        scanf("%d %s",&nothing, buf);
        //Str = "";
        //cin>>nothing>>Str;
        strcat(Str, buf);
        strcat(Str, buf);
        //Str+=Str;
        build_sa();
        work();
    }

}



