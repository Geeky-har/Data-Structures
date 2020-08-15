#include<iostream>
#include<conio.h>
using namespace std;
void select(int a[], int n){
	int x,y,min,temp;
	for(x=0;x<n-1;x++){
		min=x;
		for(y=x+1;y<n;y++){
			if(a[y]<a[min]){
				min=y;
			}
		}
		if(min!=x){
			temp=a[x];
			a[x]=a[min];
			a[min]=temp;
		}
	}
	cout<<"\nThe elements after sorting are: "<<endl;
	for(x=0;x<n;x++)
		cout<<a[x]<<" ";
}

int main(){
	int a[20],i,n;
	cout<<"*****************************************SELECTION SORT****************************************"<<endl;
	cout<<"Enter the size of the array: "<<endl;
	cin>>n;
	cout<<"Input the elements into the array: "<<endl;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"The elements you have entered are: "<<endl;
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	}cout<<endl;
	cout<<"\nPress any key to continue";
	getch();
	select(a,n);
	return 0;
}
