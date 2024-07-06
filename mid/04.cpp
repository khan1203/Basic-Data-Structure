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

class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

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
        }
        else
        {
            head->prev = newNode;
            newNode->next = head;
            head = head->prev;
        }
    }

    void insert_tail(Node *&head, Node *&tail, ll val)
    {
        Node *newNode = new Node(val);
        if (tail == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = tail->next;
        }
    }

    void insert_any_position(ll pos, ll val)
    {
        Node *newNode = new Node(val);
        ll len = size(head);

        if (pos == 0)
        {
            insert_head(head, tail, val);
            print_normal();
            print_reverse();
        }
        // else if (pos == 1)
        // {
        //     newNode->next = head->next;
        //     head->next = newNode;
        //     newNode->prev = head;
        //     newNode->next->prev = newNode;
        // }
        else if (pos == len)
        {
            insert_tail(head, tail, val);
            print_normal();
            print_reverse();
        }
        else if (pos > len || pos < 0)
        {
            cout << "Invalid" << nl;
        }
        else
        {
            Node *temp = head;
            for (ll i = 0; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            newNode->next->prev = newNode;
            newNode->prev = temp;
            print_normal();
            print_reverse();
        }
    }

    // Print functions---------------------------------
    void print_normal()
    {
        if (head == nullptr)
        {
            // cout << "List is empty" << nl;
            return;
        }

        Node *tmp = head;
        cout << "L -> ";
        while (tmp != nullptr)
        {
            cout << tmp->value << " ";
            tmp = tmp->next;
        }
        cout << nl;
    }

    void print_reverse()
    {
        if (tail == nullptr)
        {
            // cout << "List is empty" << nl;
            return;
        }
        Node *tmp = tail;
        cout << "R -> ";
        while (tmp != nullptr)
        {
            cout << tmp->value << " ";
            tmp = tmp->prev;
        }
        cout << nl;
    }
};

int main()
{
    // DoublyLinkedList------------------
    DoublyLinkedList dll;

    // Operations---------------
    int q;
    cin >> q;
    while (q--)
    {
        ll x, v;
        cin >> x >> v;

        dll.insert_any_position(x, v);
    }

    return 0;
}