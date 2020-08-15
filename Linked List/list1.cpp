#include<iostream>
using namespace std;

class node{			//node datatype consists of int and a pointer of another node.
	int data;
	node* address;
	
	public:
		node* createNode();
		void insertNode();
		void printList();
		void deleteNode();
		void sortList();
		void addElement();	
};

node *start=NULL;     //global variable

node* node:: createNode(){		//function returns a pointer of node type
	node *temp;
	temp=new node();	//will assign a new memory and store its address in temp pointer
	return temp;
}

void node:: insertNode(){
	node *temp, *traverse;
	int n;
	cout<<"Enter -1 to end"<<endl;
	cout<<"Enter the value to be added in the list"<<endl;
	cin>>n;
	while(n!=-1){	//will iterate through this loop until user enters -1
		temp=createNode();		//temp will store the address of new node.
		temp->data=n;			
		temp->address=NULL;		
		
		if(start==NULL){
			start=temp;			//if list is empty then the header will contain the address of first node
		}
		else{					//if list not empty
			traverse=start;			//traverse contains the address of first node
			while(traverse->address!=NULL){		//will iterate while we reach last node
				traverse=traverse->address;		//traverse store the address of next node.
			}
			traverse->address=temp;				//when we will reach last node we will assign address of newly created node to is address part
		}
		cout<<"Enter the elements to be entered in the list"<<endl;
		cin>>n;			//will ask again for input
	}
}

void node:: printList(){
	node *traverse=start;		//traverse will store address of first node

	if (traverse == NULL)		//if header contains null print error
	{
		cout<<"First Enter the elements in the list to perform print operation!!"<<endl;
	}
	
	
	while(traverse->address!=NULL){		//start a loop till node address is not null
		cout<<traverse->data<<" -> ";
		traverse=traverse->address;
	}
	if(traverse->address==NULL)			//corner case handled
		cout<<traverse->data<<" ";
}

void node:: deleteNode(){
	int key;
	node *ptr, *ptr1;
	cout<<"Enter the element you want to delete: "<<endl;
	cin>>key;		//wil input the key from the user

	ptr = start;		//init the ptr with address of teh header node
	ptr1 = NULL;		//init the next ptr with null
	if(ptr == NULL)
		cout<<"Your list is empty, do some insertion first!!"<<endl;

	else if(ptr->data == key){		//if key found at the very first node
		start = ptr->address;		//set header node with the address of the key node
	}
		
	else{
		
		while(ptr->address != NULL && ptr->data != key){	//iterate till the condition specified
			ptr1 = ptr;
			ptr = ptr->address;
		}
		
		if(ptr->data != key)
			cout<<"The element is not present here!!"<<endl;
			
		else if(ptr->address == NULL && ptr->data == key){		// key found at the last node
			ptr1->address = NULL;							// set previous node to null
			delete(ptr);	
		}
			
		else{
			ptr1->address = ptr->address;		// setting address contained by the prev node
			delete(ptr);						// to address holded by key node
		}
	}
	
	cout<<"Your List after the deletion Operation is: "<<endl;
	printList();
}

void node:: sortList(){
	
	cout<<"Your list is sorted(bubble sort used)"<<endl;
	
	node *t = start;
	node *t1;
	while(t->address != NULL){
		t1 = t->address;
		while(t1->address != NULL){
			if(t->data > t1->data){
				int temp;
				temp = t1->data;
				t1->data = t->data;
				t->data = temp;
			}
				
			t1 = t1->address;
		}
		
		if(t1->address == NULL){
			int temp = t1->data;
			t1->data = t->data;
			t->data = temp;
		}
		
		t = t->address;
	}
	
}

void node:: addElement(){
	int item, key;
	cout<<"Enter the element after which you wat to add an element"<<endl;
	cin>>key;

	cout<<"Now enter the value of the new element: "<<endl;
	cin>>item;

	node *new_node = createNode();

	node *t = start;

	if(t == NULL){
		cout<<"Linked List not found.. Please create one by pressing 1."<<endl;
	}

	else{
		
		while (t->address != NULL && t->data != key)
		{
			t = t->address;
		}

		if(t->address == NULL && t->data != key)
			cout<<"The key you entered is not present in the list! Please enter some valid input "<<endl;
		
		else if (t->address == NULL && t->data == key)
		{
			t->address = new_node;
			new_node->data = key;
			new_node->address = NULL;

			cout<<"New node is successfully added!!"<<endl;
		}

		else
		{
			node* temp = t->address;
			t->address = new_node;
			new_node->data = item;
			new_node->address = temp;

			cout<<"New node is successfully created"<<endl;
		}	
	}
}

int main(){
	int option;
	node ob1;
	
	cout<<"Select any option from the given menu!!"<<endl<<endl;
	
	do{
		cout<<"\n\n****************************Main Menu****************************"<<endl;
		cout<<"1. Create a List "<<endl;
		cout<<"2. Print a List "<<endl;
		cout<<"3. Delete a Node"<<endl;
		cout<<"4. To Perform sorting"<<endl;
		cout<<"5. To add an item after an existing node"<<endl;
		cout<<"6. Exit "<<endl;
		cin>>option;
		
		switch(option){
			case 1 : ob1.insertNode();
					 break;
			
			case 2 : ob1.printList();
					 break;
					 
			case 3 : ob1.deleteNode();
					 break;
					 
			case 4 : ob1.sortList();
					 break;

			case 5 : ob1.addElement();
					 break;
					 
		}
		
	}while(option!=6);
	
	return 0;
}