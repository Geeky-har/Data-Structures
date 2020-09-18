// In this program I will be implementing the functionality of Stack ADT using concept of Linked List

#include <iostream>
using namespace std;

class ListStack
{
    int data;
    ListStack *address;

public:
    ListStack *getNode();
    bool isEmpty();
    void push();
    void printStack();
    void pop();
    void sizeStack();
    void printTop();
};

ListStack *start = nullptr;

ListStack *ListStack::getNode()
{
    ListStack *temp;
    temp = new ListStack();
    return temp;
}

bool ListStack::isEmpty()
{
    if (start == nullptr)
        return true;

    else
        return false;
}

void ListStack::push()
{
    int data;
    ListStack *node;
    ListStack *top;
    node = getNode();

    cout << "Enter the data you want to enter in the stack: " << endl;
    cin >> data;

    if (start == nullptr)
    {
        node->data = data;
        node->address = nullptr;
        start = node;

        cout << "Item pushed successfully" << endl;
    }

    else
    {
        top = start;
        node->data = data;
        node->address = top;
        start = node;

        cout << "Item pushed successfully" << endl;
    }
}

void ListStack::printStack()
{
    ListStack *t = start;

    if (isEmpty())
        cout << "Stack is empty! perform push operation.." << endl;

    else
    {
        cout << "Elements in the stack(from right to left) are: " << endl;

        while (t != nullptr)
        {
            cout << t->data << " ";
            t = t->address;
        }
        cout << endl;
    }
}

void ListStack::pop()
{
    int del_data;
    ListStack *top;

    if (isEmpty())
        cout << "Stack is Empty(underflow)!" << endl;

    else
    {
        top = start;
        del_data = top->data;
        start = top->address;
        delete (top);

        cout << "The element which is popped out is: " << del_data << endl;
    }
}

void ListStack::sizeStack()
{
    ListStack *t = start;
    int count = 0;

    while (t != nullptr)
    {
        count++;
        t = t->address;
    }

    cout << "The size of the stack is: " << count << endl;
}

void ListStack::printTop()
{
    int data;
    ListStack *t = start;

    if (t == nullptr)
        cout << "The stack is empty" << endl;

    else
    {
        data = start->data;

        cout << "The element at the top is: " << data << endl;
    }
}

int main()
{
    int option;
    ListStack ll;

    cout << "Select an option from the below list: " << endl
         << endl;

    do
    {
        cout << "1. To perform Push operation" << endl;
        cout << "2. To perform Pop operation" << endl;
        cout << "3. To print the stack elements" << endl;
        cout << "4. To print the size of the stack" << endl;
        cout << "5. To get the element at top" << endl;
        cout << "6. Exit" << endl;

        cin >> option;

        switch (option)
        {
        case 1:
            ll.push();
            break;

        case 2:
            ll.pop();
            break;

        case 3:
            ll.printStack();
            break;

        case 4:
            ll.sizeStack();
            break;

        case 5:
            ll.printTop();
            break;
        }
    } while (option != 6);

    return 0;
}