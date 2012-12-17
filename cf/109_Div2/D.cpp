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
int N,M;
bool state[MAXN];


set<int> activated;

int gcd(int a,int b){
    if(b==0){
        return a;
    }else{
        return gcd(b,a%b);
    }
}


int main() {
    scanf("%d %d",&N,&M);
    getchar();
    for(int i=0; i<MAXN;i++)state[i]=0;
    
    char order;
    int number;
    for(int i=0; i<M;i++){
        //cin>>order>>number;
        order = getchar();
        scanf("%d",&number);
        getchar();
        int conflict = -1;
        if(order=='+'){
            if(activated.find(number)!=activated.end()){
                printf("Already on\n");
                continue;
            }
            tr(activated, it){
                int v = (*it);
                if(gcd(v,number)!=1){
                    conflict = v;
                    break;
                }
            }
            if(conflict==-1){
                activated.insert(number);
                printf("Success\n");
            }else{
                printf("Conflict with %d\n", conflict);
            }
        }else{
            set<int>::iterator it = activated.find(number);
            if(it==activated.end()){
                printf("Already off\n");
            }else{
                activated.erase(number);
                printf("Success\n");
            }
        }
    }
    return 0;
}
