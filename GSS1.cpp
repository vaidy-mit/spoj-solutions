#include<bits/stdc++.h>
#define MAXN 500005
using namespace std;

struct data
{
	int sum;
	int pref;
	int suff;
	int ans;	
};

data t[4*MAXN];

data combine(data l,data r)
{
	data temp;
	temp.sum=l.sum+r.sum;
	temp.pref=max(l.pref,l.sum+r.pref);
	temp.suff=max(r.suff,r.sum+l.suff);
	temp.ans=max(max(l.ans,r.ans),l.suff+r.pref);
	return temp;
}

data make_data(int val)
{
	data res;
	res.sum=val;
	res.ans=res.pref=res.suff=val;
	return res;
}

void build(int *a,int v,int tl,int tr)
{
	if(tl==tr)
		t[v]=make_data(a[tl]);
	else
	{
		int tm=(tl+tr)/2;
		build(a,v*2,tl,tm);
		build(a,v*2+1,tm+1,tr);
		t[v]=combine(t[v*2],t[v*2+1]);
	}
}

data query (int v, int tl, int tr, int l, int r) {
	if (l == tl && tr == r)
		return t[v];
	int tm = (tl + tr) / 2;
	if (r <= tm)
		return query (v*2, tl, tm, l, r);
	if (l > tm)
		return query (v*2+1, tm+1, tr, l, r);
	return combine (
		query (v*2, tl, tm, l, tm),
		query (v*2+1, tm+1, tr, tm+1, r)
	);
}


int main()
{
	int n,i,*a,m,index1,index2;
	scanf("%d",&n);
	a=new int[n+5];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	build(a,1,0,n-1);
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&index1,&index2);
		printf("%d\n",query(1,0,n-1,index1-1,index2-1).ans);
	}
	return 0;
}
