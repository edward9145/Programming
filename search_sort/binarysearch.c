#include <stdio.h>
#define LEN 20 

int binarysearch(int A[],int low,int high,int x)
{
	int mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(x<A[mid])
			high=mid-1;
		else if(x>A[mid])
			low=mid+1;
		else
			return mid;              
	}
	return -1;
}

int main(){
	int i;
	int test[LEN];
	for(i=0; i<LEN; i++) test[i] = i*i; 
	for(i=0; i<LEN; i++) printf("%d ", test[i]); 
	printf("\n");
	
	int id = binarysearch(test, 0, LEN-1, 25);
	printf("id=%d", id);
	printf("\n");
}

