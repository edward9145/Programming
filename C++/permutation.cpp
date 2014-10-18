#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    const int N = 5;
    int arr[N] = {1,2,3,3,5};

    sort(arr, arr+N);

    do{
        for(int i=0; i<N; i++){
            cout << arr[i] << ' ';
        }
        cout << endl;
    }while(next_permutation(arr, arr+4));
    return 0;
}
