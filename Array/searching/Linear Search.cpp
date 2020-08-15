#include<iostream>
using namespace std;

int i;

int l_search(int arr[], int n, int key){
	for(i=0; i<n; i++){
		if(arr[i] == key){
			return i;
		}
	}
	
	return -1;
}

int main(){
	int n,key,index;
	cout<<"Enter the size of the array: "<<endl;
	cin>>n;
	int *arr = new int[n];
	cout<<"Enter the elements into the array: ";
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	
	cout<<"Enter the element you want to find: "<<endl;
	cin>>key;
	
	index = l_search(arr, n, key);
	if(index == -1){
		cout<<"The element you searched for is not found"<<endl;
	}
	
	else{
		cout<<"The element you searched for is found at "<<index<<endl;
	}
	
	return 0;
}
