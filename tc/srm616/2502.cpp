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


class WakingUpEasy {
public:
    int countAlarms(vector <int> volume, int S) {
        int sum = 0;
        while(1){
            for(int i=0; i<volume.size(); i++){
                if(S<=0)return sum;
                else{
                    S-=volume[i];
                    sum++;
                }
            }

        }

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
    WakingUpEasy *obj;
    int answer;
    obj = new WakingUpEasy();
    clock_t startTime = clock();
    answer = obj->countAlarms(p0, p1);
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
    int t0[] = {5,2,4};
            p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 10000;
    p2 = 4;
    all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
    // ------------------
    }
    
    {
    // ----- test 1 -----
    int t0[] = {5,2,4};
            p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 3;
    p2 = 1;
    all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
    // ------------------
    }
    
    {
    // ----- test 2 -----
    int t0[] = {1};
            p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 10000;
    p2 = 10000;
    all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
    // ------------------
    }
    
    {
    // ----- test 3 -----
    int t0[] = {42,68,35,1,70,25,79,59,63,65,6,46,82,28,62,92,96,43,28,37,92,5,3,54,93,83,22,17,19,96,48,27,72,39,70,13,68,100,36,95,4,12,23,34,74,65,42,12,54,69};
            p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 9999;
    p2 = 203;
    all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
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

