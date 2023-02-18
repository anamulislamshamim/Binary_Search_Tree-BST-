#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node* left;
    int value;
    Node* right;
};
class BST
{
public:
    Node* root;
    BST()
    {
        root = NULL;
    }
    Node* createNewNode(int value)
    {
        Node* newNode = new Node;
        newNode->value = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    void DFS(Node* a)
    {
        if(a==NULL)
            return;
        cout << a->value << " ";
        DFS(a->left);
        DFS(a->right);
    }
    void BFS()
    {
        if(root==NULL)
            return;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int l = -1, r = -1;
            Node* a = q.front();
            q.pop();
            if(a->left != NULL)
            {
                l = a->left->value;
                q.push(a->left);
            }
            if(a->right != NULL)
            {
                l = a->right->value;
                q.push(a->right);
            }
            cout << "Node = " << a->value << ", ";
            cout << "left = " << l << ", ";
            cout << "right = " << r << "\n";
        }
    }
    void Insertion(int value)
    {
        Node* newNode = createNewNode(value);
        if(root == NULL)
        {
            root = newNode;
            return;
        }
        Node* curr = root;
        Node* prev = NULL;
        while(curr != NULL)
        {
            if(newNode->value > curr->value)
            {
                prev = curr;
                curr = curr->right;
            }
            else
            {
                prev = curr;
                curr = curr->left;
            }
        }
        if(newNode->value > prev->value)
        {
            prev->right = newNode;
        }
        else
        {
            prev->left = newNode;
        }
    }
    bool Search(int value)
    {
        if(root == NULL)
            return false;
        Node* curr = root;
        if(curr->value == value)
            return true;
        while(curr != NULL)
        {
            if(value > curr->value)
            {
                curr = curr->right;
            }
            else if(value < curr->value)
            {
                curr = curr->left;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
    void Delete(int value)
    {
        if(root == NULL)
            return;
        Node* curr = root;
        Node* prev = NULL;
        while(curr != NULL)
        {
            if(value > curr->value)
            {
                prev = curr;
                curr = curr->right;
            }
            else if( value < curr->value)
            {
                prev = curr;
                curr = curr->left;
            }
            else
            {
                break;
            }
        }
        if(curr == NULL)
        {
            cout << "The value does not exist in the BST" << "\n";
            return;
        }
        // case-1: both left child and right child are null
        if(curr->left == NULL && curr->right == NULL)
        {
            if(prev->left != NULL && prev->left->value == curr->value)
            {
                prev->left = NULL;
            }
            else
            {
                prev->right = NULL;
            }
            delete curr;
            return;
        }
        // case-2: if left node is not null
        if(curr->left != NULL && curr->right == NULL)
        {
            if(prev->left != NULL && prev->left->value == curr->value)
            {
                prev->left = curr->left;
            }
            else
            {
                prev->right = curr->left;
            }
            delete curr;
            return;
        }
        if(curr->right != NULL && curr->left == NULL)
        {
            if(prev->left != NULL && prev->left->value == curr->value)
            {
                prev->left = curr->right;
            }
            else
            {
                prev->right = curr->right;
            }
            delete curr;
            return;
        }
        // case-3: both left and right node does exist
        Node* tmp = curr->right;
        while(tmp->left != NULL)
        {
            tmp = tmp->left;
        }
        int saved = tmp->value;
        Delete(saved);
        curr->value = saved;
    }
};
int main()
{
    BST bst;
    bst.Insertion(6);
    bst.Insertion(4);
    bst.Insertion(3);
    bst.Insertion(5);
    bst.Insertion(7);
    bst.Insertion(8);
    bst.Delete(6);
    bst.BFS();
    return 0;
}