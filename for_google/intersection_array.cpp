#include <iostream>
using namespace std;


void intersect(int A[], int B[], int N1, int N2){
int i = 0, j =0;
while(1){
        while(A[i]<B[j] && i<N1)i++;
        while(B[j]<A[i] && j<N2)j++;
        if(i>=N1||j>=N2)break;
if(A[i]==B[j]){
                cout<<A[i]<<endl;
        i++,j++;
        }
}
}


int main(){
        int A[] = {4,5,6,7,8,9,33};
int B[] = {4,5,7,8,9,33};
int N1 = 7;
int N2 = 6;
intersect(A, B, N1, N2);




return 0;
}
