#include <stdio.h>
#include <stdlib.h>

int atoi(const char *str){
	int sum = 0;
	int sign = 1;
	int ok = 1;

    const char *ptr = str;
	if(ptr==NULL){
		printf("Error\n");
	}
	if(*ptr!='\0'){
		if(*ptr=='-'){
			sign=-1;
		}
        ptr++;
	}else{
		printf("Error, empty str");
    }	
	while(*ptr!='\0'){
		
		if( (*ptr-'0')>=0 && (*ptr-'0')<=9){
			sum = sum*10+(*ptr-'0');
		}else{
			printf("Error, not valid number");
		}
		ptr++;
    }			
	return sign*sum;
}


main(){
	
    const int *cpi;
    int b = 333;
    cpi = &b;
    const int * const cc = &b;
    printf("%d",cc);
    char *str = "-12337837";
	printf("%d", atoi(str));
return 0;
}
