#include <stdio.h>
#define LEN 20 
#define MAX 100

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int A[], int p, int r){
	int x = A[r];
	int i = p-1;
	int j;
	for(j=p; j<r; j++){
		if(A[j] <= x){
			i++;
			swap(&A[i], &A[j]);
		}
	}
	swap(&A[i+1], &A[r]);
	return i+1;
}

void quicksort(int A[], int p, int r){
	int q;
	if(p<r){
		q = partition(A, p, r);
		quicksort(A, p, q-1);
		quicksort(A, q+1, r);
	}

}	

void quicksort2(int arr[], int l, int r){
	int swap, i, j;
	i = l;
	j = r;
	swap = arr[i];
	while(i<j){
		while(i<j && swap<arr[j]) j--;
		if(i<j) arr[i++] = arr[j];
		while(i<j && arr[i]<swap) i++;
		if(i<j) arr[j--] = arr[i];
	}
	arr[i] = swap;

	if(l<i) quicksort2(arr, l, i-1);
	if(i<r) quicksort2(arr, j+1, r);
}

int main(){
	int i;
	int test[LEN];
	for(i=0; i<LEN; i++) test[i] = rand()%MAX; 
	for(i=0; i<LEN; i++) printf("%d ", test[i]); 
	printf("\n");

	quicksort(test, 0, LEN-1);

	for(i=0; i<LEN; i++) printf("%d ", test[i]); 
	printf("\n");
}
