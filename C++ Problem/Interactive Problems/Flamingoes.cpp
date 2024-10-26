//https://codeforces.com/problemset/problem/1425/F

#define ll long long
#define pb push_back
#define mod 1000000007
#define fr(c,a,b) for(ll c=a;c<b;c++)
#include<bits/stdc++.h>
using namespace std;

void solve()
{
    ll n,y=1;cin>>n;
    vector<ll> v;
    fr(c,1,n){
        cout<<'?'<<" "<<c<<" "<<c+1<<endl;
        cout<<flush;
        cout<<endl;
        ll x;cin>>x;
        v.pb(x);
    }
    cout<<'!'<<" ";
    fr(c,0,v.size()){
        cout<<v[c]<<" ";
    }cout<<endl;cout<<endl;
    cout<<flush;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    while(t--)
    {
        solve();
    }
}