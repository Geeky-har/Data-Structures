#include<iostream>
#include<conio.h>
using namespace std;
void bubble(int a[],int n){
	int i,j,temp;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(a[j]<a[i]){
				temp=a[j];
				a[j]=a[i];
				a[i]=temp;
			}
		}
	}
	cout<<"The array after sorting is: "<<endl;
	for(int k=0;k<n;k++)
		cout<<a[k]<<" ";
}
int main()
{
	int a[20],n,i;
	cout<<"**********************************************************BUBBLE SORT***************************************************"<<endl;
	cout<<"Enter size of array: ";
	cin>>n;
	cout<<"Enter the elements into the array: "<<endl;
	for(i=0;i<n;i++)
		cin>>a[i];
	cout<<"\nThe entered array is: "<<endl;
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	bubble(a,n);
	return 0;
}
