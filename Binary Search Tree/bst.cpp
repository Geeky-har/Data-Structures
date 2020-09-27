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
    BstNode* insertNode(BstNode *, int);
    void inorderT(BstNode *);
};

BstNode *BstNode::newNode()
{
    BstNode *temp;
    temp = new BstNode();
    return temp;
}

BstNode* BstNode::rootNode(int data)
{
    BstNode *temp;

    temp = newNode();
    temp->data = data;
    temp->left = temp->right = nullptr;

    return temp;
}

BstNode* BstNode::insertNode(BstNode *root, int data)
{
    if (root == nullptr)
    {   
        root = newNode();

        if(root == nullptr){
            cout<<"Memory Error!"<<endl;
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

void BstNode::inorderT(BstNode *root)
{
    if(root == nullptr){
        return;
    }

    inorderT(root->left);
    cout << root->data << " ";
    inorderT(root->right);
}

int main(){
    int option;
    BstNode b, *root = nullptr;

    do{
        cout<<endl<<"************************************MAIN MENU************************************"<<endl;
        cout<<"Select from the below menu"<<endl;
        cout<<"1. To create a root"<<endl;
        cout<<"2. To insert a node"<<endl;
        cout<<"3. To display inorder traversal of the tree"<<endl;
        cout<<"4. Exit"<<endl;
        cin>>option;

    
        switch (option)
        {
            case 1:
                int item;

                cout<<"Enter the value: "<<endl;
                cin>>item;

                root = b.rootNode(item);
                break;

            case 2:
                int data;
                cout<<"Enter the data that you want to insert: "<<endl;
                cin>>data;

                root = b.insertNode(root, data);
                cout << "Node inserted successfully!!" << endl;

                break;

            case 3:
                b.inorderT(root);
                break;

        }

    }while(option != 4);

    return 0;
}