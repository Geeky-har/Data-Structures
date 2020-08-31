#include<bits/stdc++.h>
using namespace std;

class ArrayStack{
	int top;
	int size;
	int *array;

	public:
		ArrayStack* CreateStack();
		int isFull(ArrayStack*);
		int isEmpty(ArrayStack*);
		void push(ArrayStack*);
		void pop(ArrayStack*);
		void printStack(ArrayStack*);

};


ArrayStack* ArrayStack:: CreateStack(){
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

int ArrayStack:: isFull(ArrayStack *stack){
	
	if(stack->top == stack->size-1)
		return(1);
		
	else
		return(0);
}

int ArrayStack:: isEmpty(ArrayStack *stack){
	
	if(stack->top == -1)
		return(1);
		
	return(0);
}

void ArrayStack:: push(ArrayStack *stack){
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

void ArrayStack:: pop(ArrayStack *stack){
	int temp;
	
	if(!isEmpty(stack)){
		temp = stack->array[stack->top];
		stack->top--;
		cout<<"The element which is deleted is: "<<temp<<endl;
	}
	
	else
		cout<<"The stack is empty (underflow)"<<endl;
	
}

void  ArrayStack:: printStack(ArrayStack *stack){
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
	ArrayStack obj;
	ArrayStack *stack;
	cout<<"Please select an option from below: "<<endl<<endl;
	
	do{
		cout<<"1. For Creating a Stack"<<endl;
		cout<<"2. To perform Push operation"<<endl;
		cout<<"3. To perform pop operation"<<endl;
		cout<<"4. To print the stack elements"<<endl;
		cout<<"5. Exit"<<endl;
		
		cin>>option;
		
		switch(option){
			case 1: stack = obj.CreateStack();
					break;
						
			case 2: obj.push(stack);
					break;
						
			case 3: obj.pop(stack);
					break;
						
			case 4: obj.printStack(stack);
					break;
		}
			
	}while(option != 5);
	
	return 0;
}
