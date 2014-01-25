#include <iostream>

using namespace std;


int N,M;
const int MAXN = 100001;
int inc[MAXN];
int mydec[MAXN];

int d[MAXN];
void work(){
    //inc
    int front = 0, rear = 0;

    while(1){
        rear++;
        if(d[rear]>=d[rear-1] && rear<N)continue;
        else{
            for(int i=front; i<rear; i++){
                inc[i] = rear-1;
            }
            front = rear;
        }
        if(rear>=N)break;
    }
    
    front = N-1, rear = N-1;
    while(1){
        front--;
        if(d[front]>=d[front+1] && front>=0)continue;
        else{
            for(int i=rear; i>front; i--){
                mydec[i] = front+1;
            }
            rear = front;
        }
        if(front<0)break;
    }

    /*
    for(int i=0; i<N; i++){
        cout<<inc[i]<<" ";
    }cout<<endl;
    for(int i=0; i<N; i++){
        cout<<mydec[i]<<" ";
    }cout<<endl;
    */


    for(int i=0; i<M; i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        if(inc[a]>=mydec[b]){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
}


int main(){

    cin>>N>>M;
    for(int i=0; i<N; i++){
        cin>>d[i];
    }
    work();





    return 0;
}

