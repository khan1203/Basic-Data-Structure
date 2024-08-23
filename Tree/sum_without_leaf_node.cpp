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

void count_sum(Node *root, int &sum)
{
    if (root == nullptr)
        return;

    if (root->left != nullptr || root->right != nullptr)
    {
        sum += root->value;
        // return;
    }

    count_sum(root->left, sum);
    count_sum(root->right, sum);
    return;
}

int main()
{
    Node *root = input_Btree();
    int sum = 0;
    count_sum(root, sum);

    cout<<sum<<nl;

    return 0;
}