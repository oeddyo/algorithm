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


int primes[1000][5];

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

int primes_first[10][10][10][1000];
int primes_second[10][10][10][1000];
int primes_third[10][1000];
int c_first[10][10][10];
int c_second[10][10][10];
int c_third[10];

void my_break_down(vector<int> vp){
    break_down(vp);
    for(int i=0; i<cnt; i++){
        int a = primes[i][1], b = primes[i][2], f = primes[i][3];
        primes_first[a][b][f][c_first[a][b][f]] = i;
        c_first[a][b][f]++;
    }
    for(int i=0; i<cnt; i++){
        int a = primes[i][0], b = primes[i][2], f = primes[i][4];
        primes_second[a][b][f][c_second[a][b][f]] = i;
        c_second[a][b][f]++;
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

vector<int> tmp;
int data[5][5];

bool check(){
    if(data[2][0]<0 || data[2][0]>9 || data[2][1]<0 || data[2][1]>9 || data[2][2]<0 || data[2][2]>9 || data[2][3]<0 || data[2][3]>9 || data[2][4]<0 || data[2][4]>9){
        return false;
    }
    
    
    for(int row = 0; row<5; row++){
        int sum = 0;
        int n_sum = 0;
        int multi = 10000;
        for(int i=0; i<5; i++){
            sum+=data[row][i];
            n_sum = n_sum + data[row][i]*multi;
            multi/=10;
        }
        if(sum!=prime_sum || !in[n_sum])return false;
    }
    for(int col=0; col<5; col++){
        int sum=0, n_sum=0;
        int multi = 10000;
        for(int i=0; i<5; i++){
            sum+=data[i][col];
            n_sum = n_sum + data[i][col]*multi;
            multi/=10;
        }
        if(sum!=prime_sum || !in[n_sum])return false;
    }
    int i_diag = 0, n_i_diag = 0, j_diag=0, n_j_diag=0;
    int multi = 10000;
    for(int i=0; i<5; i++){
        i_diag+=data[i][i];
        j_diag+=data[4-i][i];
        n_i_diag = n_i_diag + multi*data[i][i];
        n_j_diag = n_j_diag + multi*data[4-i][i];
        multi/=10;
    }
    if(i_diag!=prime_sum || j_diag!=prime_sum || !in[n_i_diag] || !in[n_j_diag])return false;

    
    tmp.clear();
    for(int i=0; i<5; i++){
        int sum = 0, multi = 10000;
        for(int j=0; j<5; j++){
            sum = sum+multi*data[i][j];
            multi/=10;
        }
        tmp.push_back(sum);
    }

    return true;
}


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
    int i_diag, j_diag, n_i_diag, n_j_diag;
    for(int i=0; i<sz; i++){
        if(primes[i][0]!=init)continue;
        for(int j=0; j<sz; j++){
            if(primes[i][2]!=primes[j][2])continue;
            int k_x = primes[i][2];
            int k_sz = c_third[k_x];
            for(int k=0; k<k_sz; k++){
                int idx_k = primes_third[k_x][k];
                int a_x = primes[i][0], a_y = primes[idx_k][0] , a_f = primes[j][4]; 
                int a_sz = c_second[a_x][a_y][a_f];
                for(int a=0; a<a_sz; a++){
                    int idx_a = primes_second[a_x][a_y][a_f][a];
                    int b_x = primes[j][0], b_y = primes[idx_k][4], b_f = primes[i][4];
                    int b_sz = c_second[b_x][b_y][b_f];
                    for(int b = 0; b<b_sz; b++){
                        int idx_b = primes_second[b_x][b_y][b_f][b];
                        int c_x = primes[i][1], c_y = primes[idx_k][1], c_f = primes[j][3];
                        int c_sz = c_first[c_x][c_y][c_f];
                        for(int c=0; c<c_sz; c++){
                            int idx_c = primes_first[c_x][c_y][c_f][c];
                            int d_x = primes[j][1], d_y = primes[idx_k][3], d_f = primes[i][3];
                            int d_sz = c_first[d_x][d_y][d_f];
                            for(int d=0; d<d_sz; d++){
                                int idx_d = primes_first[d_x][d_y][d_f][d];

                                ccc++; 
                                for(int z=0; z<5; z++){
                                    data[0][z] = primes[idx_a][z];
                                    data[4][z] = primes[idx_b][z];
                                    data[z][2] = primes[idx_k][z];
                                    data[z][z] = primes[i][z];
                                    data[4-z][z] = primes[j][z];
                                    data[1][z] = primes[idx_c][z];
                                    data[3][z] = primes[idx_d][z];
                                }
                                data[2][0] = prime_sum - (data[0][0]+data[1][0]+data[3][0]+data[4][0]);
                                data[2][1] = prime_sum - (data[0][1]+data[1][1]+data[3][1]+data[4][1]);
                                data[2][3] = prime_sum - (data[0][3]+data[1][3]+data[3][3]+data[4][3]);
                                data[2][4] = prime_sum - (data[0][4]+data[1][4]+data[3][4]+data[4][4]);
                                if(check()){
                                    cout<<idx_a<<" "<<idx_b<<endl;
                                    cout<<vp[idx_a]<<endl;
                                    cout<<vp[idx_b]<<endl;
                                    ans.push_back(tmp); 
                                }
                                /*
                                   cout<<vp[idx_a]<<endl;
                                   cout<<vp[idx_b]<<endl;
                                   cout<<vp[idx_c]<<endl;
                                   cout<<vp[idx_d]<<endl;
                                   cout<<vp[idx_e]<<endl;
                                   cout<<"****"<<endl;
                                   */
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<"ccc is "<<ccc<<endl;
    cout<<"ans is "<<ans.size()<<endl;
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

