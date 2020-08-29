//Given an array, check whether the array is in sorted order with recursion.
#include<iostream>
using namespace std;

bool ArrayInSortedOrder(int arr[], int n){
    if(n == 1) return 1;    //base case for the function

    else{
        return (arr[n-1] < arr[n-2])?0:ArrayInSortedOrder(arr, n-1);
        /*if last element is smaller than its corresponding element than return 0
        if not then, it will call recursively with size less than the previous 
        call, and finally when size is one(i.e, when it will reach the first element)
        it will return 1 which means array is sorted*/
    }
}

int main(){
    int n, arr[1000], i;
    bool ch;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n;

    cout<<"Now enter "<<n<<" elements in the array: "<<endl;
    for(i=0; i<n; ++i){
        cin>>arr[i];
    }

    ch = ArrayInSortedOrder(arr,n);
    (!ch)?cout<<"Array is unsorted":cout<<"Array is sorted";

    return 0;
}