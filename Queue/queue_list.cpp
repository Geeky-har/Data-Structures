#include<iostream>
using namespace std;

class ListQueue{
    int data;
    ListQueue* next;

    public:
        ListQueue* getNode();
        void enQueue();
        void deQueue();
        void dispQueue();
};

ListQueue* rear = nullptr;
ListQueue* front = nullptr;


ListQueue* ListQueue::getNode(){
    ListQueue *t;
    t = new ListQueue();
    return(t);
}

void ListQueue::enQueue(){
    ListQueue *node = getNode();
    int data;

    if(!node)
        cout<<"Cant add elements.. Some problem occurred!"<<endl;

    else{
        cout<<"Enter the element that you want to add: "<<endl;
        cin>>data;

        node->data = data;

        if(front == nullptr){
            front = rear = node;
            node->next = nullptr;
        }

        else if(front == rear){
            rear = node;
            node->next = nullptr;
            front->next = node;
        }

        else{
            node->next = nullptr;
            rear->next = node;
            rear = rear->next;
        }

        cout<<"Item added successfully in the queue"<<endl;
    }
}

void ListQueue:: deQueue(){
    int del_data;
    ListQueue* front1;

    del_data = front->data;
    front1 = front;
    front = front->next;
    delete(front1);

    cout<<"The element which is deleted from the queue is: "<<del_data<<endl;
}

void ListQueue::dispQueue(){
    ListQueue *t = front;

    if(t == nullptr)
        cout<<"The list is empty!"<<endl;
    
    else{
        
        cout<<"The elements in the list are: "<<endl;
        while(t != nullptr){
            cout<<t->data<<" ";
            t = t->next;
        }cout<<endl;
    }
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
        cout<<"4. Exit"<<endl;

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
        }

    }while(option != 4);

    return 0;
}