#include<iostream>
using namespace std;

int fib(int n){
    if(n == 1 || n == 2) return 1;

    else return( fib(n-1) + fib(n-2) ); 
}

int main(){
    int n, i;
    cout<<"Enter the number for which you want to find the series: ";
    cin>>n;

    cout<<"The "<<n<<" number in fibonacci series is: "<<fib(n)<<" and the whole sreies is: "<<endl;

    for ( i = 1; i <= n; i++)
    {
        cout<<fib(i)<<" ";
    }
    

    return 0;
}