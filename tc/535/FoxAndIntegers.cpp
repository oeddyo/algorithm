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

class FoxAndIntegers {
    public:
            vector <int> get(int, int, int, int);
};

vector <int> FoxAndIntegers::get(int AminusB, int BminusC, int AplusB, int BplusC) {
        vector<int> res;
        
        if((AminusB + AplusB)%2==0 && (BminusC+BplusC)%2==0 && (BplusC - BminusC)%2==0){
            int A=(AminusB + AplusB)/2;
            int B=(BminusC + BplusC)/2;
            int C=(BplusC - BminusC)/2;
            if((A-B)==AminusB && (B-C)==BminusC && (A+B)==AplusB && (B+C)==BplusC){

                res.push_back( (AminusB + AplusB)/2);
                res.push_back( (BminusC + BplusC)/2);
                res.push_back( (BplusC  - BminusC)/2);
            }
        }
        return res;
}