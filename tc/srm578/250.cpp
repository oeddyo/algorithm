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

const int MAXN = 100;
bool vis[MAXN][MAXN];

int dfs(vector<string> & field, int dis, int x, int y){
    if(vis[x][y]){
        return  0;
    }
    vis[x][y] = 1;
    int cur = 0;
    int tmp = 0;

    for(int i=0; i<field.size(); i++){
        for(int j=0; j<field[0].size(); j++){
            if(abs(x-i) + abs(y-j)<=dis && field[i][j]=='v'){
                tmp += dfs(field, dis, i, j);
            }
        }
    }
    tmp+=1;
    return tmp;
}

int p_2[MAXN] = {
    1 ,
    2 ,
    4 ,
    8 ,
    16 ,
    32 ,
    64 ,
    128 ,
    256 ,
    512 ,
    1024 ,
    2048 ,
    4096 ,
    8192 ,
    16384 ,
    32768 ,
    65536 ,
    131072 ,
    262144 ,
    524288 ,
    1048576 ,
    2097152 ,
    4194304 ,
    8388608 ,
    16777216 ,
    33554432 ,
    67108864 ,
    134217728 ,
    268435456 ,
    536870912 ,
    73741817 ,
    147483634 ,
    294967268 ,
    589934536 ,
    179869065 ,
    359738130 ,
    719476260 ,
    438952513 ,
    877905026 ,
    755810045 ,
    511620083 ,
    23240159 ,
    46480318 ,
    92960636 ,
    185921272 ,
    371842544 ,
    743685088 ,
    487370169 ,
    974740338 ,
    949480669 ,
    898961331 ,
    797922655 ,
    595845303 ,
    191690599 ,
    383381198 ,
    766762396 ,
    533524785 ,
    67049563 ,
    134099126 ,
    268198252 ,
    536396504 ,
    72793001 ,
    145586002 ,
    291172004 ,
    582344008 ,
    164688009 ,
    329376018 ,
    658752036 ,
    317504065 ,
    635008130 ,
    270016253 ,
    540032506 ,
    80065005 ,
    160130010 ,
    320260020 ,
    640520040 ,
    281040073 ,
    562080146 ,
    124160285 ,
    248320570 ,
    496641140 ,
    993282280 ,
    986564553 ,
    973129099 ,
    946258191 ,
    892516375 ,
    785032743 ,
    570065479 ,
    140130951 ,
    280261902 ,
    560523804 ,
    121047601 ,
    242095202 ,
    484190404 ,
    968380808 ,
    936761609 ,
    873523211 ,
    747046415 ,
    494092823 ,
    988185646 ,
    976371285 ,
    952742563 ,
    905485119 ,
    810970231 ,
    621940455 ,
    243880903 ,
    487761806 ,
    975523612 ,
    951047217 ,
    902094427 ,
    804188847 ,
    608377687 ,
    216755367 ,
    433510734 ,
    867021468 ,
    734042929 ,
    468085851 ,
    936171702 ,
    872343397 ,
    744686787 ,
    489373567 ,
    978747134 ,
    957494261 ,
    914988515 ,
    829977023 ,
    659954039 ,
    319908071 ,
    639816142 ,
    279632277 ,
    559264554 ,
    118529101 ,
    237058202 ,
    474116404 ,
    948232808 ,
    896465609 ,
    792931211 ,
    585862415 ,
    171724823 ,
    343449646 ,
    686899292 ,
    373798577 ,
    747597154 ,
    495194301 ,
    990388602 ,
    980777197 ,
    961554387 ,
    923108767 ,
    846217527 ,
    692435047 ,
    384870087 ,
    769740174 ,
    539480341 ,
    78960675 ,
    157921350 ,
    315842700 ,
    631685400 ,
    263370793 ,
    526741586 ,
    53483165 ,
    106966330 ,
    213932660 ,
    427865320 ,
    855730640 ,
    711461273 ,
    422922539 ,
    845845078 ,
    691690149 ,
    383380291 ,
    766760582 ,
    533521157 ,
    67042307 ,
    134084614 ,
    268169228 ,
    536338456 ,
    72676905 ,
    145353810 ,
    290707620 ,
    581415240 ,
    162830473 ,
    325660946 ,
    651321892 ,
    302643777 ,
    605287554 ,
    210575101 ,
    421150202 ,
    842300404 ,
    684600801 ,
    369201595 ,
    738403190 ,
    476806373 ,
    953612746 ,
    907225485 ,
    814450963 ,
    628901919 ,
    257803831 ,
    515607662 ,
    31215317 ,
    62430634 ,
    124861268 ,
    249722536, 
}

long long int choose[MAXN][MAXN];


long long int get_choose(int n, int k){
    if(choose[n][k]!=-1){
        return choose[n][k];
    }
    long long int tmp;
    if(n==0){
        tmp = 0;
    }else if(k=0){
        tmp = 1;
    }else{
        long long int t1 = get_choose(n-1, k-1);
        long long int t2 = get_choose(n-1, k);
        tmp = (t1%MOD + t2%MOD);
    }
    choose[n][k] = tmp;
    return tmp;
}



class GooseInZooDivOne {
    public:
        int count(vector <string> field, int dist) {
            memset(choose,-1, sizeof(choose));
            
            memset(vis,0,sizeof(vis));
            vector<int> odd;
            vector<int> even;
            for(int i=0; i<field.size(); i++){
                for(int j=0; j<field[0].size(); j++){
                    if(vis[i][j]==0 && field[i][j]=='v'){
                        cout<<dfs(field, dist, i, j)<<" ";
                        int tmp = dfs(field, dist, i, j);
                        if(tmp%2==0){
                            even.append(tmp);
                        }else{
                            odd.append(tmp);
                        }
                    }
                }
            }
            long long int ans = 0;
            int os = odd.size();
            int es = even.size();
            if(even.size()==0){
                for(int i=2; i<odd.size(); i+=2){
                    ans = ans + choose[os][i];
                    

            }


        }
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, int p1, bool hasAnswer, int p2) {
    cout << "Test " << testNum << ": [" << "{";
    for (int i = 0; int(p0.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << "\"" << p0[i] << "\"";
    }
    cout << "}" << "," << p1;
    cout << "]" << endl;
    GooseInZooDivOne *obj;
    int answer;
    obj = new GooseInZooDivOne();
    clock_t startTime = clock();
    answer = obj->count(p0, p1);
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

    vector <string> p0;
    int p1;
    int p2;

    {
        // ----- test 0 -----
        string t0[] = {"vvv"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 0;
        p2 = 3;
        all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        string t0[] = {"."};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 100;
        p2 = 0;
        all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        string t0[] = {"vvv"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 1;
        p2 = 0;
        all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        string t0[] = {"v.v..................v............................",".v......v..................v.....................v","..v.....v....v.........v...............v......v...",".........vvv...vv.v.........v.v..................v",".....v..........v......v..v...v.......v...........","...................vv...............v.v..v.v..v...",".v.vv.................v..............v............","..vv.......v...vv.v............vv.....v.....v.....","....v..........v....v........v.......v.v.v........",".v.......v.............v.v..........vv......v.....","....v.v.......v........v.....v.................v..","....v..v..v.v..............v.v.v....v..........v..","..........v...v...................v..............v","..v........v..........................v....v..v...","....................v..v.........vv........v......","..v......v...............................v.v......","..v.v..............v........v...............vv.vv.","...vv......v...............v.v..............v.....","............................v..v.............."
            "...v",".v.............v.......v..........................","......v...v........................v..............",".........v.....v..............vv..................","................v..v..v.........v....v.......v....","........v.....v.............v......v.v............","...........v....................v.v....v.v.v...v..","...........v......................v...v...........","..........vv...........v.v.....................v..",".....................v......v............v...v....",".....vv..........................vv.v.....v.v.....",".vv.......v...............v.......v..v.....v......","............v................v..........v....v....","................vv...v............................","................v...........v........v...v....v...","..v...v...v.............v...v........v....v..v....","......v..v.......v........v..v....vv..............","...........v..........v........v.v................","v.v......v................v....................v..",".v........v............................."
                "...v......","............................v...v.......v.........","........................vv.v..............v...vv..",".......................vv........v.............v..","...v.............v.........................v......","....v......vv...........................v.........","....vv....v................v...vv..............v..","..................................................","vv........v...v..v.....v..v..................v....",".........v..............v.vv.v.............v......",".......v.....v......v...............v.............","..v..................v................v....v......",".....v.....v.....................v.v......v......."};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 3;
        p2 = 898961330;
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
