/*
ID: xieke.b1
PROG: pprime
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
ofstream fout("pprime.out");
ifstream fin ("pprime.in");

int A,B;
const int INF = 999999999;
vector<long long int> nums;

int rev(int number){
    int t_res = 0;
    while(number){
        t_res = t_res*10+number%10;
        number/=10;
    }
    return t_res;
}

int get_digit(int number){
    int t_res = 0;
    while(number){
        t_res++;
        number/=10;
    }
    return t_res;
}

inline long long int mypow(int k){
    long long int t = 1;
    for(int i=0; i<k; i++){
        t*=10;
    }
    return t;
}

void work(){
    int t_B = B;
    int digit = get_digit(B);
    digit = ((digit)/2);
    int max_value = mypow(digit);
    for(int i=5; i<=9; i++)
        if(i>=A && i<=B)
            nums.push_back(i);

    for(int left=1; left<max_value; left++){
        int right = rev(left);
        long long int value = left * mypow(get_digit(left)) + right;
        if(right&1==0)continue;
        //cout<<"left is "<<left<<" right is "<<right<<" value is "<<value<<endl;
        if(value>=A && value<=B)
            nums.push_back(value);    
    }
    
    digit = get_digit(B);
    max_value = mypow((digit)/2);
    digit = (digit)/2;
    for(int left=1; left<max_value; left++){
        for(int mid = 0; mid<=9; mid++){
            int right = rev(left);
            if(right&1==0)continue;
            long long int value = left*mypow(get_digit(left)+1) + mid*mypow(get_digit(left) ) + right;
            //cout<<"left is "<<left<<" right is "<<right<<" value is "<<value<<endl;
            if(value>=A && value<=B)
                nums.push_back(value);
        }
    }

    sort(nums.begin(), nums.end());
    int sz = nums.size();
    cout<<sz<<endl;
    for(int i=0; i<sz; i++){
        
        long long int v = nums[i];
        int limit = sqrt(v);
        bool prime = true;
        for(int j=2; j<=limit; j++){
            if(v%j==0){
                prime = false;
                break;
            }
        }
        if(prime){
            fout<<v<<endl;
        }
    }
}

int main(){
    fin>>A>>B;
    work();
    return 0;
}

