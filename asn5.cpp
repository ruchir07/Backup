#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <ctime>

using namespace std;

void display(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int partition(int low,int high,int arr[]){

    int pivot = arr[high];
    int i=low-1;

    for(int j=low;j<high;j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[i+1],arr[high]);
    return i+1;

}

void quicksort(int low,int high,int arr[]){
    if(low < high){
        int pIndex = partition(low,high,arr);
        quicksort(low,pIndex-1,arr);
        quicksort(pIndex+1,high,arr);
    }
}

int random_partition(int low,int high,int arr[]){
    int randomIdx = low + rand() % (high-low+1);
    swap(arr[randomIdx],arr[high]);
    return partition(low,high,arr);
}

void randomized_quicksort(int low,int high,int arr[]){
    if(low < high){
        int pIndex = random_partition(low,high,arr);
        randomized_quicksort(low,pIndex-1,arr);
        randomized_quicksort(pIndex+1,high,arr);
    }
}

int main() {

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int a[n], b[n];

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    srand(time(0));
    quicksort(0,n-1,a);

    cout<<"Deterministic Quick Sort: \n";
    display(a,n);

    randomized_quicksort(0,n-1,b);
    cout<<"Randomized Quick Sort: \n";
    display(b,n);

    return 0;
}