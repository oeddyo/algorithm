#include <iostream>
using namespace std;
int min(int a,int b){
    return a<b?a:b;
}

int main(){
    int n,k,l,c,d,p,nl,np;
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;
    int drink = k*l/nl;
    int lime = c*d;
    int salt = p/np;
    int toast = drink;
    toast = min(toast, lime);
    toast = min(toast, salt);
    cout<<toast/n<<endl;
    return 0;
}

