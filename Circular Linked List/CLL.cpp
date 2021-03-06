/*

circular linked lists do not have ends. While traversing the circular linked lists we should be
careful; otherwise we will be traversing the list infinitely. In circular linked lists, each node has a
successor. Note that unlike singly linked lists, there is no node with NULL pointer in a circularly
linked list.

*/

#include <iostream>
using namespace std;

class CLLNode
{
    int data;
    CLLNode *next;

public:
    CLLNode *createNode();
    void insertNode();
    void printList();
    void insertBeg();
    void deleteBeg();
    void deleteAny();
    void insertList();
};

CLLNode *start = nullptr;

CLLNode *CLLNode::createNode()
{
    CLLNode *temp;
    temp = new CLLNode();
    return temp;
}

void CLLNode::insertNode()
{
    int data;
    CLLNode *t;
    CLLNode *current = start;

    t = createNode();

    cout << "Enter the value of data: " << endl;
    cin >> data;
    t->data = data;
    t->next = start;

    if (start == nullptr)
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

    cout << "Item successfully added in the list!!" << endl;
}

void CLLNode::printList()
{
    CLLNode *t = start;

    if (t == nullptr)
        cout << "The List is empty!" << endl;

    else
    {
        cout << "Your List is: " << endl;

        while (t->next != start)
        {
            cout << t->data << " -> ";
            t = t->next;
        }

        if (t->next == start)
            cout << t->data << endl;
    }
}

void CLLNode::insertBeg()
{
    int data;
    CLLNode *t = start;
    CLLNode *newNode = createNode();

    cout << "Enter the element that you want to insert: " << endl;
    cin >> data;
    newNode->data = data;

    if (t == nullptr)
    {
        start = newNode;
        newNode->next = start;
    }

    else
    {
        CLLNode *temp = start;
        newNode->next = temp;
        start = newNode;

        while (t->next != temp)
        {
            t = t->next;
        }

        t->next = newNode;

        cout << "New Node successfully added in the beginning" << endl;
    }
}

void CLLNode::deleteBeg()
{
    int del_data;
    CLLNode *current = start;
    CLLNode *temp = start;

    if (current == nullptr)
        cout << "List is empty!" << endl;

    else
    {
        del_data = current->data;

        while (current->next != start)
            current = current->next;

        current->next = start->next;
        start = start->next;

        delete (temp);

        cout << "The element " << del_data << " is deleted from the list" << endl;
    }
}

void CLLNode::insertList()
{
    CLLNode *t = start;
    CLLNode *newNode;

    if (t == nullptr)
        cout << "The list is empty!!" << endl;

    else
    {
        int data, key;

        cout << "Enter the element after which you want to perform insertion: " << endl;
        cin >> key;

        cout << "Now enter the value of new element: " << endl;
        cin >> data;

        while (t->next != start && t->data != key)
            t = t->next;

        if (t->next == start && t->data != key)
            cout << "The key you entered is not present in the list" << endl;

        else if (t->next == start && t->data == key)
        {
            newNode = createNode();
            newNode->data = data;

            t->next = newNode;
            newNode->next = start;

            cout << "New node added successfully!!" << endl;
        }

        else
        {
            CLLNode *temp = t->next;
            newNode = createNode();
            newNode->data = data;
            t->next = newNode;
            newNode->next = temp;

            cout << "New node added successfully!!" << endl;
        }
    }
}

void CLLNode::deleteAny()
{
    CLLNode *t = start;
    CLLNode *t1 = nullptr;

    if (t == nullptr)
        cout << "The list is empty!" << endl;

    else
    {
        int del_data;
        cout << "Enter the element that you want to delete from the list: " << endl;
        cin >> del_data;

        if (t->data == del_data)
        {
            int data;
            CLLNode *temp = start;
            data = t->data;

            if (t->next == start)
            {
                start = nullptr;
                delete(t);
            }

            else
            {
                while (t->next != start)
                    t = t->next;

                t->next = start->next;
                start = start->next;
                delete(temp);
            }

            cout<<"The element "<<data<<" is deleted from the list"<<endl;
        }

        else
        {

            while (t->next != start && t->data != del_data)
            {
                t1 = t;
                t = t->next;
            }

            if (t->next == start && t->data != del_data)
            {
                cout << "The key you entered is not present in the list" << endl;
            }

            else if (t->next == start && t->data == del_data)
            {
                int del;
                t1->next = start;
                del = t->data;
                delete (t);

                cout << "The element which is deleted is: " << del << endl;
            }

            else
            {
                int del;
                CLLNode *temp = t->next;
                t1->next = temp;
                del = t->data;
                delete (t);

                cout << "The element which is deleted is: " << del << endl;
            }
        }
    }
}

int main()
{
    int option;
    CLLNode obj;

    cout << "Select any option from the given menu!!" << endl;

    do
    {

        cout << "\n****************************Main Menu****************************" << endl;
        cout << "1. To insert element in the list" << endl;
        cout << "2. To print the list" << endl;
        cout << "3. To insert an element in the beg" << endl;
        cout << "4. To insert an element anywhere in the list" << endl;
        cout << "5. To delete an element from the beg" << endl;
        cout << "6. To delete an element from anywhere" << endl;
        cout << "7. Exit" << endl;
        cin >> option;

        switch (option)
        {
        case 1:
            obj.insertNode();
            break;

        case 2:
            obj.printList();
            break;

        case 3:
            obj.insertBeg();
            break;

        case 4:
            obj.insertList();
            break;

        case 5:
            obj.deleteBeg();
            break;

        case 6:
            obj.deleteAny();
            break;
        }

    } while (option != 7);

    return 0;
}