// by Khan Muhammad Rifat (CSE, BUBT)
#include <bits/stdc++.h>
#define ll long long
#define nl endl
#define PI 2 * acos(0.0)
using namespace std;

void Fast_io()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
}

class Node
{
public:
    ll value;
    Node *next;
    Node(ll val) : value(val), next(NULL) {}
};

void insert_node_at_tail(Node *&head, ll val)
{
    Node *newNode = new Node(val);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insert_node_at_head(Node *&head, ll val)
{
    Node *newNode = new Node(val);
    // if (head == nullptr)
    // {
    //     head = newNode;
    //     return;
    // }

    newNode->next = head;
    head = newNode;
}

void delete_node(Node *&head, int pos)
{
    if (head == NULL || pos < 0)
        return;
    if (pos == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node *current = head;
    for (int i = 0; i < pos - 1 && current != NULL; ++i)
    {
        current = current->next;
    }
    if (current == NULL || current->next == NULL)
        return;
    Node *temp = current->next;
    current->next = current->next->next;
    delete temp;
}

void print_ll(Node *head)
{
    if (head == nullptr)
    {
        // cout << "No Node found" << nl;
        return;
    }
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << nl;
}

int main()
{
    // Fast_io();

    Node *head = NULL;
    int q;
    cin >> q;
    while (q--)
    {
        ll x, v;
        cin >> x >> v;
        if (x == 0)
        {
            insert_node_at_head(head, v);
            print_ll(head);
        }
        else if (x == 1)
        {
            insert_node_at_tail(head, v);
            print_ll(head);
        }
        else if (x == 2)
        {
            delete_node(head, v);
            print_ll(head);
        }
    }

    return 0;
}