#include <iostream>
#include <cmath>


#define MAXN 100002
using namespace std;
int data[MAXN],N;

/*void print_array(){for(int i=0;i <N;i++)cout<<data[i]<<" ";
    cout<<endl;
}*/

int partition(int low, int high){
    int pivot = (rand()%(high-low))+low;
    swap(data[pivot], data[low]);
    int front = low+1;
    int rear = high-1;
    while(1){
        while(front<high&& data[front]<=data[low]){
            front++;
        }
        while(rear>low&&data[rear]>data[low]) rear--;
        if(rear<=front)break;
        swap(data[rear],data[front]);
    }
    swap(data[rear], data[low]);
    return rear;
}

int median(int low, int high, int k){
    int pos = partition(low, high);
    //cout<<low<<" "<<high<<" "<<k<<endl;
    //cout<<"pos is "<<pos<<endl;
    if(low+k==pos){
        return data[pos];
    }else if(k+low<pos){
        return median(low, pos, k);
    }else{
        return median(pos+1, high, k+low-pos-1);
    }        
}

int main(){
            scanf("%d",&N);
            for(int i=0; i<N;i++)scanf("%d",&data[i]);
            cout<<median(0,N,N/2)<<endl;
            return 0;
}


