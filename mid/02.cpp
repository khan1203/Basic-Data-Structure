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
    Node *next;
    Node *prev;
    Node(int val) : value(val), next(NULL), prev(nullptr) {}
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

bool isPalindrome(Node *head, Node *tail)
{
    if (head == nullptr)
    {
        return false;
    }

    Node *front = head;
    Node *back = tail;

    while (front != back && back->next != front)
    {
        if (front->value != back->value)
        {
            return false;
        }
        front = front->next;
        back = back->prev;
    }
    return true;
}

int main()
{
    Node *head = nullptr;
    Node *tail = head;

    while (1)
    {
        int val;
        cin >> val;
        if (val == -1)
        {
            break;
        }
        insert_tail(head, tail, val);
    }

    if (isPalindrome(head, tail))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    // print_normal(head);

    return 0;
}