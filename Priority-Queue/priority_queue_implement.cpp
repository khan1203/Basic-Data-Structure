// by Khan Muhammad Rifat (CSE, BUBT)
#include <bits/stdc++.h>
#define ll long long
#define nl endl
#define PI 2 * acos(0.0)
using namespace std;

int main()
{
    priority_queue<int> pq;

    while (1)
    {
        int opt;
        cin >> opt;

        if (opt == 1)
        {
            int x;
            cin >> x;
            pq.push(x);
        }
        else if (opt == 2)
        {
            pq.pop();
        }
        else if (opt == 3)
        {
            cout<<pq.top()<<endl;
        }
        else if(opt == 4){
            break;
        }
    }
    return 0;
}