// https://codeforces.com/problemset/problem/1807/E

#define ll long long
#define pb push_back
#define mod 1000000007
#define fr(c,a,b) for(ll c=a;c<b;c++)
#include<bits/stdc++.h>
using namespace std;

void solve()
{
    ll n;cin>>n;
    ll krr[n+1];
    ll arr[n+1];
    fr(c,1,n+1){
        cin>>arr[c];
        krr[c]=arr[c];
    }arr[0]=0;
    fr(c,2,n+1){
        arr[c]+=arr[c-1];
    }int x;
    ll start = 0, end = n;
    while(start<end){
        ll mid = (start+end)/2;
        cout<<'?'<<" "<<mid<<" ";
        fr(c,start+1,mid+1){
            cout<<krr[c]<<" ";
        }cout<<endl;cout<<endl;
        cout<<flush;
        cin>>x;
        if(arr[mid]-arr[start]==x){
            start=mid+1;
        }else{
            end=mid;
        }
    }cout<<'!'<<" "<<start<<endl;
    cout<<flush;
    return;
    
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        solve();
    }
}