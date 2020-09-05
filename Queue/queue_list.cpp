// In this program we will be implementing Queue ADT with the help of linked list!!

#include<iostream>
using namespace std;

class ListQueue{    // class for the each node in the queue
    int data;
    ListQueue* next;

    public:
        ListQueue* getNode();       // methods for operation
        void enQueue();
        void deQueue();         // in the queue
        void dispQueue();
        bool isEmpty();
        void numEleQueue();
};

ListQueue* rear = nullptr;      // rear pointing at the last node
ListQueue* front = nullptr;     // front pointing at the first node


ListQueue* ListQueue::getNode(){    // method to get a new node
    ListQueue *t;
    t = new ListQueue();
    return(t);                      // will return a pointer pointing to the newly created node
}

void ListQueue::enQueue(){          // method for enqueue operation
    ListQueue *node = getNode();        // node gets the reference of the newly created node
    int data;

    if(!node)           // node creation failed
        cout<<"Cant add elements.. Some problem occurred!"<<endl;

    else{ 
        cout<<"Enter the element that you want to add: "<<endl;
        cin>>data;      // user input data

        node->data = data;      // data stored in the node

        if(isEmpty()){       // if front is null(empty list)
            front = rear = node;    // both front and rear points at first node
            node->next = nullptr;   // set next as null
        }

        else if(front == rear){     // when there is only one node in the list
            rear = node;            // rear holds the reference of the newly created node
            node->next = nullptr;   // node next set as null
            front->next = node;     // first node points to second node(newly created)
        }

        else{                       // when there is two or more nodes in the list
            node->next = nullptr;   // new node node set as null
            rear->next = node;      // last node will point to the new node(now last node)
            rear = rear->next;      // rear will now point to the newly created node(last node)
        }

        cout<<"Item added successfully in the queue"<<endl;
    }
}

bool ListQueue:: isEmpty(){         // method for checking empty list condition
    if(front == nullptr)
        return true;

    else
        return false;
}

void ListQueue:: deQueue(){         // method for dequeue
    int del_data;                   // variable to hold the deleted value
    ListQueue* front1;              // pointer for holding the reference of first node

    if(isEmpty())
        cout<<"The list is empty cannot perform dequeue operation"<<endl;

    else{
        del_data = front->data;         // del_data gets the value stored in the first node
        front1 = front;                 // front1 gets the reference of the first node
        front = front->next;            // front now points to the next node
        delete(front1);                 // deleted the first node(second node is first now)

        cout<<"The element which is deleted from the queue is: "<<del_data<<endl;
    }

}

void ListQueue::dispQueue(){        // method for displaying elements of the queue
    ListQueue *t = front;           // t holds the address of the first node

    if(t == nullptr)                // if list is empty
        cout<<"The list is empty!"<<endl;
    
    else{
        
        cout<<"The elements in the list are: "<<endl;
        while(t != nullptr){
            cout<<t->data<<" ";
            t = t->next;
        }cout<<endl;
    }
}

void ListQueue::numEleQueue(){      // method for determining the number of elements in the queue
    int count = 0;
    ListQueue *t = front;

    while(t != nullptr){
        count++;
        t = t->next;
    }

    cout<<"The number of elements in the queue are: "<<count;
}

int main(){
    int option;
    ListQueue lq;

    cout<<"Select an option from the below list: "<<endl;

    do{
        cout<<"\n\n****************************Main Menu****************************"<<endl;
        cout<<"1. To enqueue an element from the queue"<<endl;
        cout<<"2. To dequeue an element from the queue"<<endl;
        cout<<"3. To print the elements of the queue"<<endl;
        cout<<"4. To get the number of elemnts in the queue"<<endl;
        cout<<"5. Exit"<<endl;

        cin>>option;

        switch (option)
        {
        case 1:
            lq.enQueue();
            break;

        case 2:
            lq.deQueue();
            break;

        case 3:
            lq.dispQueue();
            break;

        case 4:
            lq.numEleQueue();
            break;
        }

    }while(option != 5);

    return 0;
}