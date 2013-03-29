#include <iostream>
using namespace std;

int A, B;
void get_ans(int &res, int all, int div){
    if(all<div){
        return ;
    }
    
    int sum = div;
    int cnt = 1;
    int cur = -1;
    int rec = -1;
    while(sum<=all){
        cur = sum;
        rec = cnt;
        sum += sum;
        cnt += cnt;
    }
    int left = all-cur;
    res += rec;
    get_ans(res, left, div);
}


void work(){
    int ans;
    get_ans(ans, A,B);
    cout<<"ans = "<<ans<<endl;
}


int main(){
    cin>>A>>B;

    work();


    return 0;
}

