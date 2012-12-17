#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;


int n,x;
const int MAXN = 100000;
int d[MAXN];

int first_ele(int x){
    for(int i=1; i<=n; i++){
        if(d[i]==x){
            return i;
        }
    }
    return -1;
}

int last_ele(int x){
    for(int i=n; i>=1; i--){
        if(d[i]==x)return i;
    }
    return -1;
}


int main(){
    scanf("%d %d",&n,&x);

    for(int i=1; i<=n; i++){
        scanf("%d",&d[i]);
    }
    int ans = 0;
    if(first_ele(x)==-1){
        n++;
        d[n] = x;
        ans = 1;
    }
    sort(d+1,d+n+1);
    int left = first_ele(x);
    int right = last_ele(x);
    int mid = floor( (1.0+double(n))/2);

    if(left<=mid && right>=mid){
        ans +=0;
    }else if(right<mid){
        ans += n-right - right;
    }else if(left>mid){
        ans += left-1 - (n-left);
    }
    cout<<ans<<endl;


    return 0;
}

