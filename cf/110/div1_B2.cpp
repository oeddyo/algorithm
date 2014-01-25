#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>
#include <string.h>


using namespace std;

string str1, str2;
const int MAXN = 2003;
int dp[MAXN][MAXN];

int work(string &mystr1, string &mystr2){

    int ptr1 = 0, ptr2 = 0;
    int sz1 = mystr1.size(), sz2 = mystr2.size();
    
    int cnt = 0;
    while(ptr2<sz2){
        while(ptr1<sz1){
            if(mystr1[ptr1]==mystr2[ptr2]){
                ptr1++, ptr2++;
                cnt++;
            }else{
                ptr1++;
            }
        }
        if(ptr1>=sz1){
            break;
        }
    }
    int len = 0;
    
    if(sz1>sz2){
        return sz1 - cnt;
    }else{
        return sz2 - cnt;
    }
}

int main(){
    cin>>str1;
    cin>>str2;


    int sz = str1.size();
    int sz2 = str2.size();
    int ans = 1000000000;
    for(int i=0; i<sz; i++){
        for(int j=i; j<sz; j++){
            int len = j-i+1;
            string tmp = str1.substr(i, len);

            if(tmp[0]!=str2[0] ||  tmp[len-1]!=str2[sz2-1])continue;

            int cur = work(tmp, str1);
            ans = min(cur, ans);
            cout<<"tmp = "<<tmp<<endl;
            cout<<cur<<endl;
        }
    }

    cout<<"ans = "<<ans<<endl;


    return 0;
}

