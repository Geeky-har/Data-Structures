/*

circular linked lists do not have ends. While traversing the circular linked lists we should be
careful; otherwise we will be traversing the list infinitely. In circular linked lists, each node has a
successor. Note that unlike singly linked lists, there is no node with NULL pointer in a circularly
linked list.

*/

#include <iostream>
using namespace std;

class CLLNode{
    int data;
    CLLNode* next;

public:
    CLLNode* createNode();
    void insertNode();
    void printList();
    void insertBeg();
};

CLLNode* start = nullptr;

CLLNode* CLLNode:: createNode(){
    CLLNode* temp;
    temp = new CLLNode();
    return temp;
}

void CLLNode:: insertNode(){
    int data;
    CLLNode* t;
    CLLNode* current = start;

    t = createNode();

    cout<<"Enter the value of data: "<<endl;
    cin>>data;
    t->data = data;
    t->next = start;

    if(start == nullptr)
    {
        start = t;
        t->next = start;
    }

    else
    {
        while (current->next != start)
        {
            current = current->next;
        }

        current->next = t;
    }

    cout<<"Item successfully added in the list!!"<<endl;

}

void CLLNode::printList(){
    CLLNode *t = start;

    cout<<"Your List is: "<<endl;

    while(t->next != start){
        cout<<t->data<<" -> ";
        t = t->next;
    }

    if(t->next == start)
        cout<<t->data;

}

void CLLNode::insertBeg(){
    int data;
    CLLNode* t = start;
    CLLNode* newNode = createNode();

    cout<<"Enter the element that you want to insert: "<<endl;
    cin>>data;
    newNode->data = data;
    // newNode->next = start;

    if(t == nullptr)
    {
        start = newNode;
    }

    else
    {
        CLLNode* temp = start;
        newNode->next = temp;
        start = newNode;

        while (t->next != temp)
        {
            t = t->next;
        }

        t->next = newNode;
        
    }

    cout<<"New Node successfully added in the beginning"<<endl;

}

int main(){
    int option;
    CLLNode obj;

	cout << "Select any option from the given menu!!" << endl;

    do{

		cout << "\n****************************Main Menu****************************" << endl;
        cout<<"1. To insert element in the list"<<endl;
        cout<<"2. To print the list"<<endl;
        cout<<"3. To insert an element at the beg"<<endl;
        cout<<"4. Exit"<<endl;
        cin>>option;

        switch(option)
        {
            case 1: obj.insertNode();
                    break;

            case 2: obj.printList();
                    break;

            case 3: obj.insertBeg();
                    break;
        }

    }while(option != 4);

    return 0;

}