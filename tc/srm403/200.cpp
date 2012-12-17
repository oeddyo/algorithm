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

class TheLargestLuckyNumber {
    public:
            int find(int);
};
bool is_luck(int k){
    while(k>0){
        if(k%10==4||k%10==7){
            k/=10;
            continue;
        }else{
            return false;
        }
    }
    return true;
}
        

int TheLargestLuckyNumber::find(int n) {
       while(n>=3){
           if(is_luck(n)){
               return n;
           }
           n--;
       }
       return n;
}


