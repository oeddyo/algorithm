#include <iostream>

using namespace std;
int s, t;

int main(){
    while(cin>>s>>t){
        int sum = 0;
        int p = -1;
        for(int i=1; i<=4; i++){
            sum+=s;
            p = i;
            if(sum-(5-i)*t >= 0){
                p-=1;
                break;
            }
        }
        //cout<<"p is "<<p<<endl;
        int res = (p*2)*s - t*(5-p)*2 ;
        //cout<<"res now is "<<res<<endl;
        if(p>=2){
            res+=2*s;
        }else{
            res += -(2-p)*t+p*s;
        }
        //cout<<" final res "<<res<<endl;
        if(res>=0){
            cout<<res<<endl;
        }else if (res<0){
            cout<<"Deficit"<<endl;
        }
    }

    return 0;
}

