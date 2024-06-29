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
    Node(int val) : value(val), next(NULL) {}
};

int input_linked_list(Node *&head, Node *&tail)
{
    int val, size = 0;
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
            size++;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            size++;
        }
    }
    return size;
}

// void delete_duplicate(Node *head)
// {
//     for (Node *temp = head; temp != nullptr; temp = temp->next)
//     {
//         for (Node *curr = temp; curr->next != nullptr; curr = curr->next)
//         {
//             if(temp->value==curr->next->value){
//                 Node* targetNode = curr->next;
//                 curr->next=targetNode->next;
//                 delete targetNode;
//             }
//         }
//     }
// }

void delete_duplicate(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        Node* run = curr;
        while (run->next != nullptr) {
            if (run->next->value == curr->value) {
                Node* temp = run->next;
                run->next = run->next->next;
                delete temp;
            } else {
                run = run->next;
            }
        }
        curr = curr->next;
    }
}

void print_linked_list(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << nl;
}

int main()
{
    // Fast_io();
    Node* head = nullptr;
    Node* tail = nullptr;
    input_linked_list(head, tail);

    delete_duplicate(head);
    print_linked_list(head);

    return 0;
}