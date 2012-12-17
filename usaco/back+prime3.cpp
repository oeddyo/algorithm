/*
ID: xieke.b1
PROB: prime3
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <stack>
#include <vector>
#include <string.h>

using namespace std;
ifstream fin("prime3.in");
ofstream fout("prime3.out");

const int INF = 999999999;
int N;
typedef vector<int> vi;
typedef vector<string> vs;
vs ans;
const int MAXN = 30000;

int prime_sum, init;

int cnt = 0;

//vector<int> primes;
vector<int> counts[50];

int prime(){
    memset(counts,0,sizeof(counts));
    for(int i=10000; i<=99999; i++){
        bool is_prime = true;
        for(int j=2; j*j<=i; j++){
            if(i%j==0){
                is_prime = false;
                break;
            }
        }
        if(is_prime){
            //primes.push_back(i);
            int t = i, sum=0;
            while(t){
                sum+=t%10;
                t/=10;
            }
            if(i/10000==0)
                continue;
            counts[sum].push_back(i);
        }
    }
}

int primes[700][5];
void break_down(vector<int> vp){
    memset(primes,-1,sizeof(primes));
    for(int i=0; i<vp.size(); i++){
        int p = vp[i];
        int dig = 4;
        while(p){
            primes[i][dig] = p%10;
            dig--;
            p/=10;
        }
        cnt = i;
    }
}

pair<string, vector<int> > sv [100];

int work(){
    for(int i=0; i<50; i++){
        cout<<counts[i].size()<<" "<<i<<endl;;
    }
    cout<<"***"<<endl;
    vector<int> vp = counts[prime_sum];
    cout<<"all "<<vp.size()<<endl;
    for(int i=0; i<vp.size(); i++){
        cout<<vp[i]<<endl;
    }

    break_down(vp);
    int sz = vp.size(); 
    int ccc = 0;

    for(int a=0; a<sz; a++){
        cout<<a<<endl;
        if(primes[a][0]!=init)continue;
        for(int i=0; i<sz; i++){
            if(primes[i][0]!=primes[a][0])continue;
            for(int j=0; j<sz; j++){
                //the diagnals
                if(primes[i][2]!=primes[j][2] || primes[j][4]!=primes[a][4])continue;
                for(int p=0; p<sz; p++){
                    if(primes[a][0]!=primes[p][0] || primes[j][0]!=primes[p][4])continue;
                    for(int r=0; r<sz; r++){
                        if(primes[a][5]!=primes[r][0] || primes[i][5]!=primes[r][5])continue;
                        for(int k=0; k<sz; k++){
                            if(primes[k][1]!=primes[i][1] || primes[k][3]!=primes[j][3] || primes[k][0]!=primes[p][1] || primes[k][4]!=primes[r][1])continue;
                            for(int l=0; l<sz; l++){
                                if(primes[l][2]!=primes[i][2] || primes[l][0]!=primes[p][2] || primes[l][4]!=primes[r][2]  )continue;
                                for(int m=0; m<sz; m++){
                                    if(primes[m][3]!=primes[i][3] || primes[m][1]!=primes[j][1] || primes[m][0]!=primes[p][3] || primes[m][4]!=primes[r][3])continue;
                                    for(int n=0; n<sz; n++){
                                        if(primes[n][4]!=primes[i][4] || primes[n][4]!=primes[j][4] || primes[n][0]!=primes[p][4] || primes[n][4]!=primes[r][4])continue;
                                        //ok here;
                                        bool ok = true;
                                        ccc++;
                                        for(int x = 0; x<5; x++){
                                            int sum = 0;
                                            //sum = primes[p][x] + primes[k][x]+primes[l][x] + primes[m][x]+primes[n][x];
                                            /*
                                               cout<<vp[p]<<endl;
                                               cout<<vp[k]<<endl;
                                               cout<<vp[l]<<endl;
                                               cout<<vp[m]<<endl;
                                               cout<<vp[n]<<endl;
                                               */
                                            if(sum!=prime_sum){
                                                ok = false;break;
                                            }
                                        }
                                        /*
                                           if(ok){
                                           cout<<p<<endl;
                                           cout<<k<<endl;
                                           cout<<l<<endl;
                                           cout<<m<<endl;
                                           cout<<n<<endl;
                                           }*/

                                    }

                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<ccc<<endl;
}

int main(){
    prime();
    fin>>prime_sum>>init; 
    work(); 
    return 0;
}

