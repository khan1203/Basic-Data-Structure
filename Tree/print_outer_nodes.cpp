// by Khan Muhammad Rifat (CSE, BUBT)
#include <bits/stdc++.h>
#define ll long long
#define nl endl
#define PI 2 * acos(0.0)
using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;
    Node(int val) : value(val), left(NULL), right(NULL) {}
};

Node *input_Btree()
{
    int val;
    cin >> val;
    Node *root = (val == -1) ? NULL : new Node(val);

    queue<Node *> q;
    if (root)
        q.push(root);

    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        Node *myLeft = (l == -1) ? NULL : new Node(l);
        Node *myRight = (r == -1) ? NULL : new Node(r);

        p->left = myLeft;
        p->right = myRight;

        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return root;
}

void left_nodes(Node *root, vector<int> &v)
{
    if (root->left)
    {
        v.push_back(root->left->value);
        left_nodes(root->left, v);
    }
    else if (root->right)
    {
        v.push_back(root->right->value);
        left_nodes(root->right, v);
    }
}

void right_nodes(Node *root)
{
    if (root->right)
    {
        cout << root->right->value << " ";
        right_nodes(root->right);
    }
    else if (root->left)
    {
        cout << root->left->value << " ";
        right_nodes(root->left);
    }
}

int main()
{
    Node *root = input_Btree();
    vector<int> v;

    if (root->left)
    {
        left_nodes(root, v);
        for (auto it = v.rbegin(); it != v.rend(); it++)
        {
            cout << *it << " ";
        }
    }

    cout << root->value << " ";

    if (root->right)
        right_nodes(root);

    return 0;
}