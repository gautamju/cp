/*
problem link: https://codeforces.com/gym/100571/problem/B
f(i) = a*f(i-2) + b*f(i-1);
---> calculate f(i) from 1 to n+1, f(0) = 0
---> think about how can we add f(1) and f(2) to p(l) and p(l+1)
---> think about how can we remove weight of this from p(r+1) and p(r+2)
if during calculation we do p(i) = a*p(i-2) + b*p(i-1);
=> p(l) = p(l) + f(1);
=> p(l+1) = p(l+1) + f(2);
so here we can simply see that if we do p(l+1) = p(l+1) + a*p(l-1) + b*p(l) 
then as p(l-1) is having zero impact whereas p(l) is having impact of b*f(1)
so we can write p(l+1) = p(l+1) - b*f(1);
similarly as p(r+1) = p(r+1) + a*p(r-1) + b*p(r), total impact will be f(r+1);
so p(r+1) = p(r+1) - f(r+1);
similarly p(r+2) = p(r+2) + a*p(r) + b*p(r+1), as b*p(r+1) will be having zero impact
so p(r+2) = p(r+2) - a*p(r);
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int  mod = 1000000007;
int sumf(int a, int b, bool ismod = false)
{
	if(ismod)
	{
		if(a<0) a = (a+mod)%mod;
		if(b<0) b = (b+mod)%mod;
		return ((a%mod + b%mod)%mod);
	} 
	return a+b;
}
int prof(int a, int b, bool ismod = false)
{
	if(ismod)
	{
		if(a<0) a = (a+mod)%mod;
		if(b<0) b = (b+mod)%mod;
		return ((a%mod * b%mod)%mod);
	} 
	return a*b;
}
void GkSoln()
{
	int32_t n, q;
	int f1, f2, a, b;
	cin>>n>>q>>f1>>f2>>a>>b;
	int ff[n+3], arr[n+3], freq[n+3] = {0};
	ff[0] = 0; ff[1] = f1; ff[2] = f2;
	for(int32_t i=1;i<=n;i++) cin>>arr[i];
	for(int32_t i=3;i<=n+2;i++) ff[i] = sumf(prof(a, ff[i-2], true) , prof(b, ff[i-1], true), true);

	while(q--)
	{
		int32_t l,r; 
		cin>>l>>r;
		if(l<r)
		{
			freq[l] = sumf(freq[l], ff[1], true);
			freq[l+1] = sumf((sumf(freq[l+1], ff[2], true)), (prof(-b, ff[1], true)), true);
			freq[r+1] = sumf(freq[r+1], -ff[r-l + 2], true);
			freq[r+2] = sumf(freq[r+2], (prof(-a, ff[r-l + 1], true)), true);
		}
		else
		{
			freq[l] = sumf(freq[l], ff[1], true);
			freq[r+1] = sumf(freq[r+1], (prof(-b, ff[1], true)), true);
			freq[r+2] = sumf(freq[r+2], (prof(-a, ff[1], true)), true);
		}
		
	}

	int sump = 0;
	arr[1] = sumf(arr[1], freq[1], true);
	for(int32_t i=2;i<=n;i++)
	{
		int p = sumf(prof(a, freq[i-2], true) , prof(b, freq[i-1], true), true);
		freq[i] = sumf(p, freq[i], true);
		arr[i] = sumf(arr[i], freq[i], true);
	}
	for(int32_t i=1;i<=n;i++)
	{
		cout<<arr[i]<<" ";
	}
}

int32_t main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    clock_t stime = clock();
    int32_t t=1;
    // cin>>t;

    for(int32_t i=1;i<=t;i++)
    {
        GkSoln();
    }

    clock_t etime = clock();

    cerr<<"Run Time : "<<((double)(etime-stime)/ CLOCKS_PER_SEC);

    return 0;

}