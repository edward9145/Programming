#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class elem{
    public:
    int alpha;
    int beta;
    int ab;
    elem(int a, int b):alpha(a), beta(b){
        ab = a*b;
    }
    bool operator < (const elem &e) const {
        return ab < e.ab;
    }
};

void print_elem(const elem &e){
    cout << "{" << e.alpha << "x" << e.beta << "=" << e.ab << "}" << endl;
}

bool less_alpha(const elem &e1, const elem &e2){
    return e1.alpha < e2.alpha;
}

bool less_beta(const elem &e1, const elem &e2){
    return e1.beta < e2.beta;
}

int main(){

    vector<elem> es;
    es.push_back(elem(0,1));
    es.push_back(elem(3,0));
    es.push_back(elem(1,2));
    es.push_back(elem(1,4));
    es.push_back(elem(2,3));

    for_each(es.begin(), es.end(), print_elem);

    cout << endl << "sort by ab:" << endl;
    sort(es.begin(), es.end());
    for_each(es.begin(), es.end(), print_elem);

    cout << endl << "sort by alpha:" << endl;
    sort(es.begin(), es.end(), less_alpha);
    for_each(es.begin(), es.end(), print_elem);

    cout << endl << "sort by beta:" << endl;
    sort(es.begin(), es.end(), less_beta);
    for_each(es.begin(), es.end(), print_elem);


    const int N = 5;
    int arr[N] = {1,2,3,3,2};
    sort(arr, arr+N);
    if(binary_search(arr, arr+N, 3)){
        pair<int*, int*> bounds = equal_range(arr, arr+N, 3);
        cout << "arr@" << arr << endl;
        cout << "bounds@" << bounds.first << "," << bounds.second << endl;
        cout << "found 3 in arr: [" << (bounds.first - arr) << "," << (bounds.second - arr) << ")" << endl ;
    }
    int* low = lower_bound(arr, arr+N, 2);
    int* up = upper_bound(arr, arr+N, 2);
    cout << "found first 2 in arr " << low - arr << endl;
    cout << "found last 2 in arr " << up - arr << endl;

    int myints[] = {10,20,30,30,20,10,20,10};
    vector<int> v(myints, myints+8);
    sort(v.begin(), v.end());
    vector<int>::iterator iterLow, iterUp;
    iterLow = lower_bound(v.begin(), v.end(), 20);
    iterUp = upper_bound(v.begin(), v.end(), 20);
    cout << "lower " << *iterLow << " at " << (iterLow - v.begin()) << endl;
    cout << "upper " << *iterUp << " at " << (iterUp - v.begin()) << endl;
    return 0;
}

