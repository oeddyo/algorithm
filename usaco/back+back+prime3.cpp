/*
ID: xieke.b1
PROB: prime3
LANG: C++
*/

#include <iostream>

#include <sstream>
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
string convert(int a){
    ostringstream ss;
    ss<<a;
    string str = ss.str();
    return str;
}

bool in[100000];
vector< vector<int> > ans;


typedef pair<string, vector<int> > psv;

int work(){
    memset(in,0,sizeof(in));
    vector<int> vp = counts[prime_sum];
    for(int i=0; i<vp.size(); i++){
        in[vp[i]]=true;
    }
    break_down(vp);
    int sz = vp.size(); 
    int ccc = 0;
    int num[5];
    int sum = 0;
    int cols[5];
    bool ok;
    for(int a=0; a<sz; a++){
        cout<<a<<endl;
        if(primes[a][0]!=init)continue;
        for(int b=0; b<sz; b++){
            if(primes[b][0]!=primes[a][0])continue;
            for(int c = 0; c<sz; c++){
                if(primes[a][4]!=primes[c][0] ) continue;
                for(int i=0; i<sz; i++){
                    if(primes[i][0]!=primes[a][0] || primes[i][4]!=primes[c][4])continue;
                    for(int j=0; j<sz; j++){
                        //the diagnals
                        if(primes[i][2]!=primes[j][2] || primes[j][4]!=primes[a][4] || primes[j][0]!=primes[b][4] || primes[j][4]!=primes[c][0])continue;
                        for(int p=0; p<sz; p++){
                            if(primes[i][1]!=primes[p][1] || primes[j][3]!=primes[p][3] || primes[b][1]!=primes[p][0] || primes[p][4]!=primes[c][1]  )continue;
                            for(int k=0; k<sz; k++){
                                if(primes[i][2]!=primes[k][2] || primes[k][0]!=primes[b][2] || primes[k][4]!=primes[c][2])continue;
                                for(int l=0; l<sz; l++){
                                    if(primes[l][3]!=primes[i][3] || primes[l][1]!=primes[j][1] || primes[b][3]!=primes[l][0] || primes[l][4]!=primes[c][3])continue;
                                    ok = true;
                                    int i_diag=0, j_diag = 0;
                                    int multi = 10000;
                                    for(int q=0; q<5; q++){
                                        sum = primes[a][q] + primes[p][q] + primes[k][q] + primes[l][q];
                                        num[q] = prime_sum - sum;
                                        i_diag+=multi*primes[i][q];
                                        j_diag+=multi*primes[j][q];
                                        multi/=10;
                                        cols[q] = 10000*primes[a][q] + 1000*primes[p][q]+100*primes[k][q]+10*primes[l][q]+num[q];
                                        if(num[q]<0||num[q]>9 || !in[cols[q]] ){
                                            ok=false;
                                            break;
                                        }
                                    }
                                    ccc++;
                                    if(!ok)continue;;
                                    int m;
                                    if(ok && num[0]==primes[j][0] && num[4]==primes[i][4]&& in[i_diag]&&in[j_diag] && num[0]==primes[b][4] && num[4]==primes[c][4]){
                                        m = num[0]*10000+1000*num[1]+100*num[2]+10*num[3]+num[4];
                                        if(in[m] && in[i_diag] && in[j_diag]){
                                            /*cout<<vp[a]<<endl;
                                              cout<<vp[p]<<endl;
                                              cout<<vp[k]<<endl;
                                              cout<<vp[l]<<endl;
                                              cout<<m<<endl;
                                              */
                                            vector<int> t;
                                            t.push_back(vp[a]);t.push_back(vp[p]);t.push_back(vp[k]);t.push_back(vp[l]);t.push_back(m);
                                            ans.push_back(t);

                                        }
                                    }
                                }
                            }
                        }
                    }
                }

            }
        }
    }
    cout<<"ccc "<<ccc<<endl;
    vector<psv> v;
    for(int i=0; i<ans.size(); i++){
        string s;
        for(int j=0; j<ans[i].size(); j++){
            s+=convert(ans[i][j]);
        }
        v.push_back( psv(s, ans[i]));
    }
    sort(v.begin(), v.end());
    if(v.size()==0){
        fout<<"NONE"<<endl;
    }else{

        for(int i=0; i<v.size(); i++){
            for(int j=0; j<v[i].second.size(); j++){
                fout<<v[i].second[j]<<endl;
            }
            if(i!=v.size()-1)
                fout<<endl;
        }
    }


}

int main(){
    prime();
    fin>>prime_sum>>init; 
    work(); 
    return 0;
}

