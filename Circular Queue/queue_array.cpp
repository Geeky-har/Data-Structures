// In here I will be implementing Circular Queue ADT using array...

#include<iostream>
using namespace std;

class ArrayQueue{

    private:
        int capa;
        int front, rear;
        int *array;

    public:
        ArrayQueue* CreateQueue(int);
        ArrayQueue* QueueAlloc();
        bool isEmpty(ArrayQueue*);
        bool isFull(ArrayQueue*);
        void enQueue(ArrayQueue*);
        void deQueue(ArrayQueue*);
        void dispQueue(ArrayQueue*);
};

ArrayQueue* ArrayQueue::CreateQueue(int capa){
    ArrayQueue *p = new ArrayQueue;

    if(!p)
        return nullptr;

    else
    {
        p->capa = capa;
        p->front = p->rear = -1;
        p->array = new int[capa];

        if(!p->array)
            return nullptr;
    }

    return p;
}

ArrayQueue* ArrayQueue::QueueAlloc(){
    int n;

    cout<<"Enter the size of the queue: "<<endl;
    cin>>n;

    ArrayQueue *p;
    p = CreateQueue(n);

    if(!p)
        cout<<"The queue creation failed!"<<endl;

    else
        cout<<"The queue is successfully made!"<<endl;

    return p;
}

bool ArrayQueue::isEmpty(ArrayQueue* p){
    return (p->front == -1);
}

bool ArrayQueue::isFull(ArrayQueue* p){
    return ((p->rear + 1) % p->capa == p->front);    // front = 4; rear = 0; (condition satisfied)
}

void ArrayQueue::enQueue(ArrayQueue *p){
    
    if(isFull(p))
        cout<<"The queue is already full!"<<endl;

    else
    {
        int data;

        cout<<"Enter the data that you want to insert: "<<endl;
        cin>>data;

        p->rear = (p->rear + 1) % p->capa;
        p->array[p->rear] = data;
        if(p->front == -1)
            p->front = p->rear;

        cout<<"The element "<<data<<" is inserted in the queue"<<endl;
    }

}

void ArrayQueue::deQueue(ArrayQueue *p){

    if(isEmpty(p))
        cout<<"The queue is empty cannot perform Dequeue operation!"<<endl;

    else{
        int temp;

        temp = p->array[p->front];
        if (p->front == p->rear)    // only one element case(where rear = front = 0)
            p->front = p->rear = -1;

        else
            p->front = (p->front + 1) % p->capa;

        cout<<"The element that is removed is: "<<temp<<endl;
    }
}

void ArrayQueue::dispQueue(ArrayQueue* p){
    if(p->front == -1)
        cout<<"The queue is empty!"<<endl;

    else if(p->rear >= p->front)
    {
        int i = p->front;

        for(i; i < p->capa; i++){
            cout<<p->array[i]<<" ";
        }
    }

    else{
        for(int i = p->front; i < p->capa; i++)
            cout<<p->array[i]<<" ";

        for(int i = 0; i <= p->rear; ++i)
            cout<<p->array[i]<<" ";

    }

    cout<<endl<<"Front "<<p->front<<endl;
    cout<<"Rear "<<p->rear<<endl;
}

int main(){
	int op;
	ArrayQueue *t;
	ArrayQueue queue;
	
	cout<<"Select an option from below list: "<<endl;
	do{
		cout<<"\n\n****************************Main Menu****************************"<<endl;
		cout<<"1. For Creating a queue"<<endl;
		cout<<"2. To add an element"<<endl;
		cout<<"3. To remove an element"<<endl;
		cout<<"4. For Displaying the elements in Queue"<<endl;
		cout<<"5. Exit"<<endl;
		cin>>op;
		
		switch(op){
			case 1: t = queue.QueueAlloc();
					break;
				
			case 2: queue.enQueue(t);
					break;
				
			case 3: queue.deQueue(t);
					break;
					
			case 4: queue.dispQueue(t);
					break;
		}
		
	}while(op!=5);
	
	return 0;
}
