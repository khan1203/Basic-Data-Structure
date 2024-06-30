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

// Class -----------------------
class Node
{
public:
    int value;
    Node *next;
    Node(int val) : value(val), next(NULL) {}
};

// Functions ------------------------
int input_linked_list(Node *&head, Node *&tail)
{
    int val, co = 0, max = INT_MIN, min = INT_MAX;
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
            int newVal = newNode->value;
            (newVal > max) ? max = newVal : max;
            (newVal < min) ? min = newVal : min;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            int newVal = newNode->value;
            (newVal > max) ? max = newVal : max;
            (newVal < min) ? min = newVal : min;
        }
    }
    int diff = max - min;
    return diff;
}

int main()
{
    Fast_io();
    Node *head = NULL;
    Node *tail = NULL;
    cout<<input_linked_list(head, tail)<<nl;

    return 0;
}