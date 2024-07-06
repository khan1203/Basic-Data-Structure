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
    string data;
    Node *next;
    Node *prev;
    Node(string str) : data(str), next(NULL), prev(NULL) {}
};

class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;
    Node *curr;

    DoublyLinkedList() : head(nullptr), tail(nullptr), curr(nullptr) {}

    void insert(string &str)
    {
        Node *newNode = new Node(str);
        if (head == nullptr)
        {
            head = tail = curr = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void visit(string address)
    {
        Node *temp = head;
        while (temp)
        {
            if (temp->data == address)
            {
                curr = temp;
                cout << curr->data << nl;
                return;
            }
            temp = temp->next;
        }
        cout << "Not Available" << nl;
    }

    void next()
    {
        if (curr->next == nullptr)
        {
            cout << "Not Available" << nl;
        }
        else
        {
            curr = curr->next;
            cout << curr->data << nl;
        }
    }

    void prev()
    {
        if (curr->prev == nullptr)
        {
            cout << "Not Available" << nl;
        }
        else
        {
            curr = curr->prev;
            cout << curr->data << nl;
        }
    }
};

int main()
{
    DoublyLinkedList dll;

    while (1)
    {
        string add;
        cin >> add;
        if (add == "end")
        {
            break;
        }
        dll.insert(add);
    }

    // Node* temp2 = dll.head;
    // while(temp2 != nullptr){
    //     cout<<temp2->data<<" ";
    //     temp2 = temp2->next;
    // }

    int q;
    cin >> q;

    while (q--)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "visit")
        {
            string address;
            cin >> address;
            dll.visit(address);
        }
        else if (cmd == "next")
        {
            dll.next();
        }
        else if (cmd == "prev")
        {
            dll.prev();
        }
    }
}