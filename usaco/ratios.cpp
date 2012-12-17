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
const int MAXN = 50;
const int INF = 2100000000;
int N;

typedef vector<double> vd;

vector<double> A[3];
vector<double> b;

void print(vd AAA[]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<AAA[i][j]<<"\t";
        }cout<<endl;
    }

}
vd final_ans;


bool eliminate( int k){
    vd bb;
    vd ans;
    for(int i=0; i<3; i++){
        bb.push_back(k*b[i]);
    
        cout<<"push_back "<<k*b[i]<<endl;
        cout<<"bb[i] "<<bb[i]<<endl;
    }
    vd AA[3];
    for(int i=0; i<3; i++)AA[i] = A[i];
    
    for(int i=0; i<3; i++){
        AA[i].push_back(bb[i]);
    }
    cout<<"--before--"<<endl;
    print(AA);
    for(int i=0; i<3; i++){
        for(int j=i+1; j<3; j++){
            double times = AA[j][i]/AA[i][i];
            for(int k=0; k<4; k++){
                AA[j][k] -= AA[i][k]*times;
            }
        }
    }
    
    //back elimination
    cout<<"-------"<<endl;
    print(AA); 
    for(int i=2; i>=0; i--){
        for(int j=i-1; j>=0; j--){
            double times = AA[j][i]/AA[i][i];
            for(int k=0; k<4; k++){
                AA[j][k] -= AA[i][k]*times;
            }
        }
    }
    
    for(int i=0; i<3; i++){
        AA[i][3] /= AA[i][i];
        AA[i][i] = 1;
    }
    
    for(int i=0; i<3; i++){
        ans.push_back(AA[i][3]);
    }
    bool ok = true; 
    for(int i=0; i<3; i++){
        int t = ( (int) ans[i]);
        cout<<"ans[i] "<<ans[i]<<" t is "<<t<<endl;
        if( fabs(t-ans[i])<=1e-9 ){
        
        }else{
            ok = false;
            cout<<"false !!! now t="<<t<<" ans="<<ans[i]<<endl;
            break;
        }
    }

    cout<<"--back--"<<endl;
    print(AA);
    cout<<"k is "<<k<<" ok is "<<ok<<endl;
    if(ok){
        final_ans = ans;
    }

    return ok;
}

void work(){
    //eliminate(7);
    for(int k=1; k<=16; k++){
        if(eliminate(k)){
            for(int i=0; i<3; i++){
                fout<<final_ans[i]<<" ";
            }
            fout<<k<<endl;
            break;
        }
    }
}


int main(){
    double tmp_d;
    for(int i=0; i<3; i++){
        fin>>tmp_d;
        b.push_back(tmp_d);
    }
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            fin>>tmp_d;
            A[j].push_back(tmp_d);
        }
    }
    work();
    return 0;
}

