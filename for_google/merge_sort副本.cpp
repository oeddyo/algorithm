#include <iostream>


#define INF 2100000000

using namespace std;


void merge(int A[], int left, int mid, int right){
        int *L = (int *)malloc(sizeof(int)*(mid-left+2));
        int *R = (int *)malloc(sizeof(int)*(right-mid+2));
        for(int i=0; i< mid-left; i++){
                L[i] = A[i+left];
        }
        L[mid-left] = INF;
        for(int j=0; j< right-mid; j++){
                R[j] = A[j+mid];        
        }
        R[right-mid] = INF;
        int i = 0, j = 0;
        for(int k = left; k<right; k++){
                if(L[i] < R[j]){
                        A[k] = L[i];
                        i++;        
                }else{
                        A[k] = R[j];
                        j++;
                }
        }
        free(L);
        free(R);
}

void merge_sort(int A[ ], int left, int right){
    // [ )
    if(left+1<right){
        int mid;
        mid = left + (right-left)/2;
        //cout<<left<<" "<<mid<<" "<<right<<endl;
        merge_sort(A, left, mid);
        merge_sort(A, mid , right);
        merge(A, left, mid, right);
    }
}

int main(){
        int A[256];
        int N = 100;
        for(int i=0; i<N; i++){
                A[i] = (int) rand()%5500;
        }
        merge_sort(A, 0, N);

        for(int i=0; i<N; i++){
            cout<<A[i]<<endl;
        }
    return 0;
}
