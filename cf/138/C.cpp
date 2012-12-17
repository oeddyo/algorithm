#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <string.h>

using namespace std;

const int MAXN = 150001;
typedef pair<char, int> pcc;
string S;

int rec[MAXN];
int cnt[MAXN];
void pre(){
    memset(cnt,0,sizeof(cnt));
    if(S[0]=='['){
        cnt[0] = 1;
    }

    for(int i=1; i<S.size(); i++){
        if(S[i]=='['){
            cnt[i] = cnt[i-1]+1;
        }else{
            cnt[i] = cnt[i-1];
        }
    }
}
int sz = S.size();


void work(){
    pre();
    stack< pcc > my_stack;
    memset(rec,-1,sizeof(rec));
    for(int i=0; i<S.size(); i++){
        if(my_stack.empty()){
            my_stack.push( pcc(S[i], i) );
        }else{
            char top = my_stack.top().first;
            char now = S[i];
            if((top=='(' && now==')') || (top=='[' && now==']') ){
                rec[my_stack.top().second] = i;
                my_stack.pop();
            }else if((top=='(' && now==']') && (top=='['&&now==')'))  {
                while(!my_stack.empty()){
                    my_stack.pop();
                }
            }else{
                my_stack.push( pcc(S[i],i));
            }
        }
    }
    /*
     * [][][]
     * 
     */

    sz = S.size();
    int ans = -1;
    int ans_left, ans_right;
    int cur = 0;
    string t_str, ans_str; 
    while(1){
        //cout<<"cur at "<<cur<<endl;
        if(cur>=sz)break;
        if(rec[cur]!=-1){
            t_str += S.substr(cur, rec[cur]-cur+1);
            cur = rec[cur]+1;
            int cnt =0;
            for(int k=0; k<t_str.size(); k++){
                if(t_str[k]=='['){
                    cnt++;
                }
            }
            if(cnt>ans){
                ans = cnt;
                ans_str = t_str;
            }
        }else{
            t_str = "";
            cur++;
        }    
    }
    if(ans==-1){
        cout<<0<<endl;
    }else{
        cout<<ans<<endl;
        cout<<ans_str<<endl;
    }

}

int main(){
    cin>>S;
    work();

    return 0;
}

