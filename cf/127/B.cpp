#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>


using namespace std;
int N,T;

typedef vector<string> vs;
typedef pair<string, string> pss;
vs Lesha;
vs orig;
vs perms[50];
vs probs[20];
int p_cnt = 0;

string tmp;

void print(vs &a){
    for(int i=0; i<a.size(); i++){
        cout<<a[i]<<" ";
    }cout<<endl;
}

int inv(vs &a, vs &b){
    int res = 0;

    int sz = a.size();
    map< pair<string, string>, int> tmap;
    //a is origion
    for(int i=0; i<sz; i++){
        for(int j=i+1; j<sz; j++){
            tmap[ pss(a[i],a[j]) ] = 1;
        }
    }
    for(int i=0; i<sz; i++){
        for(int j=i+1; j<sz; j++){
            pss tt(b[i], b[j]);
            if( tmap.find(tt)== tmap.end()){
                res++;
            }
        }

    }
    return res;
}

bool is_sub(vs & A, vs & B){
    int pa = 0;
    int pb = 0;
    int szA = A.size();
    int szB = B.size();
    while( pa<szA && pb<szB){
        if(A[pa] == B[pb]){
            pa++,pb++;
        }else{
            pb++;
        }
    }
    if(pa==szA){
        return true;
    }
    return false;
}
void work(){
    bool brand_new = true;
    
    int largest_score = 0;
    int index;
    for(int i=0; i<T; i++){
        for(int j=0; j<p_cnt; j++){
            if(is_sub(perms[j], probs[i])){
                brand_new = false;
                //print(perms[j]);
                //print(probs[i]);
                int score = N*(N-1)/2 - inv(orig, perms[j]) +1;
                if(score>largest_score){
                    largest_score = score;
                    index = i;
                }
            }
        }
    }
    
    
    
    if(brand_new){
        cout<<"Brand new problem!"<<endl;
    }else{
        cout<<index+1<<endl;
        cout<<"[:";
        for(int i=0; i<largest_score; i++)cout<<"|";
        cout<<":]"<<endl;
    }
}

int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>tmp;
        Lesha.push_back(tmp);
    }
    orig = Lesha;
    cin>>T;
    for(int i=0; i<T; i++){
        int tmp_N;
        cin>>tmp_N;
        for(int j=0; j<tmp_N; j++){
            cin>>tmp;
            probs[i].push_back(tmp);
        }
    }

    sort(Lesha.begin(), Lesha.end());
    perms[p_cnt++] = Lesha;
    //print(Lesha); 
    while(next_permutation(Lesha.begin(), Lesha.end())){
        perms[p_cnt++] = Lesha;
        //print(Lesha);
    }
    work();

    return 0;
}

