#include <stdio.h>
#include <stdlib.h>

int b_s(int array[], int N){
	int low = 0, high = N,mid;
	while(low<high){
		mid = low+(high-low)/2;
		int expect = mid+1;
		if(array[mid]>expect){
			high=mid;
		}else{
			low=mid+1;
		}
	}
	return low+1;
}


main(){
    //int array[] = {1,2,3,4,5,6,7,8,9,10};
    int array[] = {2,3,4,5,6,7};
    int N = 7;
    int res = b_s(array,N+1);
    printf("res is %d\n",res);
    return 0;
}
