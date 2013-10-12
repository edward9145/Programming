#include <stdio.h>
#define LEN 20 
#define MAX 100

void merge(int A[], int p, int q, int r){
	int n1 = q-p+1;
	int n2 = r-q;
	int* L = (int*)malloc(sizeof(int)*n1);
	int* R = (int*)malloc(sizeof(int)*n2);
	int i,j,k;
	for(i=0; i<n1; i++) L[i] = A[p+i];
	for(j=0; j<n2; j++) R[j] = A[q+1+j];
	i=0; j=0;
	for(k=p; k<=r; k++){
		if(i>=n1 || j>=n2) break;
		if(L[i]<=R[j]) A[k] = L[i++];
		else A[k] = R[j++];
	}
	if(i>=n1) for(;k<=r; A[k++]=R[j++]);	
	if(j>=n2) for(;k<=r; A[k++]=L[i++]);	

//	for(k=p; k<=r; k++) printf("%d ", A[k]);
//	printf("\n");
}

void mergesort(int A[], int p, int r){
	if(p<r){
		int q = (p+r)/2;
		mergesort(A, p, q);
		mergesort(A, q+1, r);
		merge(A, p, q, r);
	}
}

int main(){
	int i;
	int test[LEN];
	for(i=0; i<LEN; i++) test[i] = rand()%MAX; 
	for(i=0; i<LEN; i++) printf("%d ", test[i]); 
	printf("\n");

	mergesort(test, 0, LEN-1);

	for(i=0; i<LEN; i++) printf("%d ", test[i]); 
	printf("\n");
}
