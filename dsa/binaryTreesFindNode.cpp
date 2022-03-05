#include <iostream>
#include <queue>
using namespace std;

class BTNode
{
public:
    int data;
    BTNode *left;
    BTNode *right;
    BTNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BTNode()
    {
        delete left;
        delete right;
    }
};

void printTreeRecursively(BTNode *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " : ";
    if (root->left != NULL)
    {
        cout << "L : " << root->left->data << ", ";
    }
    if (root->right != NULL)
    {
        cout << "R : " << root->right->data << ", ";
    }
    cout << endl;
    printTreeRecursively(root->left);
    printTreeRecursively(root->right);
}

BTNode *takeInput()
{
    int rootData;
    cout << "Enter root data : ";
    cin >> rootData;
    BTNode *root = new BTNode(rootData);
    queue<BTNode *> q;
    q.push(root);

    while (!q.empty())
    {
        BTNode *f = q.front();
        q.pop();

        int leftChildData;
        cout << "Enter left child of " << f->data << " : ";
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BTNode *child = new BTNode(leftChildData);
            q.push(child);
            f->left = child;
        }

        int rightChildData;
        cout << "Enter right child of " << f->data << " : ";
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BTNode *child = new BTNode(rightChildData);
            q.push(child);
            f->right = child;
        }
    }
    return root;
}

bool findNode(BTNode *root, int key)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == key)
    {
        return true;
    }

    return (findNode(root->left, key) || findNode(root->right, key));
}

int main()
{
    BTNode *root = takeInput();
    cout << endl;
    cout << "BINARY TREE : " << endl;
    printTreeRecursively(root);
    cout << endl;
    int key;
    cout << "Which key are you looking for?" << endl;
    cin >> key;
    if (findNode(root, key))
    {
        cout << "found" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }

    return 0;
}