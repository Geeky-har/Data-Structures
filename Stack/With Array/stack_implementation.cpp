// In the following program I have implemented Stack ADT using Arrays

#include <bits/stdc++.h>
using namespace std;

class ArrayStack
{ // class for array stack
	int top;
	int size;
	int *array;

public:
	ArrayStack *CreateStack();
	bool isFull(ArrayStack *);	// Declaration of all
	bool isEmpty(ArrayStack *); //		the function which
	void push(ArrayStack *);	//			are used in the program
	void pop(ArrayStack *);
	void printStack(ArrayStack *);
	void printTop(ArrayStack *);
};

ArrayStack *ArrayStack::CreateStack()
{ // function for creating a stack of defined size
	ArrayStack *stack = new ArrayStack;
	int n;
	cout << "Please Enter the size of the stack: " << endl;
	cin >> n;

	stack->top = -1;		   // Initializing top as -1(no elements)
	stack->size = n;		   // Initializing the size of stack
	stack->array = new int[n]; // creating the array dynamically

	cout << "Your Stack with size " << n << " created" << endl
		 << endl;

	return (stack); // returned the object with above specifications
}

bool ArrayStack::isFull(ArrayStack *stack)
{ // method to check if array is full?

	if (stack->top == stack->size - 1)
		return (true); // return true if full

	else
		return (false); // return false if not full
}

bool ArrayStack::isEmpty(ArrayStack *stack)
{ // method to check if array is empty?

	if (stack->top == -1)
		return (true); // returns true if empty

	return (false); // returns false if not empty
}

void ArrayStack::push(ArrayStack *stack)
{ // method for push operation
	int item;

	if (!isFull(stack))
	{ // execute if stack is not full
		cout << "Enter the element that they wanna push into the stack: " << endl;
		cin >> item; // item stores the entered element

		stack->top = stack->top + 1;	 // top value increemented
		stack->array[stack->top] = item; // item stored in the array with index top
		cout << "Item pushed successfully!!" << endl;
	}

	else
		cout << "The stack is full (overflow condition!!)" << endl;
}

void ArrayStack::pop(ArrayStack *stack)
{ // method for pop operation
	int temp;

	if (!isEmpty(stack))
	{									 // execute if stack not empty
		temp = stack->array[stack->top]; // temp will store the value of topmost element
		stack->top--;					 // value of top decreemented
		cout << "The element which is deleted is: " << temp << endl;
	}

	else
		cout << "The stack is empty (underflow)" << endl;
}

void ArrayStack::printStack(ArrayStack *stack)
{ // for printing the elements in the stack
	int i;
	if (isEmpty(stack))
	{
		cout << "The stack is empty, please perform push operation" << endl;
	}

	else
	{ // will execute if the stack is not empty
		cout << "The elements inside the stack are: ";

		for (i = 0; i <= stack->top; i++)
		{
			cout << stack->array[i] << " ";
		}
		cout << endl;
	}
}

void ArrayStack::printTop(ArrayStack* stack){
	if(isEmpty(stack))
		cout<<"Stack is empty!"<<endl;

	else{

		int data = stack->array[stack->top];

		cout<<"The element at top is: "<<data<<endl;
	}
}

int main()
{
	int option;
	ArrayStack obj;
	ArrayStack *stack; // pointer object of ArrayStack type
	cout << "Please select an option from below: " << endl
		 << endl;

	do
	{
		cout << "1. For Creating a Stack" << endl;
		cout << "2. To perform Push operation" << endl;
		cout << "3. To perform pop operation" << endl;
		cout << "4. To print the stack elements" << endl;
		cout << "5. To get the top element" << endl;
		cout << "6. Exit" << endl;

		cin >> option;

		switch (option)
		{
		case 1:
			stack = obj.CreateStack(); // pointer stores the address of new class
			break;

		case 2:
			obj.push(stack); // push operation with class pointer as args
			break;

		case 3:
			obj.pop(stack); // pop operation with class pointer as args
			break;

		case 4:
			obj.printStack(stack); // print operation with class pointer as args
			break;

		case 5:
			obj.printTop(stack); // prints the element at the top
			break;
		}

	} while (option != 6);

	return 0;
}
