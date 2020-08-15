#include<iostream>
using namespace std;
int b_search(int a[], int key, int n){
		int l=1,h=n,mid=0;		//initializing lower,higher and mid in array
		while(l<h){				//will check following while l<h
		mid = (l+h)/2;			//will find the mid of array
		if(key == a[mid])		//check if key present at a[mid]
			return mid;
		
		if(key < a[mid]){		//if value of key is less than a[mid[	
			h = mid-1;			//will update value of h to mid-1
		}
	
		if(key > a[mid]){		//if key is greater than a[mid]
			l = mid+1;			//will update l to mid+1
		}
	}
	return -1;				//will return -1 if not found
}

int main(){
	int n,i,key, index;
	cout<<"Kripya array ka size bataye: "<<endl;
	cin>>n;
	int *arr = new int[n];
	cout<<"Aap "<<n<<" number of elements dalen apki bdi kripa hogi"<<endl;
	for(i=0; i<n; i++){
		cin>>arr[i];
	}
	
	cout<<"Jis element ki aapko talash hai use likhe: "<<endl;
	cin>>key;
	index = b_search(arr, key, n);
	if(index == -1){
		cout<<"Apka Element nhi mila sir"<<endl;
	}
	else{
		cout<<"Apka Element "<<index+1<<" is index par prapt hua hai"<<endl;
	}
	
	return 0;
}
