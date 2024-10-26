#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,k,i,c,z,y;
    cin>>t;
    
    while(t--)
    {
        c=0;
        y=0;
        cin>>k;
        i=k;


        vector<int>vc;
        while(i!=0)
        {
            int r=i%10;
            if(r!=0)
            y++;
            vc.push_back(r);
            i=i/10;
        }
        // j=k;
        cout<<y<<endl;
        for(int i=0;i<vc.size();i++)
        {
            if(vc[i]==0)
            continue;
            else
            {
               int j=pow(10.0,(double)i);
                // cout<<j<<" ";
                cout<<vc[i]*j<<" ";
            }
        }
        cout<<endl;
    }
}
