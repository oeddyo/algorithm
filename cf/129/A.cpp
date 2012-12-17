#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


using namespace std;

const int MAXN = 100005;

typedef pair<int, int> pii;

pii data[MAXN];
int N;

void work(){
    sort(data,data+N);
    if(N==1){
        cout<<data[0].second<<endl;
    }else{
        if(data[0].first==data[1].first){
            cout<<"Still Rozdil"<<endl;
        }else{
            cout<<data[0].second<<endl;
        }
    }
}

int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>data[i].first;
        data[i].second = i+1;
    }
    work();
    
    return 0;
}

