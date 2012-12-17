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

#define MAXN 10001
using namespace std;
int N;
int data[MAXN];

int main() {
  
    cin>>N;
    for(int i=0; i<N;i++){
        cin>>data[i];
    }
    int cnt = 0;
    for(int i=1; i<N; i++){
        int amazing = 1;
        for(int j=0; j<i; j++){
            if(data[j] < data[i])
                continue;
            amazing = 0;
            break;
        }
        if(amazing){
            cnt++;
            continue;
        }
        amazing = 1;
        for(int j=0; j<i; j++){
            if(data[j] > data[i]){
                continue;
            }
            amazing = 0;
            break;
        }
        if(amazing)cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
// END KAWIGIEDIT TESTING
