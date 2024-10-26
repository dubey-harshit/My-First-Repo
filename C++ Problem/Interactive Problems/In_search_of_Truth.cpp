//https://codeforces.com/contest/1840/problem/G2

#define ll long long
#define pb push_back
#define mod 1000000007
#define fr(c,a,b) for(ll c=a;c<b;c++)
#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,ans=1,pns=0;cin>>n;
    map<int,int> m;m[n]=1;
    fr(c,2,1002){
        cout<<'+'<<" "<<1<<endl;
        cout<<endl;
        int x;cin>>x;
        m[x]+=c;
        if(m[x]>c){
            cout<<'!'<<" "<<ans<<endl;
            cout<<endl;
            return;
        }
        ans++;
    }int x=0;
    while(m[x]<=pns){
        cout<<'+'<<" "<<1000<<endl;
        cout<<endl;
        cin>>x;
        pns+=1000;
        m[x]+=pns;
        if(m[x]>pns){
            cout<<'!'<<" "<<ans+pns-(m[x]-pns)<<endl;
            cout<<endl;
            return;
        }
        
        
        
    }
    
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