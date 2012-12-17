#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


using namespace std;

const int MAXN = 100005;
int data[MAXN];
int N;

void work(){
    int ptr = 1;
    long long int pre = data[0];
    long long int add_on = 0;
    long long int ans = 0;
    while(ptr<N){
        long long int now = data[ptr]+add_on;
        //cout<<"ptr is "<<ptr<<" now is "<<now<<" pre is "<<pre<<endl;
        if(now>=pre){
            ptr++;
            pre = now;
            continue;
        }else{
            //cout<<"adding "<<endl;
            long long int dif = pre-now;
            add_on += dif;
            ans += dif;
        }
        ptr++;
    }
    cout<<ans<<endl;
}

int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>data[i];
    }
    work();
    
    return 0;
}

