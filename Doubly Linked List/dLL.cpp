/*

 The double linked list is similar to the single list the only difference between both of them
is that, each node in the doubly list contains the address of both its previous and next node...
The implementation is almost the same however the contents of the class(or struct) will change

*/

#include <iostream>
using namespace std;

class DeNode
{
    int data;
    DeNode *prev;
    DeNode *next;

public:
    DeNode *createNode();
    void insertNode();
    void printNode();
    void addNode();
    void deleteNode();
    void addBeg();
};

DeNode *Start = nullptr;

DeNode *DeNode::createNode()
{
    DeNode *temp;
    temp = new DeNode();
    return (temp);
}

void DeNode::insertNode()
{
    int item;
    DeNode *node, *traverse;

    cout << "Enter 00 after the last element to terminate the list" << endl;
    cout << "Enter the values in the list" << endl;
    cin >> item;

    while (item != 00)
    {
        node = createNode();
        node->data = item;

        if (Start == nullptr)
        {
            Start = node;
            node->prev = nullptr;
            node->next = nullptr;
        }

        else
        {
            traverse = Start;
            while (traverse->next != nullptr)
            {
                traverse = traverse->next;
            }

            traverse->next = node;
            node->prev = traverse;
        }

        cin >> item;
    }
}

void DeNode::printNode()
{
    DeNode *traverse = Start;

    if (traverse == nullptr) //if header contains null print error
    {
        cout << "First Enter the elements in the list to perform print operation!!" << endl;
    }

    else
    {
        while (traverse->next != nullptr)
        {
            cout << traverse->data << " -> ";
            traverse = traverse->next;
        }

        if (traverse->next == nullptr)
        {
            cout << traverse->data << " ";
        }
    }
}

void DeNode::addNode()
{
    int data, key;
    DeNode *traverse = Start, *new_node;

    if (traverse == nullptr)
    {
        cout << "List not found. Create a list first" << endl;
    }

    else
    {
        cout << "Enter the element after which you want to add the new node: " << endl;
        cin >> key;

        cout << "Now enter the data of the new node: " << endl;
        cin >> data;

        while (traverse->next != nullptr && traverse->data != key)
        {
            traverse = traverse->next;
        }

        if (traverse->next == nullptr && traverse->data != key)
        {
            cout << "The key you entered is not present in the list" << endl;
        }

        else if (traverse->next == nullptr && traverse->data == key)
        {
            new_node = createNode();
            new_node->data = data;
            traverse->next = new_node;
            new_node->prev = traverse;
            new_node->next = nullptr;

            cout << "New node successfullly added" << endl;
        }

        else
        {
            DeNode *temp;
            new_node = createNode();
            new_node->data = data;
            temp = traverse->next;
            traverse->next = new_node;
            new_node->prev = traverse;
            new_node->next = temp;

            cout << "New node successfullly added" << endl;
        }
    }
}

void DeNode::deleteNode()
{
    DeNode *traverse = Start;
    int key;

    if (traverse == nullptr)
        cout << "List not found" << endl;

    else
    {
        cout << "Enter the value of the node which you want to delete: " << endl;
        cin >> key;

        while (traverse->next != nullptr && traverse->data != key)
        {
            traverse = traverse->next;
        }

        if (traverse->next == nullptr && traverse->data != key)
        {
            cout << "The value you entered is not present in the list!" << endl;
        }

        else if(traverse->prev == nullptr && traverse->data == key)     // for deletion from the beginning
        {
            DeNode *temp = Start;
            Start = traverse->next;
            traverse->next->prev = nullptr;
            traverse->next = nullptr;
            delete(traverse);

            cout<<"item successfully deleted from the list!"<<endl;
        }

        else if (traverse->next == nullptr && traverse->data == key)    // for deletion at the end
        {
            traverse->prev->next = nullptr;
            delete (traverse);

            cout << "Item Successfully deleted from the list!" << endl;
        }

        else            // for deletion in the middle of the list
        {
            traverse->prev->next = traverse->next;
            traverse->next->prev = traverse->prev;
            delete (traverse);

            cout << "Item Successfully deleted from the list!" << endl;
        }
    }
}

void DeNode::addBeg()
{
    int data;
    DeNode *t, *aux;

    cout << "Enter the value of the data to be inserted: " << endl;
    cin >> data;

    t = createNode();

    if (!t)
        cout << "Memory Error!!" << endl;

    else
    {
        t->data = data;
        t->prev = nullptr;

        if (Start == nullptr)
        {
            Start = t;
            t->next = nullptr;
        }

        else
        {
            aux = Start;
            t->next = aux;
            Start = t;
        }

        cout << "The Item is successfully added in the list!" << endl;
    }
}

int main()
{
    int option;
    DeNode obj;

    cout << "Select any option from the given menu!!" << endl
         << endl;

    do
    {
        cout << "\n****************************Main Menu****************************" << endl;
        cout << "1. Create a List " << endl;
        cout << "2. Print a List " << endl;
        cout << "3. To add an element in the beginning of the list" << endl;
        cout << "4. Add a node in the list after an element " << endl;
        cout << "5. To delete an existing node" << endl;
        cout << "6. Exit " << endl;
        cin >> option;

        switch (option)
        {
        case 1:
            obj.insertNode();
            break;

        case 2:
            obj.printNode();
            break;

        case 3:
            obj.addBeg();
            break;

        case 4:
            obj.addNode();
            break;

        case 5:
            obj.deleteNode();
            break;
        }

    } while (option != 6);

    return 0;
}