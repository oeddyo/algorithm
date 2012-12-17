#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


using namespace std;


string S;
int sz;
typedef vector<string> vs;

bool is_p(string &s){
    int t_sz = s.size();
    int front = 0, rear = t_sz-1;
    bool ok = true;
    while(front<t_sz){
        if(s[front]==s[rear]){
            front++,rear--;
        }else{
            ok = false;break;
        }
    }
    return ok;
}


string get_string(int state){
    string t;
    for(int i=0; i<sz; i++){
        if( ((1<<i) & state)== 0)continue;
        t += S[i];
    }
    return t;
}
vs ans;

void work(){
    sz = S.size();
    for(int i=0; i<(1<<sz); i++){
        string tmp = get_string(i);
        if( is_p(tmp) ){
            ans.push_back(tmp);
        }
    }
    sort(ans.begin(), ans.end());
    cout<<ans[ ans.size() -1]<<endl;
}

int main(){
    cin>>S;
    work();
    return 0;
}

