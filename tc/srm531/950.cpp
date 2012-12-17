#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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

const int MAXN = 120;
const int INF = 99999999;
typedef pair<int, int> pii;

vector< int> clusters[MAXN];
vector< pii > g[MAXN];
//int g[MAXN][MAXN];
bool visited[MAXN];

class KingdomReorganization {
    public:
        int prime(int start, vector <string> kingdom, vector <string> destroy, int sz){
            bool vis[MAXN];
            memset(vis,0,sizeof(vis));
            priority_queue< pii, vector< pii > , greater<pii> > Q;
            Q.push( pii(0, start) );
            int res = 0;
            int total = 0;
            while(!Q.empty()){
                pii cur = Q.top();
                Q.pop();
                int pos = cur.second;
                if(vis[pos]==1){
                    continue;
                }
                vis[pos] = 1;
                int value = cur.first;
                res+=value;
                for(int i=0; i<sz; i++){
                    if(vis[i]==0 && kingdom[pos][i]=='1'){
                        int tmp_value = (destroy[pos][i]>='a' && destroy[pos][i]<='z')?(destroy[pos][i]-'a'+26):(destroy[pos][i]-'A');
                        total+=tmp_value;
                        tmp_value = tmp_value*-1;
                        Q.push(pii(tmp_value, i));
                    }
                }
            }
            return total + res;
        }
        
        int prim2(int start){
            bool vis[MAXN];
            memset(vis,0,sizeof(vis));
            priority_queue< pii, vector< pii > , greater<pii> > Q;
            /*
            cout<<"graph g is like "<<endl;
            for(int i=0; i<3; i++){
                for(int j=0; j<g[i].size(); j++){
                    cout<<i<<" "<<g[i][j].second<<" "<<g[i][j].first<<endl;
                }
            }
            */
            Q.push( pii(0, start) );
            int res = 0;
            while(!Q.empty()){
                pii cur = Q.top();
                Q.pop();
                int pos = cur.second;
                if(vis[pos]==1){
                    continue;
                }
                vis[pos] = 1;
                int value = cur.first;
                res+=value;
                for(int i=0; i<g[pos].size(); i++){
                    if(vis[g[pos][i].second]==0 ){
                        int tmp_value = g[pos][i].first;
                        Q.push(pii(tmp_value, g[pos][i].second));
                    }
                }
            }
            return res;
        }
        void dfs(int cur, int idx, vector<string> &kingdom, int sz){
            visited[cur] = 1;
            clusters[idx].push_back(cur);
            for(int i=0; i<sz; i++){
                if(kingdom[cur][i]=='1' && visited[i]==0){
                    dfs(i, idx, kingdom, sz);
                }
            }
        }

        int getCost(vector <string> kingdom, vector <string> build, vector <string> destroy) {
            for(int i=0; i<MAXN; i++){
                clusters[i].clear();
                g[i].clear();
            }

            //for(int i=0; i<MAXN; i++)for(int j=0; j<MAXN; j++)g[i][j] = INF;
            memset(visited, 0, sizeof(visited));
            int sz = kingdom.size();
            int cluster_idx = 0;
            for(int i=0; i<sz; i++){
                if(visited[i]==0){
                    dfs(i, cluster_idx++, kingdom, sz);
                }
            }
            for(int i=0; i<cluster_idx; i++){
                for(int j=0; j<clusters[i].size(); j++){
                    cout<<clusters[i][j]<<'\t';
                }cout<<endl;
            }cout<<endl;
            int destroy_value  =0;
            for(int i=0; i<cluster_idx; i++){
                destroy_value += prime(clusters[i][0], kingdom, destroy, sz);
            }
            cout<<destroy_value<<" destroyed"<<endl;
            
            int ans = destroy_value;
            cout<<"cluster_id = "<<cluster_idx<<endl; 
            for(int i=0; i<cluster_idx; i++){
                for(int j=i+1; j<cluster_idx; j++){
                    for(int a=0; a<clusters[i].size(); a++){
                        for(int b=0; b<clusters[j].size(); b++){
                            int point_a = clusters[i][a];
                            int point_b = clusters[j][b];
                            int v = (build[point_a][point_b]>='a' && build[point_a][point_b]<='z')?(build[point_a][point_b]-'a'+26):(build[point_a][point_b]-'A');
                            g[i].push_back(pii(v, j));
                            g[j].push_back(pii(v,i));
                        }
                    }
                }
            }
            int build_value = prim2(0);
            cout<<"final ans = "<<build_value+destroy_value<<endl;
            return build_value+destroy_value;
            //ans += prim2(0);  
        }
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <string> p1, vector <string> p2, bool hasAnswer, int p3) {
    cout << "Test " << testNum << ": [" << "{";
    for (int i = 0; int(p0.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << "\"" << p0[i] << "\"";
    }
    cout << "}" << "," << "{";
    for (int i = 0; int(p1.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << "\"" << p1[i] << "\"";
    }
    cout << "}" << "," << "{";
    for (int i = 0; int(p2.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << "\"" << p2[i] << "\"";
    }
    cout << "}";
    cout << "]" << endl;
    KingdomReorganization *obj;
    int answer;
    obj = new KingdomReorganization();
    clock_t startTime = clock();
    answer = obj->getCost(p0, p1, p2);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << p3 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer) {
        res = answer == p3;
    }
    if (!res) {
        cout << "DOESN'T MATCH!!!!" << endl;
    } else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
        cout << "FAIL the timeout" << endl;
        res = false;
    } else if (hasAnswer) {
        cout << "Match :-)" << endl;
    } else {
        cout << "OK, but is it right?" << endl;
    }
    cout << "" << endl;
    return res;
}
int main() {
    bool all_right;
    all_right = true;

    vector <string> p0;
    vector <string> p1;
    vector <string> p2;
    int p3;

    {
        // ----- test 0 -----
        string t0[] = {"000","000","000"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        string t1[] = {"ABD","BAC","DCA"};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        string t2[] = {"ABD","BAC","DCA"};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        p3 = 3;
        all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }
    {
        // ----- test 1 -----
        string t0[] = {"011","101","110"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        string t1[] = {"ABD","BAC","DCA"};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        string t2[] = {"ABD","BAC","DCA"};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        p3 = 1;
        all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }
    {
        // ----- test 2 -----
        string t0[] = {"011000","101000","110000","000011","000101","000110"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        string t1[] = {"ABDFFF","BACFFF","DCAFFF","FFFABD","FFFBAC","FFFDCA"};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        string t2[] = {"ABDFFF","BACFFF","DCAFFF","FFFABD","FFFBAC","FFFDCA"};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        p3 = 7;
        all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        string t0[] = {"0"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        string t1[] = {"A"};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        string t2[] = {"A"};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        p3 = 0;
        all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        string t0[] = {"0001","0001","0001","1110"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        string t1[] = {"AfOj","fAcC","OcAP","jCPA"};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        string t2[] = {"AWFH","WAxU","FxAV","HUVA"};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        p3 = 0;
        all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 5 -----
        string t0[] = {"0000000000","0000000011","0001010000","0010010000","0000001000","0011000000","0000100000","0000000011","0100000101","0100000110"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        string t1[] = {"AhPEqkSFMM","hAfKPtsDad","PfAyGQkaqN","EKyAeLpRpm","qPGeASfNwo","ktQLSAnCAK","SskpfnAdJS","FDaRNCdAZz","MaqpwAJZAn","MdNmoKSznA"};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        string t2[] = {"AgTqWWxEYH","gAXPgjzIRA","TXAleTmWvT","qPlAQkwxRO","WgeQAqgbJJ","WjTkqAiTzl","xzmwgiAuHb","EIWxbTuAwk","YRvRJzHwAn","HATOJlbknA"};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        p3 = 65;
        all_right = KawigiEdit_RunTest(5, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    if (all_right) {
        cout << "You're a stud (at least on the example cases)!" << endl;
    } else {
        cout << "Some of the test cases had errors." << endl;
    }
    return 0;
}
// END KAWIGIEDIT TESTING
