// by Khan Muhammad Rifat (CSE, BUBT)
#include <bits/stdc++.h>
#define ll long long
#define nl endl
#define PI 2 * acos(0.0)
using namespace std;

void Fast_io()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
}

int main()
{
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        pq.push(val);
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << pq.top() << " ";
    //     pq.pop();
    // }

    int q;
    cin >> q;
    while (q--)
    {
        int opt;
        cin >> opt;

        if (opt == 0)
        {
            int x;
            cin >> x;
            pq.push(x);

            cout << pq.top() << endl;
        }
        else if (opt == 1)
        {
            if (!pq.empty())
                cout << pq.top() << endl;
            else
                cout << "Empty" << endl;
        }
        else if (opt == 2)
        {
            if (!pq.empty())
            {
                pq.pop();
                if (!pq.empty())
                    cout << pq.top() << endl;
                else
                    cout << "Empty" << endl;
            }
            else
                cout << "Empty" << endl;
        }
    }
    return 0;
}