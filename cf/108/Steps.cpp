#include <iostream>

#define MAX_SIZE 20000
#define INF 99999999999
using namespace std;
long long int n,m,k;
long long int init_x, init_y;

long long int data[MAX_SIZE][2];

void work(){
    long long int steps = 0;
    long long int cur_x=init_x, cur_y=init_y;
    long long int t1,t2,t;
    for(int i=0; i<k; i++){
        t1 = t2 = INF;
        long long int d_x = data[i][0];
        long long int d_y = data[i][1];
        if(d_x==0 && d_y!=0){
            if(d_y>0){
                t2 = (m-cur_y)/d_y;
            }else{
                t2 = (1-cur_y)/d_y;
            }
        }else if(d_x!=0 && d_y==0){
            if(d_x>0){
                t1 = (n-cur_x)/d_x;
            }else{
                t1 = (1-cur_x)/d_x;
            }
        }else if(d_x>0&&d_y>0){
            t1 = (n-cur_x)/d_x;
            t2 = (m-cur_y)/d_y;
        }
        else if(d_x>0&&d_y<0){
            t1 = (n-cur_x)/d_x;
            t2 = (1-cur_y)/d_y;
        }
        else if(d_x<0&&d_y>0){
            t1 = (1-cur_x)/d_x;
            t2 = (m-cur_y)/d_y;
        }
        else if(d_x<0&&d_y<0){
            t1 = (1-cur_x)/d_x;
            t2 = (1-cur_y)/d_y;
        }
        
        t = min(t1,t2);
        steps+=t;
        cur_x = cur_x+t*d_x;
        cur_y = cur_y+t*d_y;
    }
    cout<<steps<<endl;
}


int main(){
    cin>>n>>m;
    cin>>init_x>>init_y;
    cin>>k;
    for(int i=0; i<k; i++){
        cin>>data[i][0]>>data[i][1];
    }
    work();
    
    return 0;
}

