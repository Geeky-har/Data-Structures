#include<bits/stdc++.h>
using namespace std;

void insert(int item, int loc, int n, int a[]){
	int i;
	for(i=n-1;i>=(loc-1);i--){
		a[i+1]=a[i];
	}
	a[loc-1]=item;
	n=n+1;
	cout<<"The resultant array is: "<<endl;
		for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	
}

int main(){
	int n,a[100],i,item,loc;
	cout<<"Enter the size of the array"<<endl;
	cin>>n;
	cout<<"Enter the elements into the array: "<<endl;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"The array you have entered is: "<<endl;
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	}cout<<endl;
	cout<<"Enter the value and location of the element to be inserted: "<<endl;
	cin>>item>>loc;
	insert(item,loc,n,a);
	
	return 0;
}
