/*
ID: xieke.b1
PROB: spin
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string.h>
#include <cmath>

using namespace std;

ifstream fin("spin.in");
ofstream fout("spin.out");

typedef pair<int, int> pii;
const int MAXN = 501;
const int INF = 999999999;

typedef struct _wheel{
    int speed;
    vector< pii > wedge;
}whell;

whell w[5];

int degree[361];
int ans = -1;

void work(){
    for(int time=0; time<=360; time++){
        memset(degree,0, sizeof(degree));
        for(int i=0; i<5; i++){
            int extra = w[i].speed*time;
            if(time==8)
                cout<<"extra is "<<extra<<endl;
            for(int j=0; j<w[i].wedge.size(); j++){
                int start = (w[i].wedge[j].first+extra)%360;
                int length = w[i].wedge[j].second;
                if(time==8)
                cout<<"for "<<i<<" start and end = "<<start<<" "<<start+length<<endl;
                for(int k=start; k<=start+length; k++){
                    int ind = k%360;
                    if(time==8)
                        cout<<"doing for "<<ind<<endl;
                    degree[ind]+=1;
                    if(degree[ind]==5){
                        cout<<"ind is "<<ind<<endl;
                        ans = time;
                        return ;
                    }
                }
            }
        }
    }
}



int main(){
    for(int i=0; i<5; i++){
        int speed;
        fin>>speed;
        w[i].speed = speed;
        int k;
        fin>>k;
        for(int j=0; j<k; j++){
            int a,b;
            fin>>a>>b;
            w[i].wedge.push_back( pii(a,b));
        }
    }
    work();
    if(ans==-1){
        fout<<"none"<<endl;
    }else{
        fout<<ans<<endl;
    }
    return 0;
}

