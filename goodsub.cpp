#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define lint long long int 

int main()
{
	lint n, k, x, i, j, res=0;
	cin>>n>>k;
	map <int, int> m;
	for(i=0;i<n;i++)
	{
		cin>>x;
		m[x]++;
	}
	lint sz = m.size();
	vector<long long int > v;
    	v.push_back(0);
	for(auto it = m.begin(); it != m.end(); it++)
		v.push_back(it->second);
	
	//k = max(k,1008)
	long long int dp[1010][1010];
	
	for(i=0;i<=sz;i++)
		for(j=0 ; j<=sz ; j++)
			dp[i][j] = 0;
	
	for(j=0;j<=sz;j++)
		dp[0][j] = 1;

	for(i=1;i<=sz;i++)
		for(j=i;j<=sz;j++)	
		{
			dp[i][j] = (dp[i-1][j-1]*v[j])%mod;
			dp[i][j] = (dp[i][j] + dp[i][j-1])%mod;
		}
	/*
	for(i=0;i<=sz;i++)
	{
		for(j=0;j<=sz;j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	*/
	if(k<=sz)
	{
		for(i=0;i<=k;i++)
			res = (res + dp[i][sz])%mod;
		cout<<res<<endl;
	}
	else 
		cout<<"-1\n";
	return 0;
}
