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


class Embassy {
    public:
            int visaApplication(vector <int> forms, int dayLength, int openTime) {
                int sz = forms.size();
                int days = 0;
                int now_time = 0;
                int spare = dayLength-openTime;
                int open_left = dayLength-openTime; 
                int open_right = dayLength;
                for(int i=0; i<sz; i++){
                    if(now_time <= open_left){
                        now_time = now_time+forms[i];
                    if(now_time<=open_right){
                        //get a new one

                }

            }
};


