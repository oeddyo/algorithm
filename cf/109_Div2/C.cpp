#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>



//#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define tr(container, it) \
      for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 

#define MAXN 100000
using namespace std;

vector<string>forbid;
int N,M;
string str;
void work(){
    int cnt=0;
    for(int i=0; i<N*2;i++){
        if(str.find(forbid[i])!=str.end()){
            cnt++;
        }
    }
    cout<<cnt<<endl;
}


int main() {
    cin>>str;
    cin>>N;
    for(int i=0; i<N;i++){
        string t;
        cin>>t;
        forbid.push_back(t);
        char ch = t[0];
        t[0] = t[1];
        t[1] = ch;
        forbid.push_back(t);
    }
    work();
    return 0;
}
