#include<bits/stdc++.h>
using namespace std;

class ArrayQueue
{
	private:
		int rear, front, capacity;
		int *array;

	public:
		ArrayQueue* CreateQueue(int);
		ArrayQueue* enQueue();
		void DispQueue(ArrayQueue*);
		void deQueue(ArrayQueue*);
		void addQueue(ArrayQueue*);
};

 ArrayQueue* ArrayQueue:: CreateQueue(int capa){
	struct ArrayQueue *p = new struct ArrayQueue;
	if(!p)
		return(NULL);
		
	p->capacity = capa;
	p->front = p->rear = -1;
	p->array = new int[capa];
	
	if(!p->array)
		return(NULL);
		
	return(p);	
}

ArrayQueue* ArrayQueue:: enQueue(){
	int n, data;
	cout<<"Please Enter the size of the queue: "<<endl;
	cin>>n;
	struct ArrayQueue* Q;
	Q = CreateQueue(n);

	cout<<"The queue of size "<<n<<" is created successfully"<<endl;
	
	return(Q);
}

void ArrayQueue:: DispQueue(ArrayQueue *ptr){
	if(ptr->rear == -1)
		cout<<"The Queue is empty"<<endl;

	else if(ptr->front > ptr->rear)
		cout<<"The Queue is empty"<<endl;
		
	else{
		int it = ptr->front;
		cout<<"The elements inside the Queue are: "<<endl;
		while(it != ptr->rear){
			cout<<ptr->array[it]<<" ";
			it++;
		}
		
		if(it == ptr->rear)
			cout<<ptr->array[it]<<" ";
			cout<<endl;
		
	}
	cout<<"Front "<<ptr->front<<endl;
	cout<<"Rear "<<ptr->rear<<endl;
	
}

void ArrayQueue:: deQueue(struct ArrayQueue* ptr){
	int temp;
	if(ptr->front == -1)
		cout<<"Queue is empty cannot perform dequeue operation";
		
	else{
		temp = ptr->array[ptr->front];
		ptr->front++;
		cout<<"The element which is removed is: "<<temp<<endl;
	}
}

void ArrayQueue:: addQueue(ArrayQueue* Q){
	int item;
	
	if(Q->rear == Q->capacity - 1)
		cout<<"The queue is full cant perform Insertion Operation"<<endl;
		
	else if(Q->front < 0){
		cout<<"Please Enter The item that you want to add"<<endl;
		cin>>item;
		Q->front = 0;
		Q->rear = 0;
		Q->array[Q->rear] = item;

		cout<<"Item added successfully in the queue!!"<<endl;

	}
	
	else{
		cout<<"Please Enter The item that you want to add"<<endl;
		cin>>item;
		Q->rear = Q->rear + 1;
		Q->array[Q->rear] = item;

		cout<<"Item added successfully in the queue!!"<<endl;

	}

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
			case 1: t = queue.enQueue();
					break;
				
			case 4: queue.DispQueue(t);
					break;
				
			case 3: queue.deQueue(t);
					break;
					
			case 2: queue.addQueue(t);
					break;
		}
		
	}while(op!=5);
	
	return 0;
}
