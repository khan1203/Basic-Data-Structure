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
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
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
        // 1. ber kore anbo
        Node *p = q.front();
        q.pop();

        // 2. Jabotiyo kaj korbo
        int l, r;
        cin >> l >> r;

        Node *myLeft = (l == -1) ? NULL : new Node(l);
        Node *myRight = (r == -1) ? NULL : new Node(r);

        p->left = myLeft;
        p->right = myRight;

        // 3. children gulake push korbo
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return root;
}

void level_order(Node *root)
{
    if (root == NULL)
    {
        cout << "Tree nai" << endl;
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();

        cout << f->val << " ";

        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
}

int main()
{

    Node *root = input_Btree();
    cout<<endl;
    level_order(root);
    return 0;
}
