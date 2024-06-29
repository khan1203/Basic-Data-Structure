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
    int value;
    Node *next;
    Node(int val) : value(val), next(nullptr) {}
};

int size(Node *head)
{
    Node *temp = head;
    int co = 0;
    while (temp != nullptr)
    {
        co++;
        temp = temp->next;
    }
    return co;
}

void insert_node_at_tail(Node *&head, int val)
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

void insert_node_at_head(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
}

void delete_node_from_index(Node *&head, int index)
{
    if (index < 0 || index >= size(head) || head == nullptr)
    {
        return;
    }

    if (index == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp; // Properly delete the node
        return;
    }

    Node *newNode = head;
    for (int i = 0; i < index - 1; i++)
    {
        newNode = newNode->next;
    }
    Node *targetNode = newNode->next;
    newNode->next = targetNode->next;
    delete targetNode; // Properly delete the node
}

void print_ll(Node *head)
{
    if (head == nullptr)
    {
        cout << "No Node found" << nl;
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
    Fast_io();

    Node *head = nullptr;
    int q;
    cin >> q;
    while (q--)
    {
        int x, v;
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
            delete_node_from_index(head, v);
            print_ll(head);
        }
    }

    return 0;
}