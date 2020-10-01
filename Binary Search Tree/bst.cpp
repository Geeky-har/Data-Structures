// In this program we will be implementing the binary search tree..

#include <bits/stdc++.h>
using namespace std;

class BstNode
{
private:
    int data;
    BstNode *left;
    BstNode *right;

public:
    BstNode *newNode();
    BstNode *rootNode(int);
    BstNode *insertNode(BstNode *, int);
    BstNode *deleteNode(BstNode *, int);
    void inorderT(BstNode *);
    void preorderT(BstNode *);
    void postorderT(BstNode *);
    void levelorderT(BstNode *);
};

BstNode *BstNode::newNode()
{
    BstNode *temp;
    temp = new BstNode();
    return temp;
}

BstNode *BstNode::rootNode(int data)
{
    BstNode *temp;

    temp = newNode();
    temp->data = data;
    temp->left = temp->right = nullptr;

    return temp;
}

BstNode *BstNode::insertNode(BstNode *root, int data)
{
    if (root == nullptr)
    {
        root = newNode();

        if (root == nullptr)
        {
            cout << "Memory Error!" << endl;
        }

        else
        {
            root->data = data;
            root->left = root->right = nullptr;
        }
    }

    else
    {

        if (data < root->data)
        {
            root->left = insertNode(root->left, data);
        }

        else
        {
            root->right = insertNode(root->right, data);
        }
    }

    return root;
}

void BstNode::inorderT(BstNode *root) // Time Complexity O(n); Space Complexity O(n)
{
    if (root == nullptr)
    {
        return;
    }

    inorderT(root->left);
    cout << root->data << " ";
    inorderT(root->right);
}

void BstNode::preorderT(BstNode *root)
{ // Time Complexity O(n); Space Complexity O(n)

    if (root == nullptr)
        return;

    cout << root->data << " ";
    preorderT(root->left);
    preorderT(root->right);
}

void BstNode::postorderT(BstNode *root)
{ // Time Complexity O(n); Space Complexity O(n)

    if (root == nullptr)
        return;

    postorderT(root->left);
    postorderT(root->right);
    cout << root->data << " ";
}

void BstNode::levelorderT(BstNode *root)
{

    if (root == nullptr)
    {
        cout << "Root Not set!!" << endl;
        return;
    }

    queue<BstNode *> q; // queue for storing nodes
    BstNode *temp;

    q.push(root); // pushing root node inside queue

    while (!q.empty())
    { // iterate until queue becomes empty

        temp = q.front(); // store frontmost element in temp

        cout << temp->data << " "; // process the node dat
        q.pop();                   // pop the node from the queue

        if (temp->left)         // if node has left child
            q.push(temp->left); // push the left child node into the queue

        if (temp->right)         // if node has right child
            q.push(temp->right); // push the left child node into the queue
    }
}

BstNode *BstNode::deleteNode(BstNode *root, int key)
{

    if (root == nullptr)
        return root;

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
        return root;
    }

    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
        return root;
    }

    // Now root points to that node which has to be deleted
    // if one of the children is empty

    if (root->left == NULL)
    {
        BstNode *temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL)
    {
        BstNode *temp = root->left;
        delete root;
        return temp;
    }

    // If both children exist
    else
    {
        BstNode *succParent = root;

        // Find successor
        BstNode *succ = root->right;
        while (succ->left != NULL)
        {
            succParent = succ;
            succ = succ->left;
        }

        // Delete successor. Since successor
        // is always left child of its parent
        // we can safely make successor's right
        // right child as left of its parent.
        // If there is no succ, then assign
        // succ->right to succParent->right
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;

        // Copy Successor Data to root
        root->data = succ->data;

        // Delete Successor and return root
        delete succ;
        return root;
    }
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
        cout << "4. To display preorder traversal of the tree" << endl;
        cout << "5. To display postorder traversal of the tree" << endl;
        cout << "6. To display Level-Order traversal of the tree" << endl;
        cout << "7. To delete a node from the tree" << endl;
        cout << "8. Exit" << endl;
        cin >> option;

        switch (option)
        {
        case 1:
            int item;

            cout << "Enter the value: " << endl;
            cin >> item;

            root = b.rootNode(item);
            break;

        case 2:
            int data;
            cout << "Enter the data that you want to insert: " << endl;
            cin >> data;

            root = b.insertNode(root, data);
            cout << "Node inserted successfully!!" << endl;

            break;

        case 3:
            b.inorderT(root);
            break;

        case 4:
            b.preorderT(root);
            break;

        case 5:
            b.postorderT(root);
            break;

        case 6:
            b.levelorderT(root);
            break;

        case 7:
            int key;

            cout << "Enter the value of the node that you want to delete: " << endl;
            cin >> key;

            root = b.deleteNode(root, key);
            break;
        }

    } while (option != 8);

    return 0;
}