#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class TreeNode
{
public:
    int data;
    vector<TreeNode *> children;
    TreeNode(int data)
    {
        this->data = data;
    }
};

TreeNode *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data : ";
    cin >> rootData;
    TreeNode *root = new TreeNode(rootData);
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *f = q.front();
        q.pop();
        int n;
        cout << "Enter number of children of " << f->data << " : ";
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int childData;
            cout << "Enter " << i << "th child of " << f->data << " : ";
            cin >> childData;
            TreeNode *child = new TreeNode(childData);
            q.push(child);
            f->children.push_back(child);
        }
    }
    return root;
}

void printTreeLevelWise(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *f = q.front();
        q.pop();
        cout << f->data << " : ";
        for (int i = 0; i < f->children.size(); i++)
        {
            cout << f->children[i]->data << ", ";
        }
        cout << endl;
        for (int i = 0; i < f->children.size(); i++)
        {
            q.push(f->children[i]);
        }
    }
}

int main()
{
    system("CLS");
    TreeNode *root = takeInputLevelWise();
    cout << endl;
    cout << "Tree is : " << endl;
    printTreeLevelWise(root);
    cout << endl;

    return 0;
}