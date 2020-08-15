#include<bits/stdc++.h>
using namespace std;

struct ArrayStack{
	int top;
	int size;
	int *array;
};


struct ArrayStack* CreateStack(){
	struct ArrayStack *stack = new struct ArrayStack;
	int n;
	cout<<"Please Enter the size of the stack: "<<endl;
	cin>>n;
	
	stack->top = -1;
	stack->size = n;
	stack->array = new int[n];
	
	cout<<"Your Stack with size "<<n<<" created"<<endl<<endl;
	
	return(stack);
}

int isFull(struct ArrayStack *stack){
	
	if(stack->top == stack->size-1)
		return(1);
		
	else
		return(0);
}

int isEmpty(struct ArrayStack *stack){
	
	if(stack->top == -1)
		return(1);
		
	return(0);
}

void push(struct ArrayStack *stack){
	int item;
	
	if(!isFull(stack)){
		cout<<"Enter the element that they wanna push into the stack: "<<endl;
		cin>>item;
		
		stack->top = stack->top + 1;
		stack->array[stack->top] = item;
		cout<<"Item pushed successfully!!"<<endl;
	}
	
	else
		cout<<"The stack is full (overflow condition!!)"<<endl;
}

void pop(struct ArrayStack *stack){
	int temp;
	
	if(!isEmpty(stack)){
		temp = stack->array[stack->top];
		stack->top--;
		cout<<"The element which is deleted is: "<<temp<<endl;
	}
	
	else
		cout<<"The stack is empty (underflow)"<<endl;
	
}

void printStack(struct ArrayStack *stack){
	int i;
	if(isEmpty(stack)){
		cout<<"The stack is empty, please perform push operation"<<endl;
	}
	
	else{
		cout<<"The elements inside the stack are: ";
		
		for(i=0; i<=stack->top; i++){
			cout<<stack->array[i]<<" ";
		}cout<<endl;
	}
}


int main(){
	int option;
	struct ArrayStack *stack;
	cout<<"Please select an option from below: "<<endl<<endl;
	
	do{
		cout<<"1. For Creating a Stack"<<endl;
		cout<<"2. To perform Push operation"<<endl;
		cout<<"3. To perform pop operation"<<endl;
		cout<<"4. To print the stack elements"<<endl;
		cout<<"5. Exit"<<endl;
		
		cin>>option;
		
		switch(option){
			case 1: stack = CreateStack();
					break;
						
			case 2: push(stack);
					break;
						
			case 3: pop(stack);
					break;
						
			case 4: printStack(stack);
					break;
		}
			
	}while(option != 5);
	
	return 0;
}
