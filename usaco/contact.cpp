/*
ID: xieke.b1
PROB: contact
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

ifstream fin("contact.in");
ofstream fout("contact.out");

#define all(c) (c).begin(), (c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i!=(c).end(); i++)
typedef pair<int, int> pii;
typedef pair<int, string> pis;
const int MAXN = 200001;
const int INF = 2100000000;
const int MAX_HASH = 999983;
int N;
string S;


int A,B;

map<int, int> mymap;

typedef struct _node{
    string s;
    int cnt;
}node;

vector< node> hash[MAX_HASH];

unsigned int hash_func(string &tmp){
    unsigned int seed = 31; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;
    int str = 0;
    while (tmp[str]){
        hash = hash * seed + tmp[str++];
    }
    return (hash % MAX_HASH);
}



void insert(string &tmp_sum, int index){
    node tmp;
    tmp.s = tmp_sum;
    tmp.cnt = 1;
    //cout<<"insert "<<tmp.s<<endl;
    hash[index].push_back(tmp);
}

int is_in(string &t, int index){
    int t_sz = hash[index].size();
    for(int i=0; i<t_sz; i++){
        if(hash[index][i].s==t){
            hash[index][i].cnt+=1;
            return hash[index][i].cnt;
        }
    }
    return 0;
}
int convert(const string &s){
    int tmp = 0;
    for(int i=0; i<s.size(); i++){
        tmp = (tmp<<1) + s[i]-'0';
    }return tmp;
}

bool mycmp(const node &a, const node &b){
    if( a.cnt==b.cnt){
        if(a.s.size()==b.s.size()){
            //cout<<a.s<<" converts to "<<convert(a.s)<<endl;
            return convert(a.s) < convert(b.s);
        }else{
            return a.s.size()<b.s.size();
        }
    }else{
        return a.cnt>b.cnt;
    }
}

void work(){
    int sz = S.size();
    for(int i=0; i+A-1<sz; i++){
        string tmp_sum="";
       // cout<<"i'm at "<<i<<endl;
        for(int j=0; j<A-1; j++){
            tmp_sum += S[i+j];
        }
        for(int j=A-1; j<B && i+j<sz; j++){
            tmp_sum+=(S[i+j]);
            //cout<<"gene "<<tmp_sum<<endl;
            int index = hash_func( tmp_sum );
            if( is_in(tmp_sum, index)!=0 ){
                //do nothing
            }else{
                insert(tmp_sum, index);
            }
        }
    }
    vector<node> data;
    for(int i=0; i<MAX_HASH; i++){
        int t_sz = hash[i].size();
        for(int j=0; j<t_sz; j++){
            //cout<<"push back "<<hash[i][j].s<<endl;
            data.push_back(hash[i][j]);
        }
    }
    sort(data.begin(), data.end(), mycmp);

    int t_sz = data.size();
    int outputed = 0;
    int pre = -1;
    int output_counter = 0;
    for(int i=0; i<t_sz; i++){
        if(data[i].cnt!=pre){
            if(outputed>=N)break;
            if(pre!=-1 && output_counter!=0)
                fout<<endl;
            pre = data[i].cnt;
            outputed+=1;
            fout<<data[i].cnt<<endl;
            fout<<data[i].s;
            output_counter = 1;
        }else{
            if(output_counter==0){
                fout<<data[i].s;
                output_counter+=1;
            }else{
                fout<<" "<<data[i].s;
                if(output_counter==5){
                    fout<<endl;
                    output_counter = 0;
                }else{
                    output_counter+=1;
                }
            }
        }
    }
    if(output_counter!=0)
        fout<<endl;

}



int main(){
    fin>>A>>B>>N;
    string str;
    while(getline(fin, str) ){
        S+=str;
    }
    work();
    return 0;
}

