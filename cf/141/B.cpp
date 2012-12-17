#include <iostream>
#include <string.h>
#include <vector>
#include <map>

using namespace std;


const int INF = 999999999;
const int MAXN = 60;

string A[MAXN];
string B[MAXN];
int Na, Nb, Ma, Mb;
void work(){
    int ans_sum = -INF;
    int ans_x=0, ans_y=0;
    for(int x=1-Na; x<=Nb-1; x++){
        for(int y=1-Ma; y<=Mb-1; y++){
            bool ok = true;
            int sum = 0;
            for(int i=1; i<=Na; i++){
                for(int j=1; j<=Ma; j++){
                    if( !(i+x>=1 && i+x<=Nb && j+y<=Mb && j+y>=1) ){
                        //cout<<"x="<<x<<" y="<<y<<" (i,j)=("<<i<<","<<j<<")"<<endl;
                        //ok = false;break;
                        continue;
                    }else{
                        sum += (A[i-1][j-1]-'0')*(B[i+x-1][j+y-1]-'0');
                    }
                }
                //if(ok==false)break;
            }
            /*
            if(ok){
                sum = sum;
            }else{
                sum = 0;
            }
            */
            if(ans_sum<sum){
                //cout<<"at "<<x<<" "<<y<<" sum is "<<sum<<endl;
                ans_sum = sum;
                ans_x = x;
                ans_y = y;
            }
        }
    }
    cout<<ans_x<<" "<<ans_y<<endl;

}


int main(){
    cin>>Na>>Ma;
    for(int i=0; i<Na; i++){
        cin>>A[i];
    }
    cin>>Nb>>Mb;
    for(int i=0; i<Nb; i++){
        cin>>B[i];
    }
    work();

    return 0;
}

