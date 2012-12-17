/*
ID: xieke.b1
PROG: packrec
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <string.h>

using namespace std;

ofstream fout("packrec.out");
ifstream fin ("packrec.in");

typedef pair<int, int> pii;

pii rec[4];
bool used[4];
vector< pii > ans;
typedef vector< pii > vp;

map< pii, int > mymap;


const int INF = 99999999;
int get_sum(vp p, int start, int end, int f_s){
    int t_sum = 0;
    for(int i=start; i<=end; i++){
        if(f_s==0){
            t_sum+=p[i].first;
        }else{
            t_sum+=p[i].second;
        }
    }
    return t_sum;
}
int get_max(vp p, int start, int end, int f_s){
    int t_max = -INF;
    for(int i=start; i<=end; i++){
        if(f_s==0){
            t_max = max(t_max, p[i].first);
        }else{
            t_max = max(t_max, p[i].second);
        }
    }
    return t_max;
}

void dfs(vp p){
    if(p.size()==4){
        int wid, len;
        wid = get_sum(p,0,3,0);
        len = get_max(p,0,3,1);
        ans.push_back( pii(wid, len) );
        //2
        wid = max(get_sum(p,0,2,0), p[3].first);
        len = get_max(p,0,2,1)+p[3].second;
        ans.push_back( pii(wid, len) );
        
        //3
        wid = get_sum(p,0,2,0);
        wid = max(wid, p[3].first+p[2].first);
        len = max(get_max(p,0,1,1)+p[3].second,p[2].second);
        ans.push_back( pii(wid, len) );
        //4
        wid = p[0].first+ max(p[1].first,p[2].first) +p[3].first;
        len = max(max(p[0].second, (p[1].second+p[2].second)), p[3].second);
        ans.push_back( pii(wid, len) );
        //6...
        wid = p[0].first+p[1].first;
        len = max(p[0].second+p[2].second,    p[1].second+p[3].second );
        if( p[0].second<p[1].second){
            wid = max(wid, p[2].first+p[1].first);
        }
        if( p[2].second+p[0].second > p[1].second){
            wid = max(wid, p[3].first+p[2].first);
        }
        if( p[1].second < p[0].second){
            wid = max(wid, p[0].first+p[3].first);
        }
        wid = max(p[2].first, max(p[3].first,wid) );

        if(wid*len==480){
            cout<<"now vector is "<<endl;
            for(int i=0; i<4; i++){
                cout<<p[i].first<<" "<<p[i].second<<endl;
            }
            cout<<"and the wid, len is "<<wid<<" "<<len<<endl;
        }
        ans.push_back( pii(wid, len) );
        return; 
    }
    for(int i=0; i<4; i++){
        if(!used[i]){
            used[i] = true;
            vp np = p;
            np.push_back(rec[i]);
            dfs(np);
            used[i] = false;
            
            used[i] = true;
            int first = rec[i].second;
            int second = rec[i].first;
            np = p;
            np.push_back(pii(first, second) );
            dfs( np  );
            used[i] = false;
        }
    } 
}

bool my_cmp(const pii &a, const pii &b){
    if(a.first*a.second == b.first*b.second){
        if(a.first==b.first){
            return a.second<b.second;
        }else{
            return a.first<b.first;
        }
    }else{
        return a.first*a.second<b.first*b.second;
    }
}

void work(){
    vector < pii > vp;
    memset(used,0,sizeof(used));
    dfs(vp);
    for(int i=0; i<ans.size(); i++){
        //cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
    for(int i=0; i<ans.size(); i++){
        if(ans[i].first>ans[i].second){
            swap(ans[i].first, ans[i].second);
        }
    }

    sort(ans.begin(), ans.end(), my_cmp);
    int tmp=ans[0].first*ans[0].second;
    cout<<"best is "<<tmp<<endl;
    fout<<tmp<<endl;
    for(int i=0; i<ans.size(); i++){
        int prod = ans[i].first*ans[i].second;
        if(prod==tmp){// && ans[i].first<=ans[i].second){
            pii t;
            if(ans[i].first<ans[i].second){
                t.first = ans[i].first, t.second = ans[i].second;
            }else{
                t.first = ans[i].second, t.second = ans[i].first;
            }
            if( mymap.find(t)==mymap.end()){
                fout<<t.first<<" "<<t.second<<endl;;
                mymap[t]=1;
            }
        }

    }

    cout<<ans[0].first<<" "<<ans[0].second<<endl;

}

int main(){
    for(int i=0; i<4; i++){
        fin>>rec[i].first>>rec[i].second;
    }
    work();
    return 0;
}

