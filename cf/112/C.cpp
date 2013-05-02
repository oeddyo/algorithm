#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
int K;
string S;

const int MAXN = 1000001;
int pos[MAXN];

void work(){
    int idx = 0;
    int S_sz = S.size();
    /*
    for(int i=0; i<S_sz; i++){
        if(S[i]=='1'){
            pos[idx++] = i;
        }
    }
    if(idx<K){
        cout<<0<<endl;
        return ;
    }
    */
    int front = 0;
    int end = 0;
    int cur = 0;
    long long int ans = 0;
    cout<<"S_sz = "<<S_sz<<endl;
    while(front<S_sz){
        cout<<"front = "<<front<<" "<<"end = "<<end<<endl;
        if(cur<K){
            if(end<S_sz){
                end++;
                if(end<S_sz && S[end]=='1'){
                    cur++;
                    if(cur==K){
                        ans++;
                    }
                }
            }else if(end>=S_sz){
                cout<<"haha i break"<<endl;
                break;
            }
        }else if(cur==K){
            if(S[front]=='1'){
                cur-=1;
            }else{
                ans+=1;
            }
            front++;
        }
    }
    cout<<ans<<endl;


}

int main(){
    cin>>K;
    cin>>S;
    work();


    return 0;
}

