#include <iostream>
#include <string>
#include <vector>

using namespace std;

string S, s_begin, s_end;
const int MAXN = 2005;
int P1[MAXN][50];
int P2[MAXN][50];
int sz, step;
struct node{
    int nr[2];
    int p;
};
struct node L[MAXN];

int my_cmp(struct node &a, struct node &b){
    return (a.nr[0] == b.nr[0])?(a.nr[1]<b.nr[1]?1:0):(a.nr[0]<b.nr[0]?1:0);
}

int search(string pattern, string S){
    int high=sz, mid, low=0, res = -1;
    int p_size = pattern.size();
    while(low<high){
        int mid = (high+low)/2;
        string cur = S.substr(L[mid].p, sz);
        if(pattern >= cur){
            low = mid+1;
        } else if(pattern < cur){
            high = mid;
            res = mid;
        }
    }
    return res;
}

int lca(int x, int y, int P[][50]){
    int k, ret = 0;
    if(x==y)return sz-x;
    for(k=step-1; k>=0 && x<sz && y<sz; k--){
        if(P[x][k] == P[y][k]){
            x+= 1<<k, y+= 1<<k, ret += 1<<k;
        }
    }
    return ret;
}

vector<int> work(int P[][50], string S, string pattern){
    for(int i=0; i<sz; i++){
        P[i][0] = S[i] - 'a';
        L[i].p = i;
    }
    int k, cnt;
    for(cnt=1, k=1; (cnt>>1)<sz; k++, cnt<<=1){
        for(int i=0; i<sz; i++){
            L[i].nr[0] = P[i][k-1];
            L[i].nr[1] = (i+cnt>=sz)?-1:P[i+cnt][k-1];
            L[i].p = i;
        }
        sort(L, L+sz, my_cmp);
        for(int i=0; i<sz; i++){
            P[L[i].p][k] = (i>0 && L[i].nr[0] == L[i-1].nr[0] && L[i].nr[1] == L[i-1].nr[1])?P[L[i-1].p][k]:i;
        }
        step = k;
    }
    
    cout<<"building successfully"<<endl;
    for(int i=0; i<sz; i++){
        cout<<S.substr(L[i].p, sz)<<endl;
    }
    cout<<"rank = "<<endl;
    cout<<"sz = "<<sz<<endl;
    for(int i=0; i<sz; i++){
        cout<<L[i].p<<" ";
    }cout<<endl;

    int up = search(pattern, S);
    cout<<"up = "<<up<<endl;
    vector<int> tmp;
    if(up==-1){
        return tmp;
    }
    cnt = 0;
    int p_size = pattern.size();
    for(int i=0; i<p_size; i++){
        if(pattern[i] == S.substr(L[up].p, sz)[i]){
            cnt++;
        }
    }
    cout<<"cnt = "<<cnt<<endl;
    if(cnt>=p_size){
        cout<<"adding "<<L[up].p<<" "<<endl;
        tmp.push_back(L[up].p);
    }
    
    int i, ok = up;
    for(i=up, ok = up; i<sz-1; i++, ok++){
        cout<<"looking at "<<S.substr(L[i].p, sz)<<" and "<<S.substr(L[i+1].p, sz)<<endl;
        cout<<"lca = "<<lca(L[i].p, L[i+1].p, P)<<endl;
        if(lca(L[i].p, L[i+1].p, P) < p_size){
            break;
        }
        cout<<"now ok = "<<ok<<endl;
    }
    cout<<"up = "<<up<<" ok = "<<ok<<endl;
    for(int i=up; i<ok; i++){
        cout<<"pushing "<<L[i+1].p<<endl;
        tmp.push_back(L[i+1].p);
    }


    cout<<"ok tmp = "<<endl;
    for(int i=0; i<tmp.size(); i++){
        cout<<tmp[i]<<" ";
    }cout<<endl;
    return tmp;
}


int main(){
    cin>>S;
    cin>>s_begin;
    cin>>s_end;
    
    sz = S.size();
    vector<int> pre = work(P1, S, s_begin);
    vector<int> suf = work(P2, string(S.rbegin(), S.rend()), string(s_end.rbegin(), s_end.rend()));
    

    cout<<"ok suf = "<<endl;
    for(int i=0; i<suf.size(); i++){
        cout<<"original = "<<suf[i]<<endl;
        suf[i] += s_end.size()-1;    
        suf[i] = sz - suf[i] - 1;
    }
    int front=0, rear = suf.size()-1;

    for(int i=0; i<pre.size(); i++){
        cout<<"pre "<<i<<" = "<<pre[i]<<endl;
    }

    for(int i=0; i<suf.size(); i++){
        cout<<"suf "<<i<<" = "<<suf[i]<<endl;
    }
    
    sort(pre.begin(), pre.end());
    sort(suf.begin(), suf.end());

    int ans =0;
    // all staring and ending points
    for(int i=0; i<pre.size(); i++){
        for(int j=0; j<suf.size(); j++){
            if(pre[i]<=suf[j]){
                ans += 1;
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}

