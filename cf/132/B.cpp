#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>

using namespace std;
const int MAXN = 5001;

const double eps = 1e-10;
double xs[MAXN], ys[MAXN], zs[MAXN];
double A,B;
int n,m, k;

double ans = 0.0;

void work(){
   int r1 = xs[n-1];
   int p1 = ys[m-1];
   int p2 = zs[0];
   
   double t = r1*r1;
   t = t*B;

   ans = t*1.0/(p2*A*1.0/p1 + B*1.0);
   //ans = B*r1*r1*1.0/(p2*A*1.0/p1 + B*1.0);
   ans = sqrt(ans);
   cout.precision(12);
   cout.setf(ios::fixed,ios::floatfield); 
   cout<<ans<<endl;

}


int main(){
    cin>>n; 
    for(int i=0; i<n; i++)cin>>xs[i];
    cin>>m;
    sort(xs,xs+n);
    for(int i=0; i<m; i++)cin>>ys[i];
    sort(ys,ys+m);
    cin>>k;
    for(int i=0; i<k; i++)cin>>zs[i];
    sort(zs,zs+k);

    cin>>A>>B; 
    work();


    return 0;
}

