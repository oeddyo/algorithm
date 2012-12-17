/*
ID: xieke.b1
PROG: crypt1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;
ofstream fout("crypt1.out");
ifstream fin ("crypt1.in");
int N;
int nums[11];
bool is_num[11];
bool in_set(int k){
    while(k){
        if(!is_num[ k%10 ] ){
            return false;
        }
        k/=10;
    }
    return true;
}


int main(){
    fin>>N;
    memset(is_num,0,sizeof(is_num));
    for(int i=0; i<N; i++){
        fin>>nums[i];
        is_num[nums[i]]=1;
    }

    int cnt=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                for(int l=0; l<N; l++){
                    for(int m=0; m<N; m++){
                        int a=nums[i], b=nums[j], c=nums[k], d=nums[l], e=nums[m];
                        int top = a*100+b*10+c;
                        int down = d*10+e;


                        int r1 = top*e;
                        int r2 = top*d;
                        int r3 = top*e + top*d*10;
                        if(a==2&&b==2&&c==2&&d==2&&e==2){
                            cout<<top<<" "<<down<<" "<<r1<<" "<<r2<<" "<<r3<<endl;
                        }
                        if( r1>=100&&r1<=999 && r2>=100&&r2<=999 && r3>=1000&&r3<=9999&&  in_set(top*e) && in_set(r2) && in_set(r3) ){
                            cout<<"yes "<<top<<" "<<down<<" "<<r1<<" "<<r2<<" "<<r3<<endl;
                            cnt++;
                        }

                    }
                }
            }
        }
    }

    fout<<cnt<<endl;
    
    
    return 0;
}

