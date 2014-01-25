#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>
#include <string.h>


using namespace std;

string str1, str2;
const int MAXN = 2003;
int dp[MAXN][MAXN];

void work(){
    memset(dp,0,sizeof(dp));
    int sz_1 = str1.size();
    int sz_2 = str2.size();
     
    int tmp_max = 0;
    for(int i=1; i<sz_1; i++){
        for(int j=1; j<sz_2; j++){
            if(str1[i]==str2[j]){
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
                //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
                tmp_max = max(tmp_max, dp[i][j]);
            }else{
                dp[i][j] = 0; 
            }

        }
    }
    cout<<tmp_max<<endl;

    cout<<sz_2 - 1 - tmp_max<<endl;
}

int main(){
    cin>>str1;
    cin>>str2;
    str1 = "#"+str1;
    str2 = "*"+str2;
    work();



    return 0;
}

