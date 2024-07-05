//by Khan Muhammad Rifat (CSE, BUBT)
#include <bits/stdc++.h>
#define ll long long
#define nl endl
#define PI 2*acos(0.0)
using namespace std;

int main(){
    list<int> myList;

    while(1){
        int val;
        cin>>val;
        if(val==-1){
            break;
        }
        myList.push_back(val);
    }

    myList.sort();
    myList.unique();

    
    for(auto val : myList){
        cout<<val<<" ";
    }
   
return 0;
}