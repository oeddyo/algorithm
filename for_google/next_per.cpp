#include <iostream>


using namespace std;


void reverse(int A[], int left, int right){
        int front = left, rear = right-1;
        while(front<rear){
                swap(A[front], A[rear]);
                front++, rear--;
        }
}

int _next_permutation(int A[], int N){
        int pos_k=-1, pos_l;
        int len = N;
        if(N<=1){
                return 0;
        }
for(int i = N-2;  i>=0; i--){
        if(A[i]<A[i+1]){
                        pos_k = i;
                break;
        }
}
if(pos_k==-1)return 0;


for(int i=N-1; i>=0; i--){
                if(A[i]> A[pos_k]){
                        pos_l  = i;
                break;
        }
        }
        swap(A[pos_k], A[pos_l]);
reverse(A, pos_k+1, N);
return 1;
}
void print_A(int A[], int N){
        for(int i=0; i<N;i++){
                cout<<A[i]<<",";
        }cout<<endl;
}



int main(){
        int A[] = {1,2,3,3};
        int N = 4;
        print_A(A, N);
        while( _next_permutation(A,N) == 1){
print_A(A,N);
}                


return 0;
}
