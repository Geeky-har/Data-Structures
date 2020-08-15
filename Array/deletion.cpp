#include<bits/stdc++.h>
using namespace std;

void deletion(int loc, int n, int a[])
{
	int i=0, ptr = loc-1;
	for(ptr=(loc-1); ptr<n; ptr++){
		a[ptr]=a[ptr+1];
	}
	n=n-1;
	cout<<"The resultant array is: "<<endl;
	while(i<n){
		cout<<a[i]<<" "<<endl;
		i++;
	}	
}

int main(){
	int n,a[100],i,loc;
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
	cout<<"Enter the location to be deleted: "<<endl;
	cin>>loc;
	deletion(loc,n,a);
	
	return 0;
}
