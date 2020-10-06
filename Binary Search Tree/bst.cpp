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
    BstNode *minValueNode(BstNode *);
    BstNode *maxValueNode(BstNode *);
    int minValue(BstNode *);
    int maxValue(BstNode *);
    bool search(BstNode * , int);
    int findHeight(BstNode*);
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
    BstNode *temp;

    if (root == nullptr)
        cout << "Root not set!!" << endl;

    else if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }

    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }

    else
    { // control wil reach here when the element is found

        if (root->left && root->right)
        {
            temp = maxValueNode(root->left); // will return the inorder predecessor
            root->data = temp->data;         // changed the element to inorder predecessor
            root->left = deleteNode(root->left, root->data);    // will delete the inorder predecessor from the left subtree
        }

        else
        { // one or zero child nodes

            temp = root;

            if (root->left == nullptr)     // if root have right node
                root = root->right;        // right node will replace the node to be deleted

            else if (root->right == nullptr)    //---do---
                root = root->left;              //---do---

            delete (temp);
        }
    }

    return (root);

    // (alternate)Now root points to that node which has to be deleted

    // if one of the children is empty

    // if (root->left == NULL)
    // {
    //     BstNode *temp = root->right;
    //     delete root;
    //     return temp;
    // }
    // else if (root->right == NULL)
    // {
    //     BstNode *temp = root->left;
    //     delete root;
    //     return temp;
    // }

    // // If both children exist
    // else
    // {
    //     BstNode *succParent = root;

    //     // Find successor
    //     BstNode *succ = root->right;
    //     while (succ->left != NULL)
    //     {
    //         succParent = succ;
    //         succ = succ->left;
    //     }

    //     // Delete successor. Since successor
    //     // is always left child of its parent
    //     // we can safely make successor's right
    //     // right child as left of its parent.
    //     // If there is no succ, then assign
    //     // succ->right to succParent->right
    //     if (succParent != root)
    //         succParent->left = succ->right;
    //     else
    //         succParent->right = succ->right;

    //     // Copy Successor Data to root
    //     root->data = succ->data;

    //     // Delete Successor and return root
    //     delete succ;
    //     return root;
    // }
}

BstNode *BstNode::minValueNode(BstNode *root)
{

    if (root->left == nullptr)
        return (root);

    return minValueNode(root->left);
}

BstNode *BstNode::maxValueNode(BstNode *root)
{

    if (root->right == nullptr)
        return (root);

    return maxValueNode(root->right);
}

int BstNode::minValue(BstNode *root)
{

    if (root->left == nullptr)
        return (root->data);

    return minValue(root->left);
}

int BstNode::maxValue(BstNode *root)
{

    if (root->right == nullptr)
        return (root->data);

    return maxValue(root->right);
}

bool BstNode::search(BstNode* root, int key){

    if(root == nullptr)
        return false;

    else if(root->data == key)
        return true;

    else if(root->data > key)
        return search(root->left, key);

    else
        return search(root->right, key);

}

// Time Complexity O(n); Space Complexity O(n)
int BstNode::findHeight(BstNode* root){     // height means number of edges from node to leaf node(depth means the number of edges from the node to the root of the tree)

    if(root == nullptr){                    // if root is null will return 0
        return 0;
    }

    else{
        int lheight = findHeight(root->left);       // this will calculate the height of left subtree
        int rheight = findHeight(root->right);      // this will calculate the height of right subtree
        
        return max(lheight, rheight) + 1;       // will return the max of the latter + 1 (for leaf)
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
        cout << "8. To display the minimum element in the tree" << endl;
        cout << "9. To display the maximum element in the tree" << endl;
        cout << "10. To search for a element in the tree" << endl;
        cout << "11. To determine the height of the tree" << endl;
        cout << "12. Exit" << endl;
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

        case 8:
            int min;
            min = b.minValue(root);

            cout << "The smallest value in the tree is: " << min << endl;
            break;

        case 9:
            int max;
            max = b.maxValue(root);

            cout << "The largest value in the tree is: " << max << endl;

        case 10:
            int find;

            cout<<"Enter the element that you have to search: "<<endl;
            cin>>find;

            if(b.search(root, find))
                cout<<"Element found"<<endl;

            else
                cout<<"Element not found"<<endl;

        case 11:
            int num;
            num = b.findHeight(root);

            cout<<"The height the tree is: "<<num;

        }

    } while (option != 12);

    return 0;
}