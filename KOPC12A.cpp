#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll c[10005];
ll h[10005];

ll costf(ll hnew,ll n)
{
	ll i,sum=0;
	
	for(i=0;i<n;i++)
	{
		sum+=(abs(h[i]-hnew)*c[i]);
	}
	return sum;
}


int main()
{
	ll t,i,n,low,high,mid1,mid2,ans,val;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		low=0;
		high=100000;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&h[i]);
		}
		for(i=0;i<n;i++)
			scanf("%lld",&c[i]);
		while(low<=high)
		{
			mid1=low+(high-low)/3;
			mid2=mid1+(high-low)/3;
			if(costf(mid1,n)<costf(mid2,n))
			{
				high=mid2-1;
				ans=mid1;
			}
			else
			{
				low=mid1+1;
				ans=mid2;	
			}
		}
		val=costf(ans,n);
		val=min(val,costf(ans+1,n));
		val=min(val,costf(ans-1,n));
		printf("%lld\n",val);
	}
	return 0;
}
