// Print only the nodes of the given level
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

    queue<pair<Node *, int>> q;
    if (root)
        q.push({root, 0});

    while (!q.empty())
    {
        pair<Node *, int> pr = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        Node *myLeft = (l == -1) ? NULL : new Node(l);
        Node *myRight = (r == -1) ? NULL : new Node(r);

        Node *node = pr.first;
        int level = pr.second;

        node->left = myLeft;
        node->right = myRight;

        if (node->left)
            q.push({node->left, level + 1});
        if (node->right)
            q.push({node->right, level + 1});
    }
    return root;
}

int maxDepth(Node *root)
{
    if (root == nullptr)
        return 0;

    int l = maxDepth(root->left);
    int r = maxDepth(root->right);

    return max(l, r) + 1;
}

void level_nodes(Node *root, int x)
{
    if (x >= maxDepth(root))
    {
        cout << "Invalid" << nl;
        return;
    }

    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        pair<Node *, int> pr = q.front();
        q.pop();

        Node *node = pr.first;
        int level = pr.second;

        if (level == x)
            cout << node->value << " ";

        if (node->left)
            q.push({node->left, level + 1});
        if (node->right)
            q.push({node->right, level + 1});
    }
}

int main()
{
    Node *root = input_Btree();

    int x;
    cin >> x;
    level_nodes(root, x);

    return 0;
}