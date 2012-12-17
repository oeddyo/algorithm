/*
ID: xieke.b1
PROB: zerosum
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <stack>
#include <vector>
#include <string.h>

using namespace std;
ifstream fin("zerosum.in");
ofstream fout("zerosum.out");

const int INF = 999999999;
int N;
typedef vector<int> vi;
typedef vector<string> vs;
vs ans;
const int MAXN = 30000;


int cnt = 0;

int process(string t){
    t+='@';
    stack <int> nums;
    stack <char> ops;

    int len = t.size();
    int sum = 0; 
    int t_sum = 0;
    
    for(int i=0; i<len; i++){
        if(t[i]==' '){
            continue;
        }
        if(t[i]>='0'&&t[i]<='9'){
            t_sum = t_sum*10+t[i]-'0';
        }else{
            if(!ops.empty()){
                //cout<<"ok, now we have "<<t[i]<<" and try to do the two "<<t_sum<<" "<<nums.top()<<endl;
                char op = ops.top();
                ops.pop();
                int tmp;
                if(op=='+'){
                    tmp = t_sum + nums.top();
                }else if(op=='-'){
                    tmp =  nums.top() - t_sum;
                }
                nums.pop();
                nums.push(tmp);
                ops.push(t[i]);
            }else{
                //cout<<"ok insert "<<t[i]<<endl;
                ops.push(t[i]);
                nums.push(t_sum);
            }
            t_sum = 0;
        }
    }
    sum = nums.top();
    return sum;
}


void dfs(int cur, string t){
    if(cur==N){
        if(process(t)==0){
            //cout<<t<<endl;
            ans.push_back(t);
        }
        return;
    }
    cur++;
    string add;
    add += cur+'0';
    dfs(cur, t+"+"+add);
    dfs(cur, t+"-"+add);
    //dfs(cur, t+"*"+add);
    dfs(cur, t+" "+add);
}



void work(){
    dfs(1, "1");
    sort(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++){
        fout<<ans[i]<<endl;
    }

}


int main(){
    fin>>N;
    work();
    return 0;
}

