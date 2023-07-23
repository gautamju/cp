#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define F first
#define S second
#define pb push_back
#define pii pair<int,int>
#define ppi pair<pii, int>
#define pip pair<int, pii>
#define vi vector<int>
#define vpii vector<pii>
#define vpip vector<pip>
#define vppi vector<ppi>
#define bug(...) __f (#__VA_ARGS__, __VA_ARGS__)

inline int power(int a, int b)
{
    int x=1;
    while (b)
    {
        if(b&1) x*=a;
        b*=a;
        b >>= 1;
    }
    return x;
}

void GkSoln()
{
    int n;
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
    int t=1;
    // cin>>t;

    for(int i=1;i<=t;i++)
    {
        GkSoln();
    }

    clock_t etime = clock();

    cerr<<"Run Time : "<<((double)(etime-stime)/ CLOCKS_PER_SEC);

    return 0;

}