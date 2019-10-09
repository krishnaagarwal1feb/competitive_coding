#include <bits/stdc++.h>
#define ll long long int  
using namespace std;
int main()
{
    ll n,k,h[8001],x,ans=0,i,j,u=1000000007,p;
    cin>>n>>k;
    
    k=min(k,8000ll);
    
    ll arr[k+1];
    memset(arr, 0, sizeof(arr));
    memset(h, 0, sizeof(h));
    
    for(i=0;i<n;++i)
    {	cin>>x;
        ++h[x];
    }
    arr[0]=1;
    for(i=0;i<8001;i++)
    {
        if(h[i]!=0)
        {
        for(j=k;j>=1;j--)
            {
            	p=(arr[j-1]%u*h[i]%u)%u;
                arr[j] = (arr[j]%u + p)%u;
            }
        }
    }
    for(i=0;i<=k;i++)
        ans=(arr[i]%u+ans%u)%u;
    cout<<ans<<endl;
 
    return 0;
}
