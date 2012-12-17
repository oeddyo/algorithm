/*
ID: xieke.b1
PROG: sort3
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>

using namespace std;

ofstream fout("sort3.out");
ifstream fin ("sort3.in");
const int INF = 999999999;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define all(c) (c).begin(), (c).end()
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
const int MAXN = 1002;
int N, data[MAXN];

int nums[4];

void print(){
    for(int i=0; i<N; i++){
        cout<<data[i]<<" ";
    }cout<<endl;
}

int counts[4][4];

void work(){
    //sort(data,data+N);
    /*
    for(int i=1; i<=3; i++){
        cout<<nums[i]<<" ";
    }

    cout<<endl;
*/
    for(int i=0; i<N; i++){
        if(i<nums[1]){
            if(data[i]==2){
                counts[1][2] ++;
            }else if(data[i]==3){
                counts[1][3]++;
            }
        }
        else if(i>=nums[1] && i<nums[1]+nums[2]){
            if(data[i]==1){
                cout<<"now i "<<i<<endl;
                counts[2][1]++;
            }
            else if(data[i]==3){
                counts[2][3]++;
            }
        }else if(i>=nums[1]+nums[2]){
            if(data[i]==1){
                counts[3][1]++;
            }else if(data[i]==2){
                counts[3][2]++;
            }
        }
    }
    
    for(int i=1; i<=3; i++){
        for(int j=1; j<=3; j++){
            cout<<counts[i][j]<<" ";
        }cout<<endl;
    }


    int final_ans = 0;
    for(int i=1; i<=3; i++){
        for(int j=i+1; j<=3; j++){
            int m = min(counts[i][j], counts[j][i]);
            counts[i][j]-=m;
            counts[j][i]-=m;
            final_ans+=m;
        }
    }

    final_ans+= min(counts[1][3], min(counts[3][2], counts[2][1]))*2;
    final_ans+= min(counts[1][2], min(counts[2][3], counts[3][1]))*2;

    fout<<final_ans<<endl;
}

int main(){
    fin>>N;
    for(int i=0; i<N; i++){
        fin>>data[i];
        nums[data[i]]++;
    }
    work();
    return 0;
}
