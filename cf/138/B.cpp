#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;
const int MAXN = 150001;
int a[MAXN];
int N,K;
void work(){
    set<int> my_set;
    vector<int> cnt;
    int left=-1, right = -1;
    for(int i=0; i<N; i++){
        my_set.insert(a[i]);
        if(my_set.size()==K){
            right = i;
            break;
        }
    }
    
    set<int> tmp;
    for(int i=right; i>=0; i--){
        tmp.insert(a[i]);
        if(tmp.size()==K){
            left = i;
            break;
        }
    }
    if(left==-1){
        cout<<"-1 -1"<<endl;
    }else{
        cout<<left+1<<" "<<right+1<<endl;
    }


}

int main(){
    cin>>N>>K;
    for(int i=0; i<N; i++){
        cin>>a[i];
    }
    work();
    return 0;
}

