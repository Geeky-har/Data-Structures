// In this program we will be implementing all the major sorting algorithms

#include<iostream>
using namespace std;

int* createArray(int n){

    int* arr = new int[n];

    cout<<"Now enter "<<n<<" elements in the array: "<<endl;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    return arr;
}

void printArray(int* arr, int n){

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

void bubble(){
    int n;

    cout<<"Enter the size of the array: "<<endl;
    cin>>n;

    int* arr = createArray(n);

    // Now performing bubble sort algorithm---

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] > arr[j]){
                swap(arr[i], arr[j]);
            }
        }
    }

    //printing the array after sorting---

    cout<<"Your array after performing bubble sort is: "<<endl;

    printArray(arr, n);

}

void selection(){
    int n;

    cout<<"Enter the size of the array: "<<endl;
    cin>>n;

    int* arr = createArray(n);

    // Now performing selection sort algorithm---

    for(int i=0; i<n-1; ++i){
        int min = i;    // will mark current element as minimum
        for(int j=i+1; j<n; ++j){

            if(arr[j] < arr[min])   // if any subsequent element found smaller
                min = j;            // will update the index value of smallest
        }

        if(min != i){   // if any smaller element found
            int temp = arr[i];
            arr[i] = arr[min];      // perform swapping
            arr[min] = temp;
        }
    }

    // Now printing the array after sorting---

    cout<<"Your array after performing selection sort is: "<<endl;

    printArray(arr, n);

}

void insertion(){
    int n;

    cout<<"Enter the size of the array: "<<endl;
    cin>>n;

    int* arr = createArray(n);

    // Now perfoming insertion sort ---
    int key, j;

    for(int i=1; i<n; ++i){
        key = arr[i];
        j = i-1;

        // we will move those elements which are greater than the key to one position ahead of their original position

        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }

    // Now printing the array after performing the sorting opertion---

    cout<<"Your array after performing Insertion Sort is: "<<endl;

    printArray(arr, n);

}

void quick(){
    
}

int main(){
    int op;

    do{
        cout<<"************************************MAIN MENU************************************"<<endl<<endl;

        cout<<"Select any option from the below list: "<<endl;
        cout<<"1. For Bubble Sort"<<endl;
        cout<<"2. For Selection Sort"<<endl;
        cout<<"3. For Insertion Sort"<<endl;
        cout<<"4. For Quick Sort"<<endl;
        cout<<"5. For Merge Sort"<<endl;
        cout<<"6. For Shell Sort"<<endl;
        cout<<"7. Exit"<<endl;
        cin>>op;

        switch(op){
            case 1:
                bubble();
                break;

            case 2:
                selection();
                break;

            case 3:
                insertion();
                break;

            case 4:
                quick();
                break;
        }
    }while (op != 7);

    return 0;
    

}