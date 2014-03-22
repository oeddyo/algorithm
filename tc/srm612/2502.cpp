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


const int MAXN = 2001;
const int INF = 999999999;

bool dp[MAXN][MAXN];

class EmoticonsDiv1 {
    public:
        int printSmiles(int smiles) {
            cout<<"s = "<<smiles<<endl;
            for(int i=0; i<MAXN; i++)for(int j=0; j<MANN; j++){
                dp[i][j] = INF;
            }

            dp[1][0][0] = 0;

            for(int i=0; i<MAXN; i++){
                for(int j=0; j<MAXN; j++){
                    for(int k=0; k<2; k++){
                        if(dp[i][j][k]!=INF){
                            dp[i+j][j][0] = 1;
                        }
                    }
                }
            }
            for(int k=0; k<MAXM; k++){
                for(int i=0; i<MAXN; i++){
                    if(dp[smiles][i][k]){
                        cout<<"!!!"<<endl;
                        cout<<" "<<smiles<<" "<<i<<" "<<k<<endl;
                        return k;
                    }
                }
            }

            return -11;
        }
};




bool KawigiEdit_RunTest(int testNum, int p0, bool hasAnswer, int p1) {
    cout << "Test " << testNum << ": [" << p0;
    cout << "]" << endl;
    EmoticonsDiv1 *obj;
    int answer;
    obj = new EmoticonsDiv1();
    clock_t startTime = clock();
    answer = obj->printSmiles(p0);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << p1 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer) {
        res = answer == p1;
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
    int p1;

    {
        // ----- test 0 -----
        p0 = 1997;
        p1 = 2;
        all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        p0 = 4;
        p1 = 4;
        all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        p0 = 6;
        p1 = 5;
        all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        p0 = 18;
        p1 = 8;
        all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        p0 = 11;
        p1 = 8;
        all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
        // ------------------
    }

    if (all_right) {
        cout << "You're a stud (at least on the example cases)!" << endl;
    } else {
        cout << "Some of the test cases had errors." << endl;
    }
    return 0;
}
