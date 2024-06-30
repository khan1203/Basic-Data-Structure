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
    int value;
    Node *next;
    Node *prev;
    Node(int val) : value(val), next(nullptr), prev(nullptr) {}
};

ll size(Node *head)
{
    Node *tmp = head;
    ll cnt = 0;
    while (tmp != nullptr)
    {
        cnt++;
        tmp = tmp->next;
    }
    return cnt;
}

// Insertion Operations --------------------------------------
void insert_head(Node *&head, Node *&tail, ll val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    head->prev = newNode;
    newNode->next = head;
    head = head->prev;
}

void insert_tail(Node *&head, Node *&tail, ll val)
{
    Node *newNode = new Node(val);
    if (tail == nullptr)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = tail->next;
}

void insert_any_position(Node *&head, Node *&tail, ll pos, ll val)
{
    Node *newNode = new Node(val);
    ll len = size(head);

    if (pos == 0)
    {
        insert_head(head, tail, val);
    }
    else if (pos == len)
    {
        insert_tail(head, tail, val);
    }
    else if (pos > len || pos < 0)
    {
        cout << "Invalid Index" << nl;
    }
    else
    {
        Node *temp = head;
        for (ll i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;
        newNode->next->prev = newNode;
    }
}

// Deletion Operations ----------------------------------

void delete_head(Node *&head)
{
    Node *targetNode = head;
    head = head->next;
    head->prev = nullptr;
    delete targetNode;
}

void delete_tail(Node *&tail)
{
    Node *targetNode = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete targetNode;
}

void delete_any_position(Node *&head, Node *&tail, ll pos)
{
    ll len = size(head);
    if (pos < 0 || pos > len)
    {
        cout << "Invalid index" << nl;
        return;
    }
    else if (pos == 0)
    {
        delete_head(head);
        return;
    }
    else if (pos == size(head))
    {
        delete_tail(tail);
        return;
    }
    else
    {
        Node *tmp = head;
        for (ll i = 0; i < pos - 1; i++)
        {
            tmp = tmp->next;
        }
        Node *targetNode = tmp->next;
        tmp->next = targetNode->next;
        tmp->next->prev = tmp;
        delete targetNode;
    }
}

// Print functions---------------------------------
void print_normal(Node *head)
{
    if (head == nullptr)
    {
        cout << "List is empty" << nl;
        return;
    }

    Node *tmp = head;
    while (tmp != nullptr)
    {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
    cout << nl;
}

void print_reverse(Node *tail)
{
    if (tail == nullptr)
    {
        cout << "List is empty" << nl;
        return;
    }
    Node *tmp = tail;
    while (tmp != nullptr)
    {
        cout << tmp->value << " ";
        tmp = tmp->prev;
    }
    cout << nl;
}

int main()
{
    // Fast_io();
    // Nodes------------------
    Node *head = nullptr;
    Node *tail = head;
    // Node *a = new Node(20);
    // Node *b = new Node(30);
    // Node *tail = new Node(40);

    // Connections-------------
    // head->next = a;
    // a->next = b;
    // b->next = tail;
    // tail->prev = b;
    // b->prev = a;
    // a->prev = head;

    // Operations---------------
    while (true)
    {
        cout << "+---------------------------------------+" << nl;
        cout << "\tDoubly Linked List Operation" << nl;
        cout << "+---------------------------------------+" << nl;
        cout << "1: Insert Doubly List" << nl;
        cout << "2: Insert head" << nl;
        cout << "3: Insert tail" << nl;
        cout << "4: Insert any node" << nl;
        cout << "5: Delete any node" << nl;
        cout << "6: Print List" << nl;
        cout << "0: Terminate" << nl << nl;
        cout << "Select any option: ";

        int op;
        cin >> op;
        if (op == 1)
        {
            ll val;
            cout << "Enter values: ";
            while (1)
            {
                cin >> val;
                if (val == -1)
                {
                    break;
                }
                else
                {
                    insert_tail(head, tail, val);
                }
            }
            print_normal(head);
        }
        else if (op == 2)
        {
            int val;
            cout << "Enter value: ";
            cin >> val;
            insert_head(head, tail, val);
            print_normal(head);
        }
        else if (op == 3)
        {
            int val;
            cout << "Enter value: ";
            cin >> val;
            insert_tail(head, tail, val);
            print_normal(head);
        }
        else if (op == 4)
        {
            ll pos, val;
            cout << "Enter Position: ";
            cin >> pos;
            cout << "Enter Value: ";
            cin >> val;
            insert_any_position(head, tail, pos, val);
            print_normal(head);
        }
        else if (op == 5)
        {
            ll pos;
            cout << "Enter Position: ";
            cin >> pos;
            delete_any_position(head, tail, pos);
            print_normal(head);
        }
        else if (op == 6)
        {
            cout << "Normal Sequence: ";
            print_normal(head);
            cout << "Reverse Sequence: ";
            print_reverse(tail);
        }
        else if (op == 0)
        {
            break;
        }
    }

    return 0;
}