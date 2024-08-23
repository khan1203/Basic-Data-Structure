// by Khan Muhammad Rifat (CSE, BUBT)
#include <bits/stdc++.h>
#define ll long long
#define nl endl
#define PI 2 * acos(0.0)
using namespace std;

void Fast_io()
{
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

class Node
{
public:
    int value;
    Node *left;
    Node *right;
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

Node *input_Btree()
{

    int val;
    cin >> val;
    Node *root = (val == -1) ? nullptr : new Node(val);

    queue<Node *> q;
    if (root)
        q.push(root);

    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        Node *myLeft = (l == -1) ? nullptr : new Node(l);
        Node *myRight = (r == -1) ? nullptr : new Node(r);

        p->left = myLeft;
        p->right = myRight;

        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return root;
}

// void descending_leaf_nodes(Node *root, vector<int> &v)
// {
//     if (root == nullptr)
//         return;
//     queue<Node *> q;
//     q.push(root);

//     while (!q.empty())
//     {
//         // 1. Element take ber kore ana
//         Node *pivot_node = q.front();
//         q.pop();

//         // 2. Jabotiyo kaj ekhane korbo
//         if (pivot_node->left == nullptr && pivot_node->right == nullptr)
//         {
//             // cout << pivot_node->value << " ";
//             v.push_back(pivot_node->value);
//         }

//         // 3. jake ber korlam tar children gulake queue er vetor rekhe dibo
//         if (pivot_node->left)
//             q.push(pivot_node->left);
//         if (pivot_node->right)
//             q.push(pivot_node->right);
//     }
// }

void descending_leaf_nodes(Node *root, vector<int> &v)
{
    if (root == nullptr)
        return;
    
    descending_leaf_nodes(root->left, v);
    
    if (root->left == nullptr && root->right == nullptr)
        v.push_back(root->value);
    
    descending_leaf_nodes(root->right, v);
}

int main()
{

    Node *root = input_Btree();
    vector<int> v;
    descending_leaf_nodes(root, v);

    sort(v.begin(), v.end(), greater<int>());

    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    return 0;
}