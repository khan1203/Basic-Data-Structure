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

void printList(const list<int> & dll)
{
    cout << "L -> ";
    for (const auto& it : dll)
    {
        cout << it << " ";
    }
    cout << nl;

    cout << "R -> ";
    for (auto it = dll.rbegin(); it != dll.rend(); ++it)
    {
        cout << *it << " ";
    }
    cout << nl;
}

int main()
{
    Fast_io();

    list<int> dll;

    int q;
    cin >> q;
    while (q--)
    {
        int x, v;
        cin >> x >> v;

        if (x == 0)
        {
            dll.push_front(v);
        }
        else if (x == 1)
        {
            dll.push_back(v);
        }
        else if (x == 2)
        {
            int len = dll.size();
            if (v >= 0 && v < len)
            {
                auto it = next(dll.begin(), v);
                dll.erase(it);
            }
        }

        printList(dll);
    }
    return 0;
}
