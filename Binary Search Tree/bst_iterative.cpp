/*

 here in this program we will implement bst with operations like: Set Root, Insert new node, Search for a new node, delete a node, inorder traversal, all with iterative approach

 */

#include <bits/stdc++.h>
using namespace std;

class BstNode
{
private:
    int data;
    BstNode *left;
    BstNode *right;

public:
    BstNode *newNode(int);
    BstNode *setRoot();
    void insertNode(BstNode *);
    void inorderT(BstNode *);
    bool find(BstNode *, int);
    BstNode *deleteNode(BstNode *, int);
};

BstNode *BstNode::newNode(int data)
{
    BstNode *temp;
    temp = new BstNode();
    temp->data = data;
    temp->left = temp->right = nullptr;

    return temp;
}

BstNode *BstNode::setRoot()
{
    int data;
    BstNode *temp;

    cout << "Enter the data root data: " << endl;
    cin >> data;

    temp = newNode(data);

    cout << "Value of root is set!!" << endl;

    return temp;
}

void BstNode::insertNode(BstNode *root)
{
    int data;
    BstNode *temp;
    BstNode *x = root;
    BstNode *y = nullptr;

    cout << "Enter the value of the node: " << endl;
    cin >> data;

    temp = newNode(data);

    if (root == nullptr)
    {
        cout << "Root is not set! First create the root node!!" << endl;
    }

    else
    {
        while (x != nullptr) // will iterate till x is not null
        {
            y = x; // will hold the parent node of current x

            if (data < x->data) // if new data is less than the current node, then
                x = x->left;    // move to the left node

            else              // otherwise,
                x = x->right; // move to the right node
        }

        //at this point x will be null, and y contains parent node of x

        if (data < y->data) // if data to be inserted is less than the value of y node(i.e parent of x)
        {
            y->left = temp; // will place the new node to the left of the y node
        }

        else //otherwise,
        {
            y->right = temp; // will place the new node to the right of the y node
        }
    }
}

void BstNode::inorderT(BstNode *root)
{
    stack<BstNode *> st;
    BstNode *curr = root;

    while (1)
    {
        while (curr != nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }

        if (st.empty())
            break;

        curr = st.top();
        st.pop();

        cout << curr->data << " ";
        curr = curr->right;
    }
}

bool BstNode::find(BstNode *root, int value)
{

    if (!root)
    {
        cout << "Create a root node first!" << endl;
        return false;
    }

    else
    {
        while (root)
        {
            if (root->data == value)
                return true;

            else if (root->data < value)
                root = root->right;

            else
                root = root->left;
        }

        return false;
    }
}

BstNode *BstNode::deleteNode(BstNode *root, int key)
{

    BstNode *curr = root;    // for pointing to the node that has to be deleted
    BstNode *prev = nullptr; // for pointing to the parent of the current node

    while (curr != nullptr && curr->data != key)
    {
        prev = curr;

        if (key < curr->data)
            curr = curr->left;

        else
            curr = curr->right;
    }

    //if curr is null that means node is not present

    if (curr == nullptr)
    {
        cout << "The key you entered is not present in the tree!" << endl;
        return root;
    }

    // now we will check if the current node has atmost one child or not

    if (curr->left == nullptr || curr->right == nullptr)
    {

        BstNode *newcurr; // it will point to the value of the node that will replace the curr node

        if (curr->left == nullptr) // if left node is not present
            newcurr = curr->right; // right child will replace the currnode

        else
            newcurr = curr->left; // left child will replace the currnode

        // now we will check if the currnode is root or not(in this case this is skewed tree)

        if (prev == nullptr)
        {
            cout << "The node is deleted successfully!" << endl;
            return newcurr;
        }

        // now we will check whether currnode is in left subtree or right subtree of the parent node
        if (curr == prev->left) // if currnode is left child
        {
            prev->left = newcurr; // the left of parent will point to the newcurr
        }

        else
        {
            prev->right = newcurr;
        }

        // freed the memory of the currnode

        delete (newcurr);

        cout << "The node having value " << key << " is deleted successfully" << endl;
    }

    else // if the node to be deleted have two child nodes
    {
        BstNode *newcurr;        // will hold the address of the node which will replace the currnode
        BstNode *prev = nullptr; // for pointing to the parent of newcurr

        // now we will calculate the inorder successor(smallest in right subtree) of the curr

        newcurr = curr->right; // newcurr now points to the node of right sub tree

        while (newcurr->left != nullptr)
        {
            prev = newcurr;
            newcurr = newcurr->left;
        }

        // now newcurr points to the inorder successor of curr

        if (prev != nullptr)             // if the parent of newcurr is not curr(a node)
            prev->left = newcurr->right; // parent of newcurr stores right child of newcurr in its left subtree

        else                              // if the parent of newcurr is curr itself
            curr->right = newcurr->right; // right of curr node points to the right of newcurr

        // replace the curr data with newcurr

        curr->data = newcurr->data;
        delete (newcurr);

        cout << "The node having value " << key << " is deleted successfully" << endl;
    }

    return root;
}

int main()
{
    int option;
    BstNode b, *root = nullptr;

    do
    {
        cout << endl
             << "************************************MAIN MENU************************************" << endl;
        cout << "Select from the below menu" << endl;
        cout << "1. To create a root" << endl;
        cout << "2. To insert a node" << endl;
        cout << "3. To display inorder traversal of the tree" << endl;
        cout << "4. To search for a element in the Binary Search Tree" << endl;
        cout << "5. To delete a node from the Binary Search Tree" << endl;
        cout << "6. Exit" << endl;
        cin >> option;

        switch (option)
        {
        case 1:
            root = b.setRoot();
            break;

        case 2:
            b.insertNode(root);
            break;

        case 3:
            b.inorderT(root);
            break;

        case 4:
            bool flag;
            int value;

            cout << "Enter the element that you want to find: " << endl;
            cin >> value;

            flag = b.find(root, value);

            if (flag)
                cout << "Element is found!" << endl;

            else
                cout << "Element is not found!" << endl;
            break;

        case 5:
            int value2;
            cout << "Enter the value of the node that you want to delete: " << endl;
            cin >> value2;

            root = b.deleteNode(root, value2);
            break;
        }

    } while (option != 6);

    return 0;
}