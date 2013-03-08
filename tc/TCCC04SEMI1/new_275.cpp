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

typedef pair<int, int> pii;

const int MAX_VALUE = 10580;
const int MAX_WEIGHT = 101;
int dp[MAX_WEIGHT][MAX_VALUE];

int VP[300][2];
int ptr = 0;

class CoinWeight {
    public:
        int possibleValues(int weight, vector <string> coins) {
            //vector< pii > VP;
            ptr = 0;
            for(int i=0; i<coins.size(); i++){
                istringstream in(coins[i]);
                int a,b,c;
                in>>a>>b>>c;
                for(int j=b; j<=c; j++){
                    //VP.push_back( pii(a,j) );
                    VP[ptr][0] = a;
                    VP[ptr][1] = j;
                    ptr++;
                }
            }
            int max_value = 0;
            for(int i=0; i<ptr; i++){
                cout<<VP[i][0]<<" "<<VP[i][1]<<endl;
                //max_value+=VP[i][1];
            }
            //sort(VP.begin(), VP.end());
            cout<<"max_value = "<<max_value<<endl;
            memset(dp,0,sizeof(dp));
            dp[0][0] = 1;
            max_value = 10000;
            max_value = MAX_VALUE-1;
            int sz = ptr;
            for(int w=0; w<=weight; w++){
                for(int v=0; v<=max_value; v++){
                    for(int k=0; k<sz; k++){
                        if(dp[w][v]==1)break;
                        int value = VP[k][0];
                        int cost = VP[k][1];
                        if( w-cost >=0 && v-value>=0 && dp[w-cost][v-value]==1){
                            dp[w][v] = 1;
                        }
                    }
                }
            }
            int cnt = 0;
            for(int i=0; i<=max_value; i++){
                if(dp[weight][i])cnt++;
            }
            return cnt;

            return -1;
        }
};

bool KawigiEdit_RunTest(int testNum, int p0, vector <string> p1, bool hasAnswer, int p2) {
    cout << "Test " << testNum << ": [" << p0 << "," << "{";
    for (int i = 0; int(p1.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << "\"" << p1[i] << "\"";
    }
    cout << "}";
    cout << "]" << endl;
    CoinWeight *obj;
    int answer;
    obj = new CoinWeight();
    clock_t startTime = clock();
    answer = obj->possibleValues(p0, p1);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << p2 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer) {
        res = answer == p2;
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

    int p0;
    vector <string> p1;
    int p2;

    {
        // ----- test 0 -----
        p0 = 100;
        string t1[] = {"46 2 13", "35 21 26", "31 15 21", "49 9 11", "14 14 17", "2 10 14"};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 1597;
        all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
        // ------------------
    }
    {
        // ----- test 1 -----
        p0 = 11;
        string t1[] = {"25 20 22"};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 0;
        all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        p0 = 50;
        string t1[] = {"1 15 20","3 30 30"};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 2;
        all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
        // ------------------
    }
    {
        // ----- test 3 -----
        p0 = 50;
        string t1[] = {"1 15 20","2 30 30"};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 1;
        all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        p0 = 100;
        string t1[] = {"1 2 31","2 16 46","4 31 61","8 46 76","16 61 91","32 76 100","50 2 31"};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 1316;
        all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
        // ------------------
    }

    if (all_right) {
        cout << "You're a stud (at least on the example cases)!" << endl;
    } else {
        cout << "Some of the test cases had errors." << endl;
    }
    return 0;
}
