#include <iostream>
#include <string>


using namespace std;

const int MAXN = 50000;
//char P[MAXN], Text[MAXN];
string P,Text;
int failure[MAXN];
int T;

void build_failure(){
    failure[0] =0;
    failure[1] = 0;
    unsigned sz = P.length();
    int j;
    for(int i=2; i<=sz; i++){
        /*
        if(i<0  || i>sz){
            cout<<"ERROR: "<<i<<endl;
        }
        */
        j = failure[i-1];
        for(;;){
            if(P[i-1]==P[j]){
                failure[i] = j+1;
                break;
            }
            if(j==0){
                failure[i] = 0;
                break;
            }
            j = failure[j];
        }
    }
    /*
    for(int i=0; i<=sz; i++){
        cout<<failure[i]<<" ";
    }cout<<endl;
*/
  
}

void work(){
    build_failure();
    //int text_sz = strlen(Text);
    //int p_sz = strlen(P);
    unsigned  text_sz = Text.length();
    unsigned  p_sz = P.length();
    int i,j=0;
    int ans = 0;

    for(;;){
        /*
        if(i<0 || j<0 || i>p_sz || j>text_sz){
            cout<<"ERROR: "<<i<<" "<<j<<endl;
        }
        */

        if(j>=text_sz)break;

        if(Text[j]==P[i]){
            i++;
            j++;
            if(i>=p_sz){
                i=failure[p_sz];
                ans++;
                continue;
            }
        }else if(i>0){
            i = failure[i];
        }else{
            j++;
        }
    }
    cout<<ans<<endl;
}


int main(){
    cin>>T;
    //scanf("%d",&T);
    while(T--){
        //scanf("%s",P);
        //scanf("%s",Text);
        cin>>P;
        cin>>Text;
        work();
    } 
    return 0;
}

