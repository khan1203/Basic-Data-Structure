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

class Person
{
public:
    string name;
    int id;
    Person(string name, int id)
    {
        this->name = name;
        this->id = id;
    }
};

class cmp
{
public:
    bool operator()(Person a, Person b)
    {
        if (a.name > b.name)
        {
            return true;
        }
        else if (a.name < b.name)
        {
            return false;
        }
        else
        {
            if (a.id < b.id)
            {
                return true;
            }
            else
                return false;
        }
    }
};

int main()
{
    Fast_io();
    int n;
    cin >> n;
    priority_queue<Person, vector<Person>, cmp> pq;

    for (int i = 0; i < n; i++)
    {
        string name;
        int id;
        cin >> name >> id;

        Person obj({name, id});
        pq.push(obj);
    }

    while (!pq.empty())
    {
        cout << pq.top().name << " " << pq.top().id << "\n";
        pq.pop();
    }

    return 0;
}