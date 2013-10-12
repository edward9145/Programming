#include <stdio.h>
#define LEN 20 
#define MAX 100

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubblesort(int A[], int p, int r){
	int i,j;
	for(i=p; i<=r; i++)
		for(j=r; j>i; j--)
			if(A[j]<A[j-1])
				swap(&A[j], &A[j-1]);

}	

int main(){
	int i;
	int test[LEN];
	for(i=0; i<LEN; i++) test[i] = rand()%MAX; 
	for(i=0; i<LEN; i++) printf("%d ", test[i]); 
	printf("\n");

	bubblesort(test, 0, LEN-1);

	for(i=0; i<LEN; i++) printf("%d ", test[i]); 
	printf("\n");
}
