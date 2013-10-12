#include <stdio.h>
#define LEN 20 
#define MAX 100

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void heapify(int A[], int idx, int max){
	int largest = idx;
	int left = idx*2+1;
	int right = idx*2+2;
	if(left<max && A[left]>A[idx]) largest = left;
	if(right<max && A[right]>A[largest]) largest = right;
	if(largest != idx){
		swap(&A[largest], &A[idx]);
		heapify(A, largest, max);
	}
}

void build_maxheap(int A[], int len){
	int i;
	for(i=len/2-1; i>=0; i--)
		heapify(A, i, len);
}


void heapsort(int A[], int len){
	build_maxheap(A, len);
	int i;
	for(i=len-1; i>0; i--){
//		int j;
//		for(j=0; j<len; j++) printf("%d ", A[j]); printf("\n");
		swap(&A[0], &A[i]);
		heapify(A, 0, i);
	}
}	

int main(){
	int i;
	int test[LEN];
	for(i=0; i<LEN; i++) test[i] = rand()%MAX; 
	for(i=0; i<LEN; i++) printf("%d ", test[i]); 
	printf("\n");

	heapsort(test, LEN);

	for(i=0; i<LEN; i++) printf("%d ", test[i]); 
	printf("\n");
}
