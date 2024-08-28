// by Khan Muhammad Rifat (CSE, BUBT)
#include <bits/stdc++.h>
#define ll long long
#define nl endl
#define PI 2 * acos(0.0)
using namespace std;

int main()
{
    priority_queue<int> pq;                             // ->  this is for max-heap (Descending order)
    priority_queue<int, vector<int>, greater<int>> pq2; // ->  this is for min-heap (Ascending order)

    while (1)
    {
        int opt;
        cin >> opt;

        if (opt == 1)
        {
            int x;
            cin >> x;
            pq.push(x); // O(logN)
        }
        else if (opt == 2)
        {
            pq.pop(); // O(logN)
        }
        else if (opt == 3)
        {
            cout << pq.top() << endl; // O(1)
        }
        else if (opt == 4)
        {
            break;
        }
    }
    return 0;
}