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
        cnt ++;
    }
}

string convert(int a){
    ostringstream ss;
    ss<<a;
    string str = ss.str();
    return str;
}

int primes_first[10][10][500];
int primes_second[10][10][10][500];
int primes_third[10][500];
int c_first[10][10];
int c_second[10][10][10];
int c_third[10];

void my_break_down(vector<int> vp){
    break_down(vp);
    for(int i=0; i<cnt; i++){
        int a = primes[i][0], b = primes[i][4];
        primes_first[a][b][c_first[a][b]] = i;
        c_first[a][b]++;
    }
    for(int i=0; i<cnt; i++){
        int a = primes[i][1], b = primes[i][3], f = primes[i][0];
        primes_second[f][a][b][c_second[f][a][b]] = i;
        c_second[f][a][b]++;
    }
    for(int i=0; i<cnt; i++){
        int a = primes[i][2];
        primes_third[a][c_third[a]] = i;
        c_third[a]++;
    }
}



bool in[100000];
vector< vector<int> > ans;


typedef pair<string, vector<int> > psv;

int work(){
    memset(in,0,sizeof(in));
    memset(c_first,0,sizeof(c_first));
    memset(c_second,0,sizeof(c_second));
    memset(c_third,0,sizeof(c_third));
    vector<int> vp = counts[prime_sum];
    for(int i=0; i<vp.size(); i++){
        in[vp[i]]=true;
    }
    my_break_down(vp);
    int sz = vp.size(); 
    int ccc = 0;
    int num[5];
    int sum = 0;
    int cols[5];
    bool ok;

    for(int f=0; f<sz; f++){
        if(primes[f][0]!=init)continue;
        for(int i=0; i<sz; i++){
            if(primes[i][0]!=init)continue;
            for(int j=0; j<sz; j++){
                if(primes[i][2]!=primes[j][2])continue;
                int a_x = primes[i][0], a_y = primes[j][4];
                int a_sz = c_first[a_x][a_y];
                for(int a=0; a<a_sz; a++){
                    int idx_a = primes_first[a_x][a_y][a];
                    if(primes[f][0]!=primes[idx_a][0])continue;
                    int b_x = primes[i][1], b_y = primes[j][3];
                    int b_sz = c_second[primes[f][1]][b_x][b_y];
                    for(int b = 0; b<b_sz; b++){
                        int idx_b = primes_second[primes[f][1]][b_x][b_y][b];
                        if(primes[f][1]!=primes[idx_b][0])continue;
                        int c_x = primes[i][2];
                        int c_sz = c_third[c_x];
                        for(int c=0; c<c_sz; c++){
                            int idx_c = primes_third[c_x][c];
                            if(primes[idx_c][0]!=primes[f][2])continue;
                            int d_x = primes[j][1], d_y = primes[i][3];
                            int d_sz = c_second[primes[f][3]][d_x][d_y];
                            for(int d=0; d<d_sz; d++){
                                int idx_d = primes_second[primes[f][3]][d_x][d_y][d];

                                if(primes[idx_d][0]!=primes[f][3])continue;
                                int e_x = primes[j][0], e_y = primes[i][4];
                                int e_sz = c_first[e_x][e_y];
                                for(int e=0; e<e_sz; e++){
                                    int idx_e = primes_first[e_x][e_y][e];
                                    if(primes[idx_e][0]!=primes[f][4])continue;
                                    //ccc++;
                                    bool ok = true;
                                    for(int p=0; p<5; p++){
                                        int sum = primes[idx_a][p] + primes[idx_b][p] + primes[idx_c][p] + primes[idx_d][p] + primes[idx_e][p];
                                        //int sum = primes[primes_first[a_x][a_y][a]][p] + primes[primes_second[b_x][b_y][b]][p] + primes[primes_third[c_x][c]][p] + primes[primes_second[d_x][d_y][d]][p] + primes[primes_first[e_x][e_y][e]][p];

                                        int num = primes[idx_a][p]*10000+primes[idx_b][p]*1000+primes[idx_c][p]*100+primes[idx_d][p]*10+primes[idx_e][p];
                                       /* 
                                        if( vp[i]==26777 && vp[j]==36749 && vp[idx_a]==25589 && vp[idx_b]==66449 && vp[idx_c]==99713)   {
                                            cout<<"e_x e_y "<<e_x<<" "<<e_y<<endl;
                                            cout<<"vc -> "<<idx_c<<endl;
                                            int num = primes[idx_a][p]*10000+primes[idx_b][p]*1000+primes[idx_c][p]*100+primes[idx_d][p]*10+primes[idx_e][p];
                                            cout<<" number is "<<num<<" " << in[num]<<" sum is "<<sum<<" prime_sum = "<<prime_sum<<endl;
                                        }*/
                                        if(sum!=prime_sum || !in[num]){
                                            ok=false;
                                            break;
                                        }
                                    }

                                    if(!ok)continue;
                                    int i_diag = 0, j_diag=0;

                                    i_diag = primes[idx_a][0] + primes[idx_b][1] + primes[idx_c][2] + primes[idx_d][3] + primes[idx_e][4];
                                    if(i_diag!=prime_sum)continue;
                                    j_diag = primes[idx_a][4] + primes[idx_b][3] + primes[idx_c][2] + primes[idx_d][1] + primes[idx_e][0];
                                    if(j_diag!=prime_sum)continue;
                                    int n_i_diag = 10000*primes[idx_a][0] + 1000*primes[idx_b][1] + 100*primes[idx_c][2] + 10*primes[idx_d][3] + primes[idx_e][4];
                                    if(!in[n_i_diag])continue;
                                    int n_j_diag = primes[idx_a][4] + 10*primes[idx_b][3] + 100*primes[idx_c][2] + 1000*primes[idx_d][1] + 10000*primes[idx_e][0];
                                    if(!in[n_j_diag])continue;

                                    //if(i_diag==j_diag && j_diag==prime_sum && in[n_i_diag] && in[n_j_diag]){
                                        vector<int> t;
                                        t.push_back(vp[idx_a ]);t.push_back(vp[ idx_b]);t.push_back(vp[idx_c]);t.push_back(vp[idx_d]);t.push_back(vp[idx_e]);
                                        ans.push_back(t);
                                        /*
                                           cout<<vp[idx_a]<<endl;
                                           cout<<vp[idx_b]<<endl;
                                           cout<<vp[idx_c]<<endl;
                                           cout<<vp[idx_d]<<endl;
                                           cout<<vp[idx_e]<<endl;
                                           cout<<"****"<<endl;
                                           */

                                    //}
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    //cout<<ccc<<endl;
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

