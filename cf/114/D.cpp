#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
int n,l,k;
const int MAXN = 251;

typedef pair<int, int> mypair;
int prob[MAXN];
int b[MAXN];
vector <mypair> contest;


bool mycmp(const mypair &a, const mypair &b){
    //return (double(a.first)/double(a.second)) < double(b.first)*double(b.second);
    return a.first*a.second < b.first*b.second;
}

    
void work(){
    sort(contest.rbegin(), contest.rend(),mycmp); 
    //sort(contest.rbegin(), contest.rend());
    int cnt = 0;
    int bags = k;
    double ans = 1;
    int prize = 0;
    for(int i=0; i<contest.size(); i++){
        if(contest[i].first==-1)prize++;
    }
    for(int i=0; i<contest.size(); i++){
        int p = contest[i].second;
        int n_b = contest[i].first;
        if(bags+n_b>=0){
            bags+=n_b;
            ans*=(p/100.0);
            cnt++;
            if(cnt==l|| (bags>=prize && prize+cnt>=l)){
                break;
            }
        }else{
            ans=0;
            break;
        }
    }
    cout<<setprecision(12)<<setiosflags(ios::fixed)<<ans<<endl;
}

int main(){
    cin>>n>>l>>k;
    for(int i=1; i<=n; i++){
        cin>>prob[i];
    }
    for(int i=1; i<=n; i++){
        cin>>b[i];
    }
    for(int i=1; i<=n; i++){
        contest.push_back(mypair( b[i], prob[i]));
    }

    work();
    return 0;

}
