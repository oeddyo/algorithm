/*
ID: xieke.b1
PROB: lgame
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <stack>
#include <vector>
#include <string.h>

using namespace std;
ifstream fin("lgame.in");
ifstream dic_in("lgame.dict");
ofstream fout("lgame.out");


const int INF = 999999999;
int N;
string str;

typedef pair<int, string> pis;

const int MAXN = 400050;
pis words[MAXN];
int scores[MAXN];

int mapping[30] = {
    2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7
};

int target_word[30];
int word_count[30];

long long int get_hash(string &t){
    long long int h_value = 0;
    int sz = t.size();
    for(int i=0; i<sz; i++){
        if(t[i]>='a'&&t[i]<='z'){
            h_value+= mapping[t[i]-'a'];
        }
    }
    return h_value;
}

bool valid(string &s){
    memset(word_count,0,sizeof(word_count));
    int sz = s.size();
    for(int i=0; i<sz; i++){
        if(s[i]>='a' && s[i]<='z'){
            word_count[ s[i] - 'a'] +=1;
        }
    }
    for(int i=0; i<26; i++){
        if(target_word[i]<word_count[i])return false;
    }
    return true;
}

void work(){
    vector<string> res;
    int max_hash = -INF;
    for(int i=0; i<N; i++){
        max_hash = max( max_hash, scores[i]);
    }

    int three_starts=-1;
    int four_ends=-1;
    for(int i=0; i<N; i++){
        if(words[i].first==3 && three_starts==-1){
            three_starts = i;break;
        }
    }
    cout<<"three four "<<three_starts<<" "<<four_ends<<endl;
    for(int i=N-1; i>=0; i--){
        if(words[i].first==4 && four_ends==-1){
            four_ends = i;break;
        }
    }
    if(three_starts == -1)three_starts = 0;
    if(four_ends == -1)four_ends = N-1;
    string tmp;
    for(int i=three_starts; i<=four_ends; i++){
        for(int j=i+1; j<=four_ends; j++){
            tmp = words[i].second+" "+words[j].second;
            if(valid(tmp)){
                if(words[i].second>words[j].second){
                    tmp = words[j].second+" "+words[i].second;
                }else{
                    tmp = words[i].second+" "+words[j].second;
                }
                int h_value = get_hash(tmp);
                words[N] = pis(-1,tmp);
                scores[N++] = h_value;
                max_hash = max(max_hash, h_value);
            }
        }
    }

    for(int i=0; i<N; i++){
        if(max_hash==scores[i]){
            res.push_back( words[i].second );
        }
    }
    sort(res.begin(), res.end());
    fout<<max_hash<<endl;
    for(int i=0; i<res.size(); i++){
        fout<<res[i]<<endl;
    }

}


int main(){
    fin>>str;

    string tmp;
    int ptr = 0;
    for(int i=0; i<str.size(); i++){
        target_word[ str[i]-'a'] += 1;
    }
    
    while(1){
        dic_in>>tmp;
        if(tmp[0]=='.')break;
        if(valid(tmp)){
            words[ptr].first = tmp.size();
            words[ptr].second = tmp;
        }
        ptr++;
    }
    N = ptr;
    sort(words, words+N);
    for(int i=0; i<N; i++){
        scores[i] = get_hash( words[i].second );
    }
    work();
    return 0;
}

