#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

long long int p,d;
long long int to_number(string s){
    long long int t = 0;
    for(int i=0; i<s.size(); i++){
        t = t*10 + s[i]-'0';
    }
    return t;
}

string to_string(long long int t){
    string s= "";
    while(t){
        s+= char((t%10)+'0');
        t/=10;
    }
    reverse(s.begin(), s.end());
    return s;
}
int larger_than(string &a, string &b){
    if(a.size()>b.size())return 1;
    if(a.size()<b.size())return -1;
    for(int i=0; i<a.size(); i++){
        if(a[i]>b[i])
            return 1;
        else if(a[i]<b[i])
            return -1;
    }
    return 0;
}

void work(){
    long long int small = p-d;
    long long int large = p;
    int large_dig = to_string(large).size();
    string large_string = to_string(large);
    string cur_s = to_string(small);
    int pos = cur_s.size()-1;
    string ans;
    while(1){
        bool modified = false;
        if(pos == -1){
            if( cur_s.size()+1>large_dig){
                break;
            }
            cur_s.insert(cur_s.begin(), '1');
            pos = 0;
        }
        string t = cur_s;
        for(int i=cur_s[pos]-'0'; i<=9; i++){
            t[pos] = char(i+'0');
            if( larger_than(t,large_string) == 1){
                continue;
            }
            else{
                cur_s = t;
                modified = true;
                ans = cur_s;
            }
        }
        if( larger_than(cur_s, large_string) == 1 )break;
        //if(to_number(cur_s)>large)break;
        pos-=1;
        if(modified==false)break;
    }
    cout<<ans<<endl;
}


int main(){
    cin>>p>>d;
    work();
    
    return 0;
}



