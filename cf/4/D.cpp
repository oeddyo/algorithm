#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;


typedef pair<int, int> pii;

typedef pair< pii, int > piii;

const int MAXN = 5002;
int N,W,H;
int dp[MAXN];

vector< piii > cards;

int rec[MAXN];
void print_dp(){
    cout<<"dp = "<<endl;
    for(int i=0; i<cards.size(); i++){
        cout<<dp[i]<<" ";
    }cout<<endl;
}

void work(){
    int n_cards = cards.size();
    memset(dp,0,sizeof(dp));
    memset(rec, -1, sizeof(rec));
    int ans = 0;
    int idx = -1;
    /*
    cout<<"after sort"<<endl;
    for(int i=0; i<n_cards; i++){
        cout<<cards[i].first.first<<" "<<cards[i].first.second<<endl;
    }
    */
    //print_dp();
    for(int i=0; i<n_cards; i++){
        if(cards[i].first.first>W && cards[i].first.second>H){
            dp[i] = 1;
            ans = 1;
            idx = i;
        }
    }
    //print_dp(); 
    for(int i=0; i<n_cards; i++){
        for(int j=0; j<i; j++){
            if(cards[j].first.first<cards[i].first.first && cards[j].first.second<cards[i].first.second && dp[j]!=0){
                if(dp[j]+1>dp[i]){
                    rec[i] = j;
                }
                dp[i] = max(dp[i], dp[j]+1);
                
                if(dp[i]>ans){
                    ans = dp[i];
                    idx = i;
                }
            }
        }
    }

    //cout<<"ans = "<<ans<<" idx = "<<idx<<endl; 
    if(idx==-1){
        cout<<0<<endl;
        return ;
    }
    cout<<ans<<endl;
    
    vector<int> ans_idx;
    while(idx!=-1){
        ans_idx.push_back( cards[idx].second +1);
        idx = rec[idx];
    }

    for(int i=ans_idx.size()-1; i>=1; i--){
        cout<<ans_idx[i]<<" ";
    }
    cout<<ans_idx[0]<<endl;


    /*
    for(int i=0; i<n_cards; i++){
        cout<<rec[i]<<" ";
    }
    cout<<endl;
    */


}



int main(){
    cin>>N>>W>>H;

    for(int i=0; i<N; i++){
        int a,b;
        cin>>a>>b;
        cards.push_back( piii( pii(a,b), i) );
    }
    sort(cards.begin(), cards.end());
    work();
    return 0;
}

