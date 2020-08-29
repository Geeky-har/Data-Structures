// C++ code to perform factorial of a number by recursion
#include<iostream>
using namespace std;

int fac(int num){
    if(num == 0 || num == 1) return 1; // base case for factorial

    else return(num * fac(num-1) );  // recursive call with intermediate operation
}

int main(){
    int n;
    cout<<"Enter the number to find the factorial: "<<endl;
    cin>>n;

    cout<<"The factorial of "<<n<<" is: "<<fac(n);

    return 0;
}