/*
ID: xieke.b1
PROB: prefix
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <string.h>

using namespace std;
ifstream fin("prefix.in");
ofstream fout("prefix.out");

const int INF = 999999999;
int N;
typedef vector<int> vi;

const int MAXN = 201;
char words[MAXN][13];
int lens[MAXN];
int words_cnt =  0;
string text;


bool dp[200005];
int text_len = 0;
void work(){
    memset(dp,0,sizeof(dp));
    text_len = text.size();
    dp[0] = true;
    int ans = 0;
    for(int i=0; i<text_len; i++){
        if(dp[i]){
            for(int j=0; j<words_cnt; j++){
                int len = lens[j];
                if(i+len<text_len){
                    bool ok = true;
                    for(int k=i+1, ptr=0; k<=i+len && ptr<len; k++, ptr++){
                        if(words[j][ptr] == text[k]){
                            continue;
                        }else{
                            ok=false;
                            break;
                        }
                    }
                    //cout<<"at pos "<<i<<" try to add "<<words[j]<<" but the result is "<<ok<<endl;
                    if(ok){
                        //cout<<"at position "<<i<<" add "<<words[j]<<endl;
                        dp[i+len] = true;
                        ans = max(i+len, ans);
                    }
                }
            }
        }
    }
    fout<<ans<<endl;
}



int main(){
    words_cnt=0;
    while(1){
        fin>>words[words_cnt];
        lens[words_cnt] = strlen(words[words_cnt]);
        if(words[words_cnt][0]=='.')break;
        cout<<"cin "<<words[words_cnt]<<endl;
        words_cnt++;
    }
    text = "^";
    string t;
    while(fin>>t){
        text+=t;
    }
    cout<<"text is "<<text<<endl;
    work();
    return 0;
}

