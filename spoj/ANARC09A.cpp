#include <iostream>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

string S;
int T;

void work(){
    stack<int>  my_stack;
    int sz = S.size();
    int ans=0;
    int one=0, two=0;
    for(int i=0; i<sz&&(S[i]=='{'||S[i]=='}'); i++){
        if(S[i]=='{'){
            my_stack.push(1);
            one++;
        }else{
            if(!my_stack.empty()&&my_stack.top()==1){
                my_stack.pop();
                one--;
            }else{
                my_stack.push(2);
                two++;
            }
        }
    }
    //cout<<"one and two are "<<one<<" "<<two<<endl;

    ans+= (one/2);
    ans+= (one - (one/2)*2);
    ans+= two/2;
    ans+= two - (two/2)*2;
   /* 
    if(one<two){
        ans+=one*2;
        two-=one;
        ans+= (two/2);
    }else{
        ans+=two*2;
        one-=two;
        ans+= (one/2);
    }
    */
    cout<<T<<". "<<ans<<endl;
}
int main(){
    T = 1;
    while(cin>>S){
        if(S[0]=='-')break;
        work();
        T++;
    }
    return 0;
}

