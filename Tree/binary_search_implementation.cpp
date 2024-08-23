// by Khan Muhammad Rifat (CSE, BUBT)
#include <bits/stdc++.h>
#define ll long long
#define nl endl
#define PI 2 * acos(0.0)
using namespace std;

void Fast_io()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
}

class Node
{
public:
    int value;
    Node *left;
    Node *right;
    Node(int val) : value(val), left(NULL), right(NULL) {}
};

void preorder(Node *root)
{

    // base case
    if (root == NULL)
    {
        return;
    }
    cout << root->value << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{

    // base case
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->value << " ";
}

void inorder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->value << " ";
    inorder(root->right);
}

void level_order(Node *root)
{
    if (root == nullptr)
        return;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        // 1. Element take ber kore ana
        Node *pivot_node = q.front();
        q.pop();

        // 2. Jabotiyo kaj ekhane korbo
        cout << pivot_node->value << " ";

        // 3. jake ber korlam tar children gulake queue er vetor rekhe dibo
        if (pivot_node->left)
            q.push(pivot_node->left);
        if (pivot_node->right)
            q.push(pivot_node->right);
    }
}

int main()
{

    Node *root = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *d = new Node(50);
    Node *e = new Node(60);
    Node *f = new Node(70);
    Node *g = new Node(80);
    Node *h = new Node(90);
    Node *i = new Node(100);

    // connections
    root->left = a;
    root->right = b;
    a->left = c;
    a->right = h;
    b->left = NULL;
    b->right = d;
    c->left = NULL;
    c->right = e;
    d->left = f;
    d->right = g;
    h->right = i;

    // call
    preorder(root);
    cout << nl;
    postorder(root);
    cout << nl;
    inorder(root);
    cout << nl;
    level_order(root);
    return 0;
}