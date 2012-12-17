#include <iostream>
#include <string>
#define MAXN 601
#define INF 99999999
using namespace std;

string words[MAXN];
int words_len[MAXN];
int dp[MAXN][MAXN];
int W,L;
string S;
int c[301][301];

int get_dp(int left, int right){
    if(dp[left][right]!=INF){
        return dp[left][right];
    }
    if(left==right)return 1;
    int tmp_min = INF;
    for(int i=left; i<=right-1; i++){
        int t_ans1 = get_dp(left, i);
        int t_ans2 = get_dp(i+1, right);
        /*if(left==0&&right==9){
            cout<<"i is "<<i<<endl;
            cout<<"!!!"<<endl;
                   
                cout<<t_ans1<<" "<<t_ans2<<endl;
            
        }*/

        if(tmp_min > t_ans1+t_ans2){
            tmp_min = t_ans1+t_ans2;
        }
    }
    dp[left][right] = tmp_min;
    return tmp_min;

}


void work(){
    for(int i=0; i<MAXN; i++)for(int j=0; j<MAXN;j++)dp[i][j]=INF;
    int s_len = S.length();
    
    for(int i=0; i<W; i++){
        int ptr_word, ptr_str;
        for(int j=0; j<=s_len-words_len[i]; j++){
            ptr_str = j;
            ptr_word = 0;
            if(words[i][ptr_word]!=S[j])continue;

            while(1){
                if(ptr_str>=s_len)break;
               
                if(words[i][ptr_word]==S[ptr_str]){
                    ptr_str++,ptr_word++;
                }else{
                    ptr_str++;
                }
                if(ptr_word==words_len[i]){
                    /*cout<<"in "<<words[i]<<endl;
                    cout<<j<<" "<<ptr_word<<" "<<ptr_str-1<<endl;
                    */
                    dp[j][ptr_str-1] = min(dp[j][ptr_str-1], ptr_str-j-words_len[i]);
                    //cout<<"dp is "<<dp[j][ptr_str-1]<<endl;
                    break;
                }
            }
        }
    }
    /*for(int i=0; i<s_len; i++){
        for(int j=0; j<s_len; j++){
            if(dp[i][j]!=INF)
            cout<<"dp["<<i<<"]["<<j<<"]"<<dp[i][j]<<endl;
        }
    }*/
    int ans = get_dp(0, L-1);
    cout<<ans<<endl;
}


int main(){
    cin>>W>>L;
    cin>>S;
    for(int i=0; i<W; i++){
        cin>>words[i];
        words_len[i] = words[i].size();
    }
    work();
    
    return 0;
}

