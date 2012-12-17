#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class TaxiManager {
    public:
        int schedule(vector <string>, vector <string>);
};

const int MAXN = 51;
int sp[MAXN][MAXN];
const int INF = 999999999;
void floyd(vector<string> roads){
    int sz = roads.size();
    for(int i=0; i<sz; i++){
        for(int j=0; j<sz; j++){
            if(roads[i][j]=='0'){
                sp[i][j] = INF;
            }else{
                sp[i][j] = roads[i][j]-'0';
            }
        }
        sp[i][i] = 0;
    }
    
    for(int k=0; k<sz; k++){
        for(int i=0; i<sz; i++){
            for(int j=0;j<sz; j++){
                sp[i][j] = min(sp[i][k]+sp[k][j], sp[i][j]);
            }
        }

    }
}
const int MAXM = 13;
const int MAXS = 1<<MAXM;;
int dp[1<<13][MAXN][MAXN];
int cus_des[MAXN][2];

int TaxiManager::schedule(vector <string> roads, vector <string> customers) {
    floyd( roads );
    int g_sz = roads.size();
    int sz = customers.size();
    for(int i=0; i<sz; i++){
        istringstream is(customers[i]);
        is>>cus_des[i][0]>>cus_des[i][1];
    }
    
    for(int i=0; i<MAXS; i++){
        for(int j=0; j<g_sz; j++){
            for(int k=0; k<g_sz; k++){
                dp[i][j][k]=INF;
            }
        }
    }
    dp[0][0][0] = 0;
    /*
    for(int i=0; i<sz; i++){
        dp[1<<i][cus_des[i][0]][0] = sp[cus_des[i][0]][cus_des[i][1]];
        dp[1<<i][0][cus_des[i][0]] = sp[cus_des[i][0]][cus_des[i][1]];
    }
*/
    for(int s=0; s<(1<<sz); s++){
        for(int cur_a = 0; cur_a<g_sz; cur_a++){
            for(int cur_b = 0; cur_b<g_sz; cur_b++){
                if(dp[s][cur_a][cur_b]==INF)continue;
                
                for(int i=0; i<sz; i++){
                    if( ((s>>i)&1)!=0) continue;
                    int ns = (1<<i)|s;
                    int next_a = cus_des[i][1];
                    dp[ns][next_a][cur_b] = min(dp[ns][next_a][cur_b], dp[s][cur_a][cur_b] + sp[cur_a][cus_des[i][0]] + sp[cus_des[i][0]][cus_des[i][1]]);
                    int next_b = cus_des[i][1];
                    dp[ns][cur_a][next_b] = min(dp[ns][cur_a][next_b], dp[s][cur_a][cur_b] + sp[cur_b][cus_des[i][0]] + sp[cus_des[i][0]][cus_des[i][1]]);
                    /*
                    if(cur_a == cus_des[i][0]){
                        int next_a = cus_des[i][1];
                        dp[ns][next_a][cur_b] = min(dp[ns][next_a][cur_b], dp[s][cur_a][cur_b] + sp[cur_a][next_a]);
                    }
                    */
                    /*
                    if(cur_b == cus_des[i][0]){
                        int next_b = cus_des[i][1];
                        dp[ns][cur_a][next_b] = min(dp[ns][cur_a][next_b], dp[s][cur_a][cur_b] + sp[cur_b][next_b]);
                    }
                    */
                }
                /*
                for(int next_a = 0; next_a < sz; next_a++){
                    if( ((s>>next_a)&1)!=0) continue;
                    int ns = (1<<next_a)|s;
                    dp[ns][next_a][cur_b] = min(dp[ns][next_a][cur_b], dp[s][cur_a][cur_b] + sp[cur_a][next_a]);
                }
                for(int next_b = 0; next_b < sz; next_b++){
                    if( ((s>>next_b)&1)!=0) continue;
                    int ns = (1<<next_b)|s;
                    dp[ns][cur_a][next_b] = min(dp[ns][cur_a][next_b], dp[s][cur_a][cur_b] + sp[cur_b][next_b]);
                }
                */
            }
        }
    }
    int ans = INF;
    for(int i=0; i<g_sz; i++){
        for(int j=0; j<g_sz; j++){
            ans = min(ans, dp[(1<<sz)-1][i][j]+sp[i][0]+sp[j][0]);
        }
    }
    return ans;
}
double test0() {
    string t0[] = {"020200"
        ,"202020"
            ,"020002"
            ,"200020"
            ,"020202"
            ,"002020"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    string t1[] = {"5 3","2 4","1 5","3 2"};
    vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
    TaxiManager * obj = new TaxiManager();
    clock_t start = clock();
    int my_answer = obj->schedule(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 16;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p2 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p2 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test1() {
    string t0[] = 
    {"00020251090265906661"
        ,"00763002550100090081"
            ,"06003699000080062771"
            ,"00000710460400035310"
            ,"50000039119198350060"
            ,"66060004050810046028"
            ,"02333108565000200880"
            ,"40212560000209205231"
            ,"02601150098329905062"
            ,"00210383709951005203"
            ,"10111087340780827070"
            ,"05065800003095040140"
            ,"15604020082000100090"
            ,"83430030070580600750"
            ,"10588355007006001150"
            ,"14400080790005400536"
            ,"23400990400933060004"
            ,"11053016300602000090"
            ,"90040920084059282502"
            ,"61300007077904050900"};
        vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
        string t1[] = {"0 19","4 16","15 16","4 18","2 7","9 15","11 6","7 13","19 13","12 19","14 12","16 1"};
        vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
        TaxiManager * obj = new TaxiManager();
        clock_t start = clock();
        int my_answer = obj->schedule(p0, p1);
        clock_t end = clock();
        delete obj;
        cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
        int p2 = 33;
        cout <<"Desired answer: " <<endl;
        cout <<"\t" << p2 <<endl;
        cout <<"Your answer: " <<endl;
        cout <<"\t" << my_answer <<endl;
        if (p2 != my_answer) {
            cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
            return -1;
        }
        else {
            cout <<"Match :-)" <<endl <<endl;
            return (double)(end-start)/CLOCKS_PER_SEC;
        }
}
double test2() {
    string t0[] = 
    {"095222800320504"
        ,"107600288090501"
            ,"760973530769345"
            ,"963093337510830"
            ,"338404069255826"
            ,"291700050155264"
            ,"002783031709004"
            ,"404730701707712"
            ,"068870030090995"
            ,"320025180036103"
            ,"468695042801904"
            ,"233626561000105"
            ,"070014432197086"
            ,"887301000143802"
            ,"230852749990330"};
        vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
        string t1[] = {"3 6","0 4","2 7","9 7","13 9","1 6","7 13","14 2","8 7","10 1","11 13","7 12"};
        vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
        TaxiManager * obj = new TaxiManager();
        clock_t start = clock();
        int my_answer = obj->schedule(p0, p1);
        clock_t end = clock();
        delete obj;
        cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
        int p2 = 28;
        cout <<"Desired answer: " <<endl;
        cout <<"\t" << p2 <<endl;
        cout <<"Your answer: " <<endl;
        cout <<"\t" << my_answer <<endl;
        if (p2 != my_answer) {
            cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
            return -1;
        }
        else {
            cout <<"Match :-)" <<endl <<endl;
            return (double)(end-start)/CLOCKS_PER_SEC;
        }
}
double test3() {
    string t0[] = {"00401","50990","00062","08008","03000"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    string t1[] = {"2 4"};
    vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
    TaxiManager * obj = new TaxiManager();
    clock_t start = clock();
    int my_answer = obj->schedule(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 14;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p2 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p2 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
int main() {
    int time;
    bool errors = false;

    time = test0();
    if (time < 0)
        errors = true;

    time = test1();
    if (time < 0)
        errors = true;

    time = test2();
    if (time < 0)
        errors = true;

    time = test3();
    if (time < 0)
        errors = true;

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}

