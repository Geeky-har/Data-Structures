// Max heap

#include<bits/stdc++.h>
using namespace std;

class Heap{
    private:
        int *array;     // array having the elements of heap
        int size;       // current size of heap
        int capacity;   // total capacity of heap

    public:
        Heap* createHeap();
        int parentNode(Heap*, int);
        int leftChild(Heap*, int);
        int rightChild(Heap*, int);
        int maxElement(Heap*);
        void percolateDown(Heap*, int);       // traversing from the fault node to leaf node
        void resizeHeap(Heap*);
        void buildHeap(Heap*, int[], int);
        void showHeap(Heap*);
};

Heap* Heap::createHeap(){   // Method for heap creation( TC: O(n) )
    Heap *h = new Heap();
    int capa;

    cout<<"Enter the the total capacity of the heap"<<endl;
    cin>>capa;

    h->size = 0;
    h->capacity = capa;
    h->array = new int[capa];
    if(h->array == nullptr){
        cout<<"Memory Error!"<<endl;
        return nullptr;
    }

    return h;
}

int Heap::parentNode(Heap* h, int i){
    if(h == nullptr)
        cout<<"Heap not found!"<<endl;
        return -1;

    if(i <= 0 || i >= h->size)      // if node is at 0 or below or more than total size    
        return -1;

    return (i-1)/2;     // this gives the index of the parent node
}

int Heap::leftChild(Heap* h, int i){        // method to get the left child index(TC: O(n))
    if(h == nullptr){
        cout<<"Heap Not Found!"<<endl;
        return -1;
    }

    int left = (2*i)+1;

    if(left >= h->size)     // if leaf node
        return -1;

    return left;
}

int Heap::rightChild(Heap* h, int i){       // method to get the right child index(TC: O(n))
    if(h == nullptr){
        cout<<"Heap Not Found!"<<endl;
        return -1;
    }

    int right = (2*i)+2;

    if(right >= h->size)     // if leaf node
        return -1;

    return right;
}

int Heap::maxElement(Heap* h){
    if(h == nullptr){
        cout<<"Heap Not Found!"<<endl;
        return -1;
    }

    return h->array[0];     // First element is the root and hence the largest
}

void Heap::percolateDown(Heap* h, int i){       // method to heapify a node and all its descendants(from top to bottom) (TC: O(logn), worst case: from root to leaf, which is equal to height of complete BT)
    int left, right, max = i;

    left = leftChild(h, i);     // will find the left child node index
    right = rightChild(h, i);   // will find the right child node index

    if(left != -1 && h->array[left] > h->array[max])
        max = left;

    if(right != -1 && h->array[right] > h->array[max])
        max = right;

    if(max != i){
        swap(h->array[i], h->array[max]);
        percolateDown(h, max);
    }

}

void Heap::resizeHeap(Heap* h){
    if(h == nullptr){
        cout<<"Heap not created!!"<<endl;
        return;
    }

    int* old_arr = h->array;
    h->array = new int[h->capacity * 2];
    if(h->array == nullptr){
        cout<<"Memory Error!!"<<endl;
        return;
    }

    for(int i=0; i < h->capacity; ++i){
        h->array[i] = old_arr[i];
    }

    h->capacity *= 2;
    delete(old_arr);
}

void Heap::buildHeap(Heap* h, int a[], int n){
    if(h == nullptr)
        return;

    while(n>h->capacity)
        resizeHeap(h);

    for(int i=0; i<n; i++)
        h->array[i] = a[i];

    h->size = n;
    int startInd = (h->size / 2) - 1;

    for(int i=startInd; i>=0; i--)
        percolateDown(h,i);
}

void Heap::showHeap(Heap* h){
    if(h == nullptr){
        cout<<"No heap found"<<endl;
        return;
    }

    cout<<"Elements in the heap are: "<<endl;

    for(int i=0; i<h->size; i++)
        cout<<h->array[i]<<" ";

    cout<<endl;

}

int main(){
    int op;
    Heap h;
    Heap* heap = nullptr;

    do{
        cout<<"****************MAIN MENU************************"<<endl<<endl;
        cout<<"Select an option from below:"<<endl;
        cout<<"1. To create a heap"<<endl;
        cout<<"2. To build a heap"<<endl;
        cout<<"3. To display the heap"<<endl;
        cout<<"4. Exit"<<endl;
        cin>>op;

        switch(op){
            case 1:{
                heap = h.createHeap();
                break;
            }

            case 2:{
                int n;

                cout<<"Enter the size: "<<endl;
                cin>>n;

                int *arr = new int[n];

                cout<<"Enter "<<n<<" elements: "<<endl;

                for(int i=0; i<n; i++){
                    cin>>arr[i];
                }

                h.buildHeap(heap, arr, n);
                break;
            }

            case 3:{
                h.showHeap(heap);
                break;
            }

        }
    }while(op != 4);

    return 0;

}