#define ll long long
#define pb push_back
#define mod 1000000007
#define fr(c,a,b) for(ll c=a;c<b;c++)
#include<bits/stdc++.h>
using namespace std;

class A {
    public:
    void fun(){
        cout<<" yeah boi";
    }
}
class B : public A {     // Inheriting protected and public members and func in public of B
    public:
    void holo {
        cout<<"Hoi boi";
    }
}       // Now we can access data members of A in B also 

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        solve();
    }
}