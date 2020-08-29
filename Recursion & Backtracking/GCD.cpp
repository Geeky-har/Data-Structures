//Greatest Common divisor(using euclids theorem) with recursion: 

#include<iostream>
using namespace std;

int GCD(int n1, int n2){
    if(n1 == n2) return(n1);

    if(n1 % n2 == 0) return(n2);

    if(n2 % n1 == 0) return(n1);

    if(n1 > n2) return( GCD(n1 % n2, n2) ); // if first number is greater, change it to n1 % n2

    else return( GCD(n1, n2 % n1) );        // if second number is greater, change it to n2 % n1
}

int main(){
    int num1, num2;
    cout<<"Enter two number: "<<endl;;
    cin>>num1>>num2;

    cout<<"The GCD of "<<num1<<" and "<<num2<<" is: "<<GCD(num1, num2);

    return 0;
}