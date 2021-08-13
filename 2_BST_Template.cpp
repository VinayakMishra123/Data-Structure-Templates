#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define rep(int, i, z) for (int i = 0; i < z; i++)
struct node
{
    int data;
    node *left;
    node *right;
    node *next;
    node(int x)
    {
        this->data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};



node *search(node *head, int key)
{
    if (head == nullptr)
    {
        return NULL;
    }
    if (head->data == key)
    {
        return head;
    }
    else
    {
        if (head->data > key)
        {
            search(head->left, key);
        }
        else if (head->data < key)
        {
            search(head->right, key);
        }
    }
}




node *iterSearch(node *head, int key)
{
    if (head == nullptr)
    {
        return NULL;
    }
    if (head->data == key)
    {
        return head;
    }
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return temp;
        }
        else if (temp->data < key)
        {
            temp = temp->right;
        }
        else if (temp->data > key)
        {
            temp = temp->left;
        }
    }
    return NULL;
}




void inorderT(node *head)
{
    if (head == NULL)
        return;
    inorderT(head->left);
    cout << head->data << " ";
    inorderT(head->right);
}




void insertBST(node *head, int key)
{
    node *p = NULL, *temp = head;
    while (temp != NULL)
    {
        p = temp;
        if (temp->data == key)
        {
            return;
        }
        else if (temp->data < key)
        {
            temp = temp->right;
        }
        else if (temp->data > key)
        {
            temp = temp->left;
        }
    }
    temp = new node(key);

    if (key > p->data)
    {
        p->right = temp;
    }

    else
    {
        p->left = temp;
    }
}


/*deletion left*/
node *success(){}
node *deleteBST(node *head, int key)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->data < key)
    {
        head->right = deleteBST(head->right, key);
    }
    else if (head->data > key)
    {
        head->left = deleteBST(head->left, key);
    }
}




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    node *rootptr = new node(2);
    insertBST(rootptr, 6);
    insertBST(rootptr, 5);
    insertBST(rootptr, 8);
    insertBST(rootptr, 7);
    inorderT(rootptr);
}