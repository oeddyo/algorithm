#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
using namespace std;
 
#define DEBUG
#define REP(i,a) for(i=0;i<a;i++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define VE vector<int>
#define SZ size()
#define PB push_back
int N;

int A[] = {
    1,
    3, 
    9 ,
    27 ,
    81 ,
    43 ,
    29 ,
    87 ,
    61 ,
    83 ,
    49 ,
    47 ,
    41 ,
    23 ,
    69 ,
    7 ,
    21 ,
    63 ,
    89 ,
    67 
};

int B[] = {
    4 ,
    8 ,
    16 ,
    32 ,
    64 ,
    28 ,
    56 ,
    12 ,
    24 ,
    48 ,
    96 ,
    92 ,
    84 ,
    68 ,
    36 ,
    72 ,
    44 ,
    88 ,
    76 ,
    52 };


int C[] = {
    4, 
    16 ,
    64 ,
    56 ,
    24 ,
    96 ,
    84 ,
    36 ,
    44 ,
    76 ,
    };





int main(){

    int a=20, b=20, c=10;
    cin>>N;
    
    if(N==1){
        cout<<1<<endl;
        return 0;
    }else if(N==2){
        cout<<1<<endl;
        return 0;
    }


    int pa = 3, pb=1, pc=2;
    //N = myN;
    N -= 3;
    

    for(int i=0; i<N; i++){
        pa++, pb++, pc++;
        if(pa==a)pa = 0;
        if(pb==b)pb = 0;
        if(pc==c)pc = 0;
    }

    //cout<<"Now N = "<<myN<<endl;
    //cout<<pa<<" "<<pb<<" "<<pc<<endl;

    int s = A[pa]+B[pb]+C[pc] + 1;
    //cout<<"and sum = "<<s<<endl;
    //cout<<"s = "<<s<<endl;
    if(s%100==0){
        cout<<2<<endl;
    }else if(s%10==0){
        cout<<1<<endl;
    }else{
        cout<<0<<endl;
    }



    return 0;
}

