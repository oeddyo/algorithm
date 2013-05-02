#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100001;
const int INF = 900000000;
int N;

int d[MAXN];

void work(){
    /*
    for(int i=0; i<N; i++){
        cout<<data[i]<<" ";
    }cout<<endl;
    */
    int ans = -INF;
    for(int i=0; i<N-1; i++){
        int low = i+1;
        int high = N-1;
        int tmp_ans = -1;
        int mid;
        //cout<<"at "<<i<<endl;
        while(low<=high){
            //cout<<"low high = "<<low<<" "<<high<<endl;
            mid = (low+high)/2;
            if(d[mid]*1.0/d[i]<=2){
                low = mid+1;
                tmp_ans = mid;
            }else{
                high = mid-1;
            }
        }
        if(tmp_ans!=-1){
            ans = max(tmp_ans - i+1, ans);
        }
    }
    //cout<<"ans = "<<ans<<endl;
    cout<<N-ans<<endl;

}

int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>d[i];
    }
    sort(d, d+N);
    work();

    return 0;
}

