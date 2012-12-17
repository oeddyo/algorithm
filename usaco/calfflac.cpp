/*
ID: xieke.b1
PROG: calfflac
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ofstream fout("calfflac.out");
ifstream fin ("calfflac.in");

const int MAXN = 25000;
int mapping[MAXN];

int main(){
    string t,s;
    while(getline(fin,t)){
        s+=t;
        s+='\n';
    }
    //cout<<"original len is "<<s.size()<<endl;
    int sz = s.size();
    string pure="";
    int cnt = 0;
    for(int i=0; i<sz; i++){
        if((s[i]>='a'&&s[i]<='z') ){
            pure+=s[i];
            mapping[cnt++] = i;
        }else if(s[i]>='A' && s[i]<='Z'){
            pure+=s[i]-'A' + 'a';
            mapping[cnt++] = i;
        }
    }
    /*
    for(int i=0; i<pure.size(); i++){
        cout<<"mapping "<<i<<" to "<<mapping[i]<<endl;
    }
    */
    int front, rear, mid;

    //mid
    int p_sz = pure.size();
    int r_left=0, r_right=0;
    int t_max = 1;
    //cout<<"pure size "<<pure.size()<<endl;
    for(int mid=1; mid<p_sz-1; mid++){
        front = mid-1, rear = mid+1;
        while(front>=0 && rear<p_sz && pure[front]==pure[rear]){
            if(rear-front+1>t_max){
                t_max = rear-front+1;
                r_left = front, r_right = rear;
            }
            front--, rear++;
        }
    }
    //cout<<"t_max here "<<t_max<<" left right are "<<r_left<<" "<<r_right<<endl;
    for(int mid = 0; mid<p_sz-1; mid++){
        front = mid, rear = mid+1;
        while(front>=0 && rear<p_sz && pure[front]==pure[rear]){
            if(rear-front+1>t_max){
                t_max = rear-front+1;
                r_left = front, r_right = rear;
            }
            front--, rear++;
        }
    }
    //cout<<"pure is "<<pure<<endl;
    //cout<<"r_left, r_right, len are "<<r_left<<" "<<r_right<<" "<<r_right-r_left+1<<endl;
    //cout<<"mapping "<<mapping[r_left]<<" "<<mapping[r_right]<<endl;
    fout<<t_max<<endl;
    for(int i=mapping[r_left]; i<=mapping[r_right]; i++){
        fout<<s[i];
    }fout<<endl;



    return 0;
}

