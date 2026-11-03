#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int fibonacciRecursive(int n){
    if(n<=1)
        return n;
    return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
}

void fibonacciNonRecursive(int n){
    int a = 0,b=1,c;
    cout<<"Fibonacci Non Recursive:";
    for(int i=0;i<n;i++){
        cout<<a<<" ";
        c = a + b;
        a = b;
        b = c;
    }
    cout<<endl;
}

int main() {

    int n;
    cout<<"Enter no. of terms:";
    cin>>n;

    fibonacciNonRecursive(n);

    cout<<"Fibonacci Recursive:";
    for(int i=0;i<n;i++){
        cout<<fibonacciRecursive(i)<<" ";
    }
    cout<<endl;


    return 0;
}