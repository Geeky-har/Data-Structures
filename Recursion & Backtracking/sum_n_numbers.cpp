// C++ program to find sum of first n natural numbers

#include<iostream>
using namespace std;

int sum(int num){
    int s;
    if(num == 1) return(num);

    else return(s = num + sum(num - 1));

}

int main(){
    int n;
    cout<<"Enter the natural number for which you want to sum: "<<endl;
    cin>>n;

    cout<<"The sum is: "<<sum(n)<<endl;

    return 0;
}