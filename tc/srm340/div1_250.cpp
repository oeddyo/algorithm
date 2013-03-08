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

const int INF = 99999999;

class ProblemsToSolve {
    public:
        int dis(int a, int b){
            int t = abs(a-b);
            if(t%2==0){
                return t/2;
            }return t/2 + 1;
        }

        int minNumber(vector <int> pleasantness, int variety) {
            int ans = INF;

            //start big -> small
            for(int i=1; i<pleasantness.size(); i++){
                if(abs(pleasantness[i]-pleasantness[0])>=variety){
                    ans = min(ans, dis(i,0));
                    //(i-1)%2==0?(i-1)/2:((i-1)/2+1));
                    break;
                }
            }

            int sz = pleasantness.size();
            for(int i=1; i<sz; i++){
                for(int j=i+1; j<sz; j++){
                    if(abs(pleasantness[i]-pleasantness[j])>=variety){
                        ans = min(ans, dis(0,i)+dis(i,j));
                        break;
                    }
                }
            }
            if(ans==INF){
                return sz;
            }
            return ans+1;

        }
};

bool KawigiEdit_RunTest(int testNum, vector <int> p0, int p1, bool hasAnswer, int p2) {
    cout << "Test " << testNum << ": [" << "{";
    for (int i = 0; int(p0.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p0[i];
    }
    cout << "}" << "," << p1;
    cout << "]" << endl;
    ProblemsToSolve *obj;
    int answer;
    obj = new ProblemsToSolve();
    clock_t startTime = clock();
    answer = obj->minNumber(p0, p1);
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

    vector <int> p0;
    int p1;
    int p2;

    {
        // ----- test 0 -----
        int t0[] = {1,2,3};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 2;
        p2 = 2;
        all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        int t0[] = {1,2,3,4,5};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 4;
        p2 = 3;
        all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        int t0[] = {10,1,12,101};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 100;
        p2 = 3;
        all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        int t0[] = {10,1};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 9;
        p2 = 2;
        all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        int t0[] = {6,2,6,2,6,3,3,3,7};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 4;
        p2 = 2;
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
// END KAWIGIEDIT TESTING

