#include <vector>
#include <list>
#include <cstring>
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

const int MAXN = 12;
const int MAXS = 50000;
double prob[MAXN][MAXN][MAXS];

class TorusSailingEasy {
public:
    double expectedTime(int N, int M, int goalX, int goalY) {
        memset(prob, 0, sizeof(prob));
        prob[0][0][0] = 1;

        for(int s = 0; s<MAXS-1; s++){

            for(int i=0; i<N; i++){
                for(int j=0; j<M; j++){
                    if(i == goalX && j == goalY)continue;
                    int new_x = (i+1)%N;
                    int new_y = (j+1)%M;
                    prob[new_x][new_y][s+1] += prob[i][j][s]*0.5;

                    new_x = (N + i-1)%N;
                    new_y = (M + j-1)%M;
                    prob[new_x][new_y][s+1] += prob[i][j][s]*0.5;
                }
            }
        }
        double ans = 0.0;
        for(int i=0; i<MAXS; i++){
            ans += prob[goalX][goalY][i]* i;
        }
        if(ans == 0.0 )return -1;
        return ans;
    }
};




// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, bool hasAnswer, double p4) {
    cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3;
    cout << "]" << endl;
    TorusSailingEasy *obj;
    double answer;
    obj = new TorusSailingEasy();
    clock_t startTime = clock();
    answer = obj->expectedTime(p0, p1, p2, p3);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << p4 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer) {
        res = fabs(p4 - answer) <= 1e-9 * max(1.0, fabs(p4));
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
    int p2;
    int p3;
    double p4;
    
    {
    // ----- test 0 -----
    p0 = 10;
    p1 = 9;
    p2 = 9;
    p3 = 8;
    p4 = 89.0;
    all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
    // ------------------
    }
    
    {
    // ----- test 1 -----
    p0 = 2;
    p1 = 2;
    p2 = 0;
    p3 = 1;
    p4 = -1.0;
    all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
    // ------------------
    }
    
    {
    // ----- test 2 -----
    p0 = 3;
    p1 = 3;
    p2 = 1;
    p3 = 1;
    p4 = 2.0;
    all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
    // ------------------
    }
    
    {
    // ----- test 3 -----
    p0 = 4;
    p1 = 6;
    p2 = 1;
    p3 = 3;
    p4 = 27.0;
    all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
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