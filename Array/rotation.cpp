#include<bits/stdc++.h>
#include<conio.h>
# define right =1
# define left =-1
using namespace std;
void rotate(int a[], int n, int dir, int count){
	int temp,i;
	if(dir==1){
		while(count){
			temp=a[n-1];
			for(i=n-2;i>=0;i--){
				a[i+1]=a[i];
			}
			a[0]=temp;
			count--;
		}
	}
	if(dir==-1){
		while(count){
			temp=a[0];
			for(i=1;i<n;i++){
				a[i-1]=a[i];
			}
			a[n-1]=temp;
			count--;
		}
	}
	else
		cout<<"Please enter a valid input"<<endl;
}
void display(int a[], int n){
	int i;
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
}
int main(){
	int a[20],n;
	int i,dir,count;
	cout<<"********************************************ROTATION OF ARRAY**************************************"<<endl<<endl;
	cout<<"Enter the size of the array: "<<endl;
	cin>>n;
	cout<<"Now enter the elements of the array: "<<endl;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"The array before sorting is: "<<endl;
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<"\nNow enter the direction in which array is to be shifted: "<<endl;
	cin>>dir;
	cout<<"Now enter the number of steps you want to shift: "<<endl;
	cin>>count;
	rotate(a,n,dir,count);
	display(a,n);
	return 0;
	getch();
}
