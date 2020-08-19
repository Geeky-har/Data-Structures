#include<iostream>
using namespace std;

void insert(int a[], int n){
	for(int i=1;i<n;i++){
		int temp=a[i];
		int j=i-1;
			while(j>=0 && temp<a[j]){
				a[j+1]=a[j];
				j--;
			}
		a[j+1]=temp;
	}
	cout<<"\n \nThe sorted array is: \n";
	for(int m=0;m<n;m++){
		cout<<a[m]<<" ";
	}
}
int main(){
	int n,a[30],i;
	cout<<"*****************************************INSERTION SORT************************************"<<endl<<endl;
	cout<<"Enter the size of array: \n";
	cin>>n;
	cout<<"Enter the elements in the array: \n";
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"The elements you have entered are: \n";
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	insert(a,n);
	return 0;
}
