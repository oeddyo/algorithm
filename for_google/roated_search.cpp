#include <iostream>
using namespace std;


int b_find_gap(int A[], int left, int right){
        int mid, low = left, high = right;
        while(low < high){
            mid = low + (high-low)/2;
            if( A[mid] > A[low]){
                low = mid+1;
            }else{
                high = mid;
            }
        }
        return mid;
}

int b_search(int A[], int key, int left, int right){
        int mid, res = -1, low = left, high = right;
        while(low<high){
            mid = low + (high-low)/2;
            cout<<low<<" "<<mid<<" "<<high<<endl;
            if(A[mid]==key){
                        return mid;
            }
            if(A[mid] < key){
                low = mid+1;
            }else{
                high = mid;
            }
        }
        return res;
}

int main(){
        int A[] = {4,5,6,7,8,9,33,1,2,3};
        int N = 10;
        int gap = b_find_gap(A, 0, N);        
        cout<<gap<<endl;
        int res1 = b_search(A,5, 0, gap+1);
        int res2 = b_search(A,5, gap+1, N);

        if(res1!=-1){
                cout<<"res is "<<res1<<endl;
        }
        if(res2!=-1){
                cout<<"res is "<<res2<<endl;
        }
    return 0;
}
