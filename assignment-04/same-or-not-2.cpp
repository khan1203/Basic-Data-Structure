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

class myStack
{
public:
    vector<int> v;

    void push(int val)
    {
        v.push_back(val);
    }

    void pop()
    {
        v.pop_back();
    }

    int top()
    {
        return v.back();
    }

    int size()
    {
        return v.size();
    }

    bool empty()
    {
        return v.empty();
    }
};

class myQueue
{
public:
    list<int> v;

    void push(int val)
    {
        v.push_back(val);
    }

    void pop()
    {
        v.pop_front();
    }

    int front()
    {
        return v.front();
    }

    int size()
    {
        return v.size();
    }

    bool empty()
    {
        return v.empty();
    }
};

int main()
{
    Fast_io();
    int n, m;
    cin >> n >> m;
    if (n == m)
    {
        myStack s;
        while (n--)
        {
            int x;
            cin >> x;
            s.push(x);
        }
        myQueue q;
        while (m--)
        {
            int x;
            cin >> x;
            q.push(x);
        }

        while (!s.empty())
        {
            if (!s.empty() && !q.empty() && s.top() == q.front())
            {
                s.pop();
                q.pop();
            }
            else
            {
                cout << "NO\n";
                return 0;
            }
        }
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}