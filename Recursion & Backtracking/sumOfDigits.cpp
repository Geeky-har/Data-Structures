/* In this program we will calculate the sum of its digits of a number.
Eg: 123 = 1+2+3
*/
#include<iostream>
using namespace std;

int sum(int n){
    if(n == 0)
        return 0;

    else
        return( n % 10 + sum(n / 10) );
    
}

int main(){
    int n;
    cout<<"Enter a number to find the sum of its digits: "<<endl;
    cin>>n;

    cout<<"The sum of its digits is: "<<sum(n)<<endl;

    return 0;
}