/*
ID: xieke.b1
PROB: milk2
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <string.h>

using namespace std;

ifstream fin("milk2.in");
ofstream fout("milk2.out");

typedef pair<int, int> pii;
const int MAXN = 5500;
int data[MAXN*2];
int N,dis_data[MAXN*2];
int milk[MAXN*2];
const int INF = 999999999;
void work(){
    map <int, int> mmap;
    vector < pii > tv;
    for(int i=0; i<2*N; i+=2){
        tv.push_back( pii(data[i],i) );
        tv.push_back( pii(data[i+1], i+1) );
    }
    sort(tv.begin(), tv.end());

    int cnt = 0;
    int pre = -1;
    int sz = tv.size();
    
    for(int i=0; i<sz; i++){
        if( pre!=tv[i].first ){
            pre = tv[i].first;
            mmap[cnt] = tv[i].first;
            dis_data[tv[i].second] = cnt++;
        }else{
            dis_data[tv[i].second] = dis_data[tv[i-1].second];
        }
    }

    //cout<<"cnt is "<<cnt<<endl;
    for(int i=0; i<N*2; i+=2){
        //cout<<dis_data[i]<<" "<<dis_data[i+1]<<endl;
        //cout<<"corresponding "<<mmap[dis_data[i]]<<" "<<mmap[dis_data[i+1]]<<endl;
    }

    memset(milk,0,sizeof(milk));

    for(int i=0; i<2*N; i+=2){
        for(int j=dis_data[i]; j<dis_data[i+1]; j++){
            milk[j] = 1;
        }
    }
    /*
    for(int i=0; i<cnt; i++){
        cout<<milk[i]<<" ";
    }cout<<endl;
    */
    int ans_cont = 0;
    int ans_dis_cont = 0;

    pre = milk[0];
    int left = 0;
    for(int i=1; i<cnt; i++){
        if(milk[i]!=pre){
            if(pre==0){
                ans_dis_cont = max(ans_dis_cont, mmap[i] - mmap[left]);
            }else{
                ans_cont = max(ans_cont, mmap[i] - mmap[left]);
            }
            left = i;
            pre = milk[i];
        }
    }

    //cout<<"ans: "<<ans_cont<<" "<<ans_dis_cont<<endl;
    fout<<ans_cont<<" "<<ans_dis_cont<<endl;
}


int main(){


    while(fin>>N){
    for(int i=0; i<2*N; i+=2){
        fin>>data[i]>>data[i+1];
    }
    work();
    }

    return 0;
}

