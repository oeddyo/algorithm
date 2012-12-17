/*
ID: xieke.b1
PROB: ratios
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string.h>
#include <cmath>

using namespace std;

ifstream fin("ratios.in");
ofstream fout("ratios.out");

typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 50;
const int INF = 2100000000;
int N;

int A[3][3];
int B[3];


void work(){
    int record[4] = {-1,-1,-1,-1};
    int min_ans = INF;
    for(int x=0; x<=100; x++){
        for(int y=0; y<=100; y++){
            for(int z=0; z<=100; z++){
                int tmp[3]={0,0,0};
                int scalar[3] = {x,y,z};
                for(int j=0; j<3; j++){
                    for(int i=0; i<3; i++){
                        tmp[i]+=scalar[j]*A[i][j];
                    }
                }
                bool zeros[3] = {0,0,0};

                for(int i=0; i<3; i++)if(B[i]==0)zeros[i]=1;
                
                bool ok = true;
                int times = -1;
                if(x==1 && y==0 && z==2){
                    cout<<"***"<<endl;
                    for(int i=0; i<3; i++){
                        cout<<tmp[i]<<" ";
                    }
                    cout<<endl;
                }


                for(int i=0; i<3; i++){
                    if(zeros[i]==1){
                        if(tmp[i]!=0){
                            ok=false;
                            break;
                        }
                    }else{
                        if(tmp[i]%B[i]==0){
                            if(times==-1){
                                times = tmp[i]/B[i]; 
                            }else{
                                int t = tmp[i]/B[i];
                                if(t!=times){
                                    ok=false;
                                    break;
                                }
                            }
                        }else{
                            ok = false;
                            break;
                        }
                    }
                }
                if(ok){
                    int sum = x+y+z;
                    if(sum==0)continue;
                    //cout<<"sum is "<<sum<<endl;
                    if(sum<min_ans){
                        min_ans = sum;
                        record[0] = x, record[1]=y, record[2]=z, record[3] = tmp[0]/B[0];
                    }
                }
            }
        }
    }
    if(record[0]==-1){
        fout<<"NONE"<<endl;
    }else{
        fout<<record[0]<<" "<<record[1]<<" "<<record[2]<<" "<<record[3]<<endl;
    }
}


int main(){
    double tmp_d;
    for(int i=0; i<3; i++){
        fin>>B[i];
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            fin>>A[j][i];
        }
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<A[i][j]<<" ";
        }cout<<endl;
    }
    work();
    return 0;
}

