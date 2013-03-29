#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>

using namespace std;

int T, N;

const int MAXN = 1001;
const int INF = 99999999;
const int MOD = 999983;
unsigned int seed = 31;
int half;


string strs[MAXN];
int lens[MAXN];

typedef struct entry{
    int ith, start, len;
    bool operator<(const struct entry &it) const{
        if(len<it.len)return -1;
        for(int i=0; i<len; i++){
            if(strs[ith][i+start] < strs[it.ith][i+it.start]){
                return -1;
            }else if(strs[ith][i+start] > strs[it.ith][i+it.start]){
                return 1;
            }else{
                continue;
            }
        }
        return 0;
    }
    bool operator==(const struct entry &it) const{
        if(len!=it.len)return false;
        for(int i=0; i<len; i++){
            if( strs[ith][i+start] == strs[it.ith][i+it.start]){
                continue;
            }else{
                return false;
            }
        }
        return true;
    }
}et;

typedef pair<et, int> pei;

vector < pei > hash_table[MOD];
//vector< et > answers;
//vector< et > answer_buf;
set< et > answers;
set< et > answer_buf;

set< et > myset;

void print(const et &mystr){
    for(int i=mystr.start; i<mystr.start+mystr.len; i++){
        cout<<strs[mystr.ith][i];
    }cout<<endl;
}

unsigned int hash_func(et &str){
    unsigned int hash = 0;
    for(int i=str.start; i<str.start+str.len; i++){
        hash = (hash * seed + strs[str.ith][i])%MOD;
    }
    return hash%MOD;
}

void insert(et &str, unsigned int h){
    int t_size = hash_table[h].size();
    //cout<<"Inserting ";print(str);cout<<endl;
    if(t_size==0){
        pei ns(str, 1);
        hash_table[h].push_back(ns);
    }else{
        bool exist = false;
        for(int j=0; j<t_size; j++){
            if(str == hash_table[h][j].first){
                hash_table[h][j].second+=1;
                //cout<<"current counting = "<<hash_table[h][j].second<<endl;
                if(hash_table[h][j].second>half){
                    //answers.push_back( hash_table[h][j].first);
                    answers.insert(hash_table[h][j].first);
                }
                exist = true;
                break;
            }
        }
        if(!exist){
            pei ns(str, 1);
            hash_table[h].push_back(ns);
        }
    }
}


bool mark[1002];
bool judge( int cur_length){
    for(int i=0; i<MOD; i++)hash_table[i].clear();
    unsigned RM = 1;
    for(int i=1; i<cur_length; i++){
        RM = (seed*RM)%MOD;
    }
    //cout<<"RM = "<<RM<<endl;

    for(int i=0; i<N; i++){
        int len = lens[i];
        et net;
        if(len<cur_length)continue;
        net.ith = i;net.start=0;net.len=cur_length;
        memset(mark,0,sizeof(mark));
        myset.clear();
        myset.insert(net);
        for(int j=1; j+cur_length-1<len; j++){
            net.ith = i;net.start=j;net.len=cur_length;
            myset.insert(net);
        }
        //cout<<"set size = "<<myset.size()<<endl;

        //cout<<"initial string is ";print(net);
        //cout<<" with hash value "<<h<<endl;
        set< et >::iterator myIt;
        vector<int> tmp;
        for(myIt = myset.begin(); myIt!=myset.end(); myIt++){
            tmp.push_back(myIt->start);
            mark[myIt->start] = 1;
        }

        net.ith = i;net.start=0;net.len=cur_length;
        unsigned int h = hash_func(net); 
        insert(net, h);
        for(int j=1; j+cur_length-1<len; j++){
            unsigned int new_h = (h  + MOD - (RM*strs[i][j-1])%MOD)%MOD ;
            //cout<<"deleting "<<strs[i][j-1]<<" adding "<<strs[i][j+cur_length-1]<<endl;
            new_h = (new_h*seed + strs[i][j+cur_length-1])%MOD;
            net.ith = i;net.start=j;net.len=cur_length;
            /*
            cout<<"now checking ";
            print(net);
            cout<<" with hash value "<<new_h<<endl;
            */
            
            h = new_h;
            if(mark[j]){
                insert(net, new_h);
            }
        }
    }
    

    if(answers.size()>0){
        return true;
    }
    return false;
}

void work(){
    int max_length = -INF;
    for(int i=0; i<N; i++){
        lens[i] = strs[i].size();
        max_length = max(max_length, lens[i]);
    }
    int low = 1, high = max_length, ans = -INF;
    while(low<=high){
        int mid = (high+low)/2;
        if(judge(mid)){
            ans = mid;
            low = mid+1;
            answer_buf = answers;
            answers.clear();
        }else{
            high = mid-1;
        }
    }
    
    if(answer_buf.size()==0){
        cout<<"?"<<endl;
    }else{
        set<et>::iterator myIt;
        vector< et > result;
        for(myIt = answer_buf.begin(); myIt!=answer_buf.end(); myIt++){
            //print( (*myIt) );
            result.push_back( *myIt);
        }
        sort(result.begin(), result.end());
        for(int i=0; i<result.size(); i++){
            print(result[i]);
        }
        cout<<endl;
    }
    answers.clear();
    answer_buf.clear();
}

int main(){
    while(cin>>N){
        if(N==0)break;
        for(int i=0; i<N; i++){
            cin>>strs[i];
        }
        half=N/2;
        work();
    }
    return 0;
}
