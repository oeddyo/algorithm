#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#define eps 1e-9
using namespace std;
typedef  pair<double, double>  mypair;
int N,D,T;

priority_queue< mypair, vector< mypair>, greater<mypair> > Q;

//vector< pair<double, double> > V;

bool intersect(mypair a, mypair b){
    if(a.second>=b.first ){
        return true;
    }else{
        return false;
    }
}


void work(){
    int cnt = 0;
    while(!Q.empty()){
        mypair t = Q.top();
        Q.pop();
        if(!Q.empty()){
            mypair next = Q.top();
            Q.pop();
            if (intersect(t, next)){
                mypair w(next.first, min(t.second,next.second     ));
                //cout<<"insert "<<next.first<<" "<<t.second<<endl;
                Q.push(w);
            }else{
                Q.push(next);
                cnt+=1;
            }
        }else{
            cnt+=1;
            break;
        }
    }
    cout<<"Case "<<T<<": "<<cnt<<endl;
}

int main(){
    double t1, t2;
    double a,b;
    T=0;
    while(cin>>N>>D){
        T++;
        if(N==0&&D==0)break;
        Q = priority_queue< mypair, vector< mypair>, greater<mypair> >();
        bool ok=1;
        for(int i=0; i<N; i++){
            cin>>a>>b;
            double q = (double)D*(double)D - (double)b*(double)b;
            if(q< 0 ){
                ok=0;
            }
            t1 = a+sqrt(q);   
            t2 = a-sqrt(q);
            //cout<<t2<<" "<<t1<<endl;

            Q.push(mypair(t2,t1));


        }
            /*cout<<"---"<<endl;
            priority_queue< mypair, vector< mypair>, greater<mypair> >ww;
            ww = Q;
            while(!ww.empty()){
                cout<<ww.top().first<<" "<<ww.top().second<<endl;
                ww.pop();
            }
            cout<<"---"<<endl;
            */
        if(D<=0){
            ok=0;
        }
        if(ok){
            work();
        }else{
            cout<<"Case "<<T<<": "<<-1<<endl;
        }

    }

    return 0;
}

