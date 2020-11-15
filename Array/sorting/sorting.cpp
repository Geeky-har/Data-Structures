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

int partioning(int arr[], int lower, int upper){
    // This method will be responsible for partioning the array

    // left will move towards the end of the list and right will move towards the pivot element
    int left = lower, right = upper; 

    int pivot = arr[lower];    // will set the first element as pivot

    while(left < right){    // will repeat the following while left is less than right

        // we will increement left if the elements are less than pivot(since we need to find element greater than pivot inorder to swap left with right)

        while(arr[left] <= pivot) 
            left++;

        // we will increement left if the elements are less than pivot(since we need to find element greater than pivot inorder to swap left with right)

        while(arr[right] > pivot)
            right--;

        // if left and right hasn't crossed each other yet!, then swap elements of left and right

        if(left < right)
            swap(arr[left], arr[right]);

    }

    // After left and right are at same position or crossed each other, we will move the pivot element with index in which right is at and the element at right will go to the position of pivot.

    arr[lower] = arr[right];
    arr[right] = pivot;

    // Since this method returns the partioning position(where pivot element is present) we will return right, because thats where pivot element is present.
    return right;
}

void quickSort(int arr[], int lower, int upper){
    // This function will take the array and the lower and upper bound of the array

    int pi; // This is the memory allocated for partioning index

    if(lower < upper){  // will execute the following code only when lower is less than upper

        pi = partioning(arr, lower, upper);    // will partion the array
        quickSort(arr, lower, pi-1);          // performing quickSort on first partition(pi sorted)
        quickSort(arr, pi+1, upper);         // performing quickSort on second partition(pi sorted)
    }
}

void quick(){
    int n;

    cout<<"Enter the size of the array: "<<endl;
    cin>>n;

    int* arr = createArray(n);

    // Now perfoming Quick sort ---

    quickSort(arr, 0, n-1);

    // Now printing the array after performing the sorting opertion---

    cout<<"Your array after performing Quick Sort is: "<<endl;

    printArray(arr, n);

}

void merge(int arr[], int lower, int mid, int upper){
    int i, j, k;
    i = lower;  // i will start from the first index of partition 1
    j = mid + 1;    // j will start from the first index of partition 2
    k = lower;  // k will start from the first index of the auxiliary array

    int* aux = new int[upper+1];    // auxiliary array where we will store the sorted elements

    // will iterate until either of the two partition ran out of elements

    while(i <= mid && j <= upper){

        if(arr[i] < arr[j]){    // if element of first partition is smaller
            aux[k] = arr[i];    // store that element in the auxiliary array
            i++;                // increement the pointer of array of first partition
        }

        else{   // if element of second partition is smaller
            aux[k] = arr[j];    // store that element in the auxiliary array
            j++;    // increement the pointer of array of second partition
        }

        k++;    // after storing the element will increase the pointer of the auxiliary
    }

    // if elements in the first partition are left will store rest of the elements in the auxiliary array

    while(i <= mid){
        aux[k] = arr[i];
        k++;
        i++;
    }

    // if elements in the second partition are left will store rest of the elements in the auxiliary array

    while(j <= upper){
        aux[k] = arr[j];
        j++;
        k++;
    }

    // Now our auxiliary array have the sorted elements, now we will copy elements of aux array to original array

    for (int i = lower; i <= upper; i++)
    {
        arr[i] = aux[i];
    }
    
}

void mergeSort(int arr[], int lower, int upper){

    // Will execute the code if lower is less than upper(means atleast two elements)

    if(lower < upper){
        int mid = (lower + upper) / 2;  // will determine mid of the array
        mergeSort(arr, lower, mid);     // partition the array from lower to mid (1st partition)
        mergeSort(arr, mid+1, upper);   // partition the array from mid+1 to upper (2nd partition)
        merge(arr, lower, mid, upper);  // perform merging of the partitions made above
    }
}

void ms(){
    int n;

    cout<<"Enter the size of the array: "<<endl;
    cin>>n;

    int* arr = createArray(n);

    // Now perfoming Merge sort ---

    mergeSort(arr, 0, n-1);

    // Now printing the array after performing the sorting opertion---

    cout<<"Your array after performing Merge Sort is: "<<endl;

    printArray(arr, n);
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

            case 5:
                ms();
                break;
        }

    }while (op != 7);

    return 0;

}