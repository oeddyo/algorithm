#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

const int MAXN = 100001;
int N;
int my_data[MAXN];
int neg[MAXN];
int pos[MAXN];
const int INF = 999999999;

int main(){
    //scanf("%d",&N);
    
    ifstream myfile;
    myfile.open("input.txt");

    myfile>>N;
    //cin>>N;
    for(int i=0; i<N; i++){
        //scanf("%d",&my_data[i]);
        //cin>>my_data[i];
        myfile>>my_data[i];
        if(i>0){
            if(my_data[i]>0 ){
                pos[i] = pos[i-1] + 1;
                neg[i] = neg[i-1];
            }
            else if(my_data[i]<0){
                neg[i] = neg[i-1] + 1;
                pos[i] = pos[i-1];
            }else{
                pos[i] = pos[i-1];
                neg[i] = neg[i-1];
            }
        }else{
            if(my_data[i]>0){
                pos[i] = 1;
            }
            else if(my_data[i]<0){
                neg[i] = 1;
            }else{
                pos[i] = 0;
                neg[i] = 0;
            }
        }
    }

    /* 
    for(int i=0; i<N; i++){
        cout<<"at "<<i<<" "<<pos[i]<<" "<<neg[i]<<endl;
    }
    */


    int ans = INF;
    

    for(int i=1; i<N; i++){
        int pre_neg = neg[i-1];
        int post_pos = pos[N-1] - pos[i-1];
        //cout<<"i = "<<i<<" "<<pre_neg<<" "<<post_pos<<endl;
        //cout<<"change "<<i-pre_neg<<" pos to neg "<<endl;
        //cout<<"change "<<N-i-post_pos<<" neg to pos"<<endl;
        int tmp_ans = (i-pre_neg) + (N-i-post_pos);
        ans = min(tmp_ans, ans);
    }
    ofstream out;
    out.open("output.txt");
    out<<ans<<endl;

    
    //cout<<"ha"<<endl;
    return 0;
}

