// by Khan Muhammad Rifat (CSE, BUBT)
#include <bits/stdc++.h>
#define ll long long
#define nl endl
#define PI 2 * acos(0.0)
using namespace std;

// Class -----------------------
class Node
{
public:
    int value;
    Node *next;
    Node(int val) : value(val), next(NULL) {}
};

// Functions ------------------------
void input_linked_list(Node *&head, Node *&tail)
{
    int val, co = 0;
    while (1)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
}

void print_reverse(Node *n)
{
    if (n == NULL)
    {
        return;
    }
    print_reverse(n->next);
    cout << n->value << " ";
}

int main()
{
    // Fast_io();
    Node *head1 = NULL;
    Node *tail1 = NULL;

    input_linked_list(head1, tail1);
    print_reverse(head1);
    return 0;
}