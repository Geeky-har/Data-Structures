#include<iostream>
using namespace std;

class DeNode{
    int data;
    DeNode* prev;
    DeNode* next;

    public:
        DeNode* createNode();
        void insertNode();
        void printNode();
};

DeNode* Start = nullptr;

DeNode* DeNode:: createNode(){
    DeNode* temp;
    temp = new DeNode();
    return(temp);
}

void DeNode::insertNode(){
    int item;
    DeNode* node, *traverse;

    cout<<"Enter 00 after the last element to terminate the list"<<endl;
    cout<<"Enter the values in the list"<<endl;
    cin>>item;

    while(item != 00){
        node = createNode();
        node->data = item;
        
        if(Start == nullptr){
            Start = node;
            node->prev = nullptr;
            node->next = nullptr;
        }

        else{
            traverse = Start;
            while(traverse->next != nullptr){
                traverse = traverse->next;
            }

            traverse->next = node;
            node->prev = traverse;
            
        }

        cin>>item;
    }
}

void DeNode::printNode(){
    DeNode* traverse = Start;

    if (traverse == nullptr)		//if header contains null print error
	{
		cout<<"First Enter the elements in the list to perform print operation!!"<<endl;
	}

    else
    {
        while (traverse->next != nullptr)
        {
            cout<<traverse->data<<" -> ";
            traverse = traverse->next;
        }

        if (traverse->next == nullptr)
        {
            cout<<traverse->data<<" ";
        }   
        
    }
    
}

int main(){
    int option;
    DeNode obj;

    cout<<"Select any option from the given menu!!"<<endl<<endl;

    do{
		cout<<"\n\n****************************Main Menu****************************"<<endl;
		cout<<"1. Create a List "<<endl;
		cout<<"2. Print a List "<<endl;
		cout<<"3. Exit "<<endl;
		cin>>option;

        switch(option){
			case 1 : obj.insertNode();
					 break;
			
			case 2 : obj.printNode();
					 break;
					 
		}
		
	}while(option!=3);

    return 0;
}