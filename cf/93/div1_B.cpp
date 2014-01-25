#include <iostream>
#include <string>
#include <vector>

using namespace std;
string str;
int sz_str = -1;
const int MAXN = 1000005;
int F[MAXN];



void build_failure(string pattern){
    F[0] = F[1] = 0;
    int sz = pattern.size();
    for(int i=2; i<=sz; i++){
        int j = F[i-1];
        for(;;){
            if(pattern[j]==pattern[i-1]){
                F[i] = j+1;
                break;
            }else{
                if(j==0){
                    break;
                }else{
                    j = F[j];
                }
            }
        }
    }
}

bool kmp(string pattern){
    build_failure(pattern);
    int i=0, j=0; 
    int p_sz = pattern.size();
    vector<int> pos ;
    for(;;){
        if(j==sz_str)break;
        if(str[j]==pattern[i]){
            i++;j++;
            if(i==p_sz){
                pos.push_back(j-p_sz);
            }
        }
        else if(i>0) i=F[i];
        else j++;
    }

    if(pos[pos.size()-1] == sz_str-p_sz){
        if(pos.size()>=3){
            return true;
        }
    }
    return false;
}

bool endWith(string & text, string & sub){
    cout<<text<<" end with "<<sub<<endl;
    int s_sz = sub.size();
    int ptr_a = s_sz-1;
    int ptr_b = sz_str -1;
    while(ptr_a>=0 && ptr_b>=0){
        if(sub[ptr_a]==text[ptr_b]){
            ptr_a--,ptr_b--;
        }else{
            return false;
        }
    }
    return true;
}



void work(){
    build_failure(str);
    
    
    for(int i=0; i<=str.size(); i++){
        cout<<F[i]<<" ";
    }cout<<endl;
    
    /*
    cout<<kmp(str.substr(0,2))<<endl;;
    
    int high=sz_str, low = 1;
    int ans = -1;
    while(low<high){
        int mid = (high+low)/2;
        cout<<"current "<<low<<" "<<high<<" "<<mid<<endl;
        string sub = str.substr(0, mid);
        cout<<"end with = "<<endWith(str, sub)<<endl;
        if( endWith(str, sub) &&   kmp(sub) ){
            ans = mid;
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    cout<<" ans = "<<ans<<endl;

    */

    

    int t = F[sz_str];
    cout<<"t = "<<t<<endl;
    bool ok = false;
    for(int i=0; i<sz_str; i++){
        if(F[i]==t){
            ok = true;
            break;
        }
    }
    if(ok){
        cout<<str.substr(0, t)<<endl;
    }else{
        cout<<"Just a legend"<<endl;
    }

}


int main(){
    cin>>str;
    sz_str = str.length();
    work();

    return 0;
}

