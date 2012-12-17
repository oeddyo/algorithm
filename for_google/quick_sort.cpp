#include <iostream>
#include <algorithm>
using namespace std;


int partition(int A[], int left, int right){
        int pivot = rand()%(right-left)+left;
        swap(A[pivot], A[left]);
        pivot = left;
        int i = left, j = right-1;
        while(1){
                while(A[i]<=A[pivot]) i++;
                while(A[j]>A[pivot]) j--;
                if(i<j){
                        swap(A[i], A[j]);
                }else{
                        break;
                }
        }
        swap(A[left], A[j]);
        return j;
}


void qsort(int A[], int left, int right){
        if(right-left>1){
                int pos = partition(A, left, right);       
                cout<<"pos "<<pos<<endl;
                qsort(A, left, pos-1);
                qsort(A, pos+1, right);
        }
}

int main(){
        int A[256];
        int N = 25;
        for(int i=0; i<N; i++){
                A[i] = (int) rand()%1000;
        }
        qsort(A, 0, N);
        for(int i=0; i<N; i++){
            cout<<A[i]<<endl;        
        }
    return 0;
}
