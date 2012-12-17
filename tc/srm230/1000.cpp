#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAXN = 60;
int dp[MAXN][MAXN];

int get_dig(int left, int right, string &s){
    if(right<left)return -1;
    int sum = 0; 
    for(int i=left; i<=right; i++){
        sum = s[i]-'0' + sum*10;
    }
    //cout<<"left right "<<left<<" "<<right<<" "<<sum<<endl;
    return sum;
}

int main(){
    string input;
    cin>>input;
    cout<<"input is "<<input<<endl;
    dp[0][0] = 1;
    int sz = input.size();

    for(int i=0; i<=sz; i++){
        for(int j=i; j<=sz; j++){
            for(int k=j+1; k<=sz; k++){
                //if(j-i>7 || k-j>7)continue;
                int first = get_dig(i,j-1,input);
                int second = get_dig(j, k-1, input);
                if(first>1000000 || second>1000000)break;
                if( (first==-1|| (first>=1&&first<=1000000)) && (second==-1||(second>=1&&second<=1000000 && first<=second))){
                //if(j-i<=7&&k-j<=7&& get_dig(i,j-1,input)<=1000000     get_dig(i,j-1, input)<get_dig(j,k-1, input)){
                    dp[j][k]+=dp[i][j];
                    cout<<"from "<<i<<" "<<j<<" to "<<j<<" "<<k<<" dp["<<i<<"]["<<j<<"] = "<<dp[i][j];
                    cout<<" dp["<<j<<"]["<<k<<"] = "<<dp[j][k]<<endl;
                    cout<<"now the two digits are "<<i<<" "<<j-1<<" "<<j<<" "<<k<<" "<<get_dig(i,j-1,input)<<" "<<get_dig(j,k,input)<<endl;
                }
            }
        }
    }
    int ans = 0;
    for(int i=0; i<=sz; i++){
        if(dp[i][sz]!=0){
            cout<<"dp["<<i<<"]["<<sz<<"]="<<dp[i][sz]<<endl;
        }
        ans+=dp[i][sz];
    }
    cout<<ans<<endl;
    return 0;
}


