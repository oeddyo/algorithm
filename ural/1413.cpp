#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
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
 
string S;
int dir[2][2];
// up/left

void work(){
    int sz = S.size();
    
    for(int i=0; i<sz; i++){
        if(S[i] == '7'){
            dir[0][1] += 1;
            dir[1][1] += 1;
        }else if(S[i] == '8'){
            dir[0][0] += 1;
        }else if(S[i] == '9'){
            dir[0][1] += 1;
            dir[1][1] -= 1;
        }else if(S[i] == '4'){
            dir[1][0] += 1;
        }else if(S[i] == '5'){

        }else if(S[i] == '6'){
            dir[1][0] -= 1;
        }else if(S[i] == '1'){
            dir[0][1] -= 1;
            dir[1][1] += 1;
        }else if(S[i] == '2'){
            dir[0][0] -= 1;
        }else if(S[i] == '3'){
            dir[0][1] -= 1;
            dir[1][1] -= 1;
        }else if(S[i] == '0'){
            break;
        }
    }


    double f = 0.70710678118654752440084436210485;

    double vertical = 0.0;
    vertical += dir[0][0];
    vertical += dir[0][1] * f;
    
  
    double horizon = 0.0;
    horizon += dir[1][0];
    horizon += dir[1][1] * f;
    if(horizon!=.0)
        horizon *= -1.0;
    
    cout<<setprecision(10)<<fixed<<horizon<<" "<<vertical<<endl;
}

int main(){


    cin>>S;

    work();

   
        
    return 0;
}

