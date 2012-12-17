#include <iostream>
#include <map>
#include <stdio.h>
#include <string>

using namespace std;
int T,N,row = -1,ans = 0;
const int MAXN = 101;
//char d[MAXN][MAXN], r_d[MAXN][MAXN];
string d[MAXN],r_d[MAXN];


typedef pair<int, int> mypair;

void work(){
    map <string, mypair > my_map;
    ans = 0;
    for(int i=0; i<N; i++){
        int sz = d[i].size();
        for(int j=0; j<sz; j++){
            for(int k=j; k<sz; k++){
                string t = d[i].substr(j,k-j+1);
                
                map<string, mypair >::iterator it = my_map.find(t);
                //map <string, mypair >::iterator it = my_map.find(t);
                int second = (*it).first;
                int num = 0;
                if(it!=my_map.end()){
                    if((*it).second != i){
                        //(*it).second+=1;
                        //(*it).first = i;
                        my_map[t] = mypair(i,(second)+1);
                        //(*it)=mypair(i,second+1);
                        num = (*it).second;
                    }
                }else{
                    my_map[t] = mypair(1, i);
                    num = 1;
                }

                if(i==N-1&&num==N){
                    if(ans < k-j+1){
                        ans = k-j+1;
                    }
                }

                t = reverse(t.begin(), t.end());
                it = my_map.find(t);
                if(it!=my_map.end()){
                    if((*it).second!=i){
                        (*it).second+=1;
                        (*it).fisrt=i;
                        num = (*it).second;
                    }
                }else{
                    my_map[t] = mypair(1,i);
                    num =1;
                }
                if(i==N-1&&num==N){
                    if(ans < k-j+1){
                        ans = k-j+1;
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    cin>>T;
    while(T--){
        cin>>N;
        for(int i=0; i<N; i++){
            cin>>d[i];
            r_d[i] = reverse(d[i].begin(), d[i].end());
        }
        for(int i=0; i<N; i++){
            cout<<r_d[i]<<endl;
        }
        work();
    }

    return 0;
}

