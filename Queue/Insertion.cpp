#include<bits/stdc++.h>
using namespace std;

struct ArrayQueue
{
	int rear, front, capacity;
	int *array;
};

struct ArrayQueue* CreateQueue(int capa){
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

struct ArrayQueue* enQueue(){
	int n, data;
	cout<<"Please Enter the size of the queue: "<<endl;
	cin>>n;
	struct ArrayQueue* Q;	
	Q = CreateQueue(n);
	
	cout<<"Now enter the dataset you want to insert (press -1 after the last element)"<<endl;
	cin>>data;
	
	do{
		
		if(Q->rear == n-1)
			cout<<"The queue is full cant perform Insertion Operation"<<endl;
		
		else if(Q->front < 0){
			Q->front = 0;
			Q->rear = 0;
			Q->array[Q->rear] = data;
		}
	
		else{
			Q->rear = Q->rear + 1;
			Q->array[Q->rear] = data;
		}
		
		cout<<"Now enter the dataset you want to insert (press -1 after the last element)"<<endl;
		cin>>data;
		
	}while(data!=-1);
		
	return(Q);
}

void DispQueue(struct ArrayQueue *ptr){
	if(ptr->rear == -1)
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

void deQueue(struct ArrayQueue* ptr){
	int temp;
	if(ptr->front == -1)
		cout<<"Queue is empty cannot perform dequeue operation";
		
	else{
		temp = ptr->array[ptr->front];
		ptr->front++;
		cout<<"The element which is removed is: "<<temp<<endl;
	}
}

void addQueue(struct ArrayQueue* Q){
	int item;
	cout<<"Please Enter The item that you want to add"<<endl;
	cin>>item;
	
//	if(Q->rear == n-1)
//		cout<<"The queue is full cant perform Insertion Operation"<<endl;
		
	if(Q->front < 0){
		Q->front = 0;
		Q->rear = 0;
		Q->array[Q->rear] = item;
	}
	
	else{
		Q->rear = Q->rear + 1;
		Q->array[Q->rear] = item;
	}
}


int main(){
	int op;
	struct ArrayQueue *t;
	
	cout<<"Select an option from below list: "<<endl;
	do{
		cout<<"\n\n****************************Main Menu****************************"<<endl;
		cout<<"1. For Creating a queue"<<endl;
		cout<<"2. For Displaying the elements in Queue"<<endl;
		cout<<"3. To remove an element"<<endl;
		cout<<"4. To add an element"<<endl;
		cout<<"5. Exit"<<endl;
		cin>>op;
		
		switch(op){
			case 1: t = enQueue();
					break;
				
			case 2: DispQueue(t);
					break;
				
			case 3: deQueue(t);
					break;
					
			case 4: addQueue(t);
					break;
				
		}
		
	}while(op!=5);
	
	return 0;

}
