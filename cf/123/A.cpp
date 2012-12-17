#include <iostream>

using namespace std;

int main(){
    int a,b,c;
    while(cin>>a>>b>>c){
        int ans;
        for(int x=0; x<=1000*1000; x++){
            if( a*c-b*x>=0 &&   b*c*1.0 >= (a*1.0*c-b*x) ){
                ans = x;
                break;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}

