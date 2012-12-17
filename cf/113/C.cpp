#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;


int n,x;
const int MAXN = 100000;
int d[MAXN];

int get_ans(){
    int left = -1,right = -1;
    for(int i=1; i<=n; i++){
        if(d[i]==x){
            left = i;
            break;
        }
    }
    for(int i=n; i>=1; i--){
        if(d[i]==x){
            right =i;break;
        }
    }
    int ans=1;    
    int m = floor(1.0*(n+1)/2);
    cout<<"in func"<<endl;    
    if(left<=m && right>=m){
            ans += 0;
        }
        if(left>m){
            ans += (left-1)-(n-left);
        }else if(right<m){
            ans += (n-right)-(right);
        }
        return ans;
}

int main(){
    scanf("%d %d",&n,&x);

    for(int i=1; i<=n; i++){
        scanf("%d",&d[i]);
    }
    sort(d,d+n);
    int left = -1,right = -1;
    for(int i=1; i<=n; i++){
        if(d[i]==x){
            left = i;
            break;
        }
    }
    for(int i=n; i>=1; i--){
        if(d[i]==x){
            right =i;break;
        }
    }
    int ans = -1;
    if(left==-1){
        //not in list
        if(x>d[n]){
           ans = 1+n;           
        }else if( x<d[1]){
            ans = 1+ n-1;
        }else{
            for(int i=1; i<=n; i++){
                right = i;
                if(d[i]>x){
                    break;
                }
            }
            //cout<<"now right is "<<right<<endl;
            //ans =1+ max(right-1, 1+n-right) - min(right-1, 1+n-right); 
            d[n+1] = x;
            n++;
            sort(d+1,d+1+n);
            ans = get_ans();
        }
    }else{
        int m = floor(1.0*(n+1)/2);
        if(left<=m && right>=m){
            ans = 0;
        }
        if(left>m){
            ans = (left-1)-(n-left);
        }else if(right<m){
            ans = (n-right)-(right);
        }
    }
    cout<<ans<<endl;

    return 0;
}

