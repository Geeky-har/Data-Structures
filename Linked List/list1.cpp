#include<iostream>
using namespace std;

class node{			//node datatype consists of int and a pointer of another node.
	int data;
	node* address;
	
	public:
		node* createNode();
		void insertNode();
		void printList();			//  declaration
		void deleteNode();			//		of all
		void sortList();			//			the functions
		void addElement();			//             used in the program
		void addElementBeg();	
		void searchEle();
		void revList();
		void delList();
		void nRev();
		int noNode(node*);
};

node *start=NULL;     //global variable

node* node:: createNode(){		//function returns a pointer of node type
	node *temp;
	temp = new node();	//will assign a new memory and store its address in temp pointer
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
	
	else
	{
		while(traverse->address!=NULL){		//start a loop till node address is not null
		cout<<traverse->data<<" -> ";
		traverse=traverse->address;
		}
		if(traverse->address==NULL)			//corner case handled
			cout<<traverse->data<<" ";
	}
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

	int temp;
	
	node *t = start;		//pointer to the first node
	node *t1;				//pointer to keep record of the node next to the current node

	if (t == NULL)
	{
		cout<<"Please create a list first (press 1)"<<endl;
	}

	else{
		cout<<"Your list is sorted(bubble sort used)"<<endl;

		while(t->address != NULL){	//t will traverse till the last node(init with header node)
			t1 = t->address;		//t1 takes the address of the next node
			while(t1->address != NULL){		//t1 will traverse the whole list
				if(t->data > t1->data){		//previous data found larger than the subsequet data
					// temp;
					temp = t1->data;				// swapping
					t1->data = t->data;					// performed
					t->data = temp;								// here 
				}

				t1 = t1->address;		//t1 will go one node further
			
			}

			if(t1->address == NULL && t->data > t1->data){	//corner case for the last node handled
					temp = t1->data;
					t1->data = t->data;
					t->data = temp;
				}
			
			t = t->address;				//t will go one node further
		}
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
			new_node->data = item;
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

void node:: addElementBeg(){
	int data;
	node* newNode, *temp;
	cout<<"Enter the data you want to add in the first node: "<<endl;
	cin>>data;

	newNode = createNode();
	newNode->data = data;

	if(start == NULL){
		start = newNode;
		newNode->address = NULL;
	}

	else{
		temp = start;
		start = newNode;
		newNode->address = temp;
	}

	cout<<endl<<"Your node successfuly inserted in the beginning"<<endl;
}

void node:: searchEle(){
	int key_element, count = 0;
	node* t = start;

	if(t == NULL)
		cout<<"List Not found please create a list first!!!";

	else{
		cout<<"Enter the element you want to search: "<<endl;
		cin>>key_element;

		while(t != NULL){
			count++;

			if(t->data == key_element){
				cout<<"Element is found at position"<<count;
				break;
			}

			t = t->address;
		}

		if (t == NULL)
			cout<<"The key you entered is not present in the list"<<endl;
	}
}

void node:: revList(){
	node *t1, *t2, *trav;
	t1 = t2 = NULL;

	if (start == NULL)
	{
		cout<<"Enter some elements in the list first!!"<<endl;
	}
	
	else{
		while (start != NULL){

			t2 = start->address;
			start->address = t1;
			t1 = start;
			start = t2;
		}

		start = t1;

		cout<<"Your linked list has been reversed successfully!!"<<endl;

	}
	
}

void node:: delList(){
	node *current, *t1;

	current = start;
	
	if(current == NULL)		cout<<"No LIst exists"<<endl;

	else
	{
		while (current != NULL)
		{
			t1 = current->address;
			free(current);
			current = t1;
		}

		start = NULL;

		cout<<"Your List is Successfully deleted"<<endl;
		
	}
}

int node::noNode(node* t){		// method to calc the no of nodes present after a specific node
	int count = 0;

	while(t->address != NULL){
		t = t->address;
		count++;
	}

	return count;
}

void node:: nRev(){		// algorithm by brute force technique
	int n;
	node* t = start;

	if(t == NULL)
		cout<<"The list is empty!"<<endl;

	else{
		cout<<"Enter the value of n: "<<endl;
		cin>>n;

		while(noNode(t) != n-1){
			if(noNode(t) < n-1){
				cout<<"Few nodes in list"<<endl;
				break;
			}

			else
				t = t->address;
		}

		cout<<"Value of that node is: "<<t->data<<endl;
		
	}

}

int main(){
	int option;
	node ob1;
	
	cout<<"Select any option from the given menu!!"<<endl;
	
	do{
		cout<<"\n****************************Main Menu****************************"<<endl<<endl;
		cout<<"1. Create a List "<<endl;
		cout<<"2. Print a List "<<endl;
		cout<<"3. Delete a Node"<<endl;
		cout<<"4. To Perform sorting"<<endl;
		cout<<"5. To add a node after an existing node"<<endl;
		cout<<"6. To add an item right after the header(i.e in the beginning)"<<endl;
		cout<<"7. To Perform Searching Operation"<<endl;
		cout<<"8. To Reverse the List"<<endl;
		cout<<"9. Delete the whole List"<<endl;
		cout<<"10. To find nth node from the last"<<endl;
		cout<<"11. Exit "<<endl;
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

			case 6 : ob1.addElementBeg();
					 break;

			case 7 : ob1.searchEle();
					 break;

			case 8 : ob1.revList();
					 break;

			case 9 : ob1.delList();
					 break;

			case 10 : ob1.nRev();
					  break;
		}
		
	}while(option!=11);
	
	return 0;
}