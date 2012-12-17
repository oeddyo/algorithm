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

typedef struct{
    int a, b;

}card;

card cards[MAXN];

int comp(const void *A, const void  *B){
    card *C = (card *)(A);
    card *D = (card *)(B);
    
    if(C->b == D->b){
        if(C->a==D->a){
            return 0;
        }else if(C->a<D->a){
            return 1;
        }else{
            return -1;
        }
        //return C->a < D-> a;
    }
    if(C->b< D->b){
        return 1;
    }else{
        return -1;
    }
    //return C->b < D->b;
}

void work(){
    qsort(cards,N, sizeof(card), comp);
   /* 
    for(int i=0; i<N; i++){
        cout<<cards[i].a<<" "<<cards[i].b<<endl;
    }*/
    int counter = 1, points = 0;
    for(int i=0; i<N; i++){
        counter+=cards[i].b;
        points +=cards[i].a;
        counter = counter-1;
        if(counter==0){
            break;
        }
    }
    cout<<points<<endl;
}

int main() {
  
    cin>>N;
    for(int i=0; i<N;i++){
        cin>>cards[i].a>> cards[i].b;
    }
    work();
    return 0;
}
// END KAWIGIEDIT TESTING
