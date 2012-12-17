#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>

using namespace std;

int N;
string A,B;
long long int red_A=0, red_B = 0;
int work(){
    int sz_A = A.size();
    int sz_B = B.size();
    int round = 0;
    bool should_break = 0;
    long long int ans_a=0, ans_b = 0;
    int p_a = 0;
    int p_b = 0;
    while(1){
        //cout<<N<<endl;    
        if(A[p_a]=='R' && B[p_b]=='P'){
            red_A++;
        }else if(A[p_a]=='P' && B[p_b]=='R'){
            red_B++;
        }else if(A[p_a]=='R' && B[p_b]=='S'){
            red_B++;
        }else if(A[p_a]=='S' && B[p_b]=='R'){
            red_A++;
        }else if(A[p_a]=='P' && B[p_b]=='S'){
            red_A++;
        }else if(A[p_a]=='S' && B[p_b]=='P'){
            red_B++;
        }
        round++;
        if(round==N){
            ans_a += red_A;
            ans_b += red_B;
            break;
        }
        p_a++, p_b++;
        if(p_a==sz_A){
            p_a = 0;
        }
        if(p_b==sz_B){
            p_b=0;
        }
        if(p_a==0&&p_b==0){
            if(round<N){
                ans_a += (N/round)*red_A ;
                ans_b += (N/round)*red_B ;
                N = N%round;
                if(N<=0)break;
                red_A = 0, red_B = 0,round=0;
                continue;
            } 
        }
    }
    cout<<ans_a<<" "<<ans_b<<endl;
}


int main(){
    cin>>N;
    cin>>A;
    cin>>B;
    work();
    return 0;
}

