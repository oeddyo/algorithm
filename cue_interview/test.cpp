#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("input.txt");

int main(){
    fin>>S;

    int sz = S.size();
    int rec_start = -1;
    int rec_end = -1;
    int t_ans = -1;
    for(int i=0; i<sz; i++){
        for(int j=i+1; j<sz; j++){
            int front = i; 
            int rear = j;
            bool ok = true;
            while(front <= rear ){
                if(S[front]==S[rear]){ 
                    front++,rear--;
                }else{
                    ok=false;
                }
            }
            if(ok){
                if( j-i+1 >= t_ans){
                    t_ans = j-i+1;
                    rec_start = i;
                    rec_end = j;
                }
            }
        }
    }
    for(int i=rec_start; i<=rec_end; i++){
        cout<<S[i];
    }cout<<endl;


    return 0;
}

