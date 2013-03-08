#include <iostream>

using namespace std;


int get_range(int A[], int left, int right){
    int mid = (left+right)>>1;
    if(right-left<=2){
        if(A[left]==A[right]){
            return A[mid];
        }else{
            if(A[left]==A[mid]){
                return A[right];
            }else{
                return A[left];
            }
        }
    }
    int t_left = get_range(A,left, mid-1);
    int t_right= get_range(A,mid+1, right);
    if(t_left==t_right){
        return A[mid];
    }else{
        if(t_left==A[mid]){
            return t_right;
        }else if(t_right==A[mid]){
            return t_left;
        }
    }
}

int odd_occurrences_in_array ( int A[], int N ) {
    return get_range(A, 0, N-1);
}


int A[10000000];
int main(){
    int cnt=0;
    while(cin>>A[cnt]){
        cnt++;
    }
    cout<<"cnt = "<<cnt<<endl;
    cout<<odd_occurrences_in_array(A, cnt)<<endl;
    
    //int A[] = {9,3,9,3,9,7,9};
    //cout<<odd_occurrences_in_array(A, 7)<<"!"<<endl;
    //int A[] = {9,3,9};
    //cout<<odd_occurrences_in_array(A,3)<<endl;
    return 0;
}

