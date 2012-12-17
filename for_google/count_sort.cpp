#include <iostream>


#define MAXN 10000


using namespace std;






void count_sort(int A[], int N, int K){
        int C[MAXN];
        int B[MAXN];
        memset(C,0,sizeof(C));
        for(int i=0; i<N; i++){
                C[ A[i] ] ++;
        }
        for(int i=0; i<K-1; i++){
            C[i+1] +=C[i];
        }
        for(int i=N-1; i>=0; i--){
            B[ C[A[i]] - 1 ] = A[i];
            C[A[i]]--;
        }
        for(int i=0; i<N; i++){
            cout<<B[i]<<" ";
        }cout<<endl;
}



int main(){
        //int A[256];
        int A[] = {2,5,3,0,2,3,0,3};
        int N = 8;
        int K = 100;
        /*
        for(int i=0; i<N; i++){
                A[i] = (int) rand()%K;
                cout<<A[i]<<endl;
        }*/
        cout<<"_---------"<<endl;


        count_sort(A, N, K);
        return 0;
}
