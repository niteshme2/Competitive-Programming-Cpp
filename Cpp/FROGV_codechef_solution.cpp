#include <bits/stdc++.h>
using namespace std;

#define ll              long long int
#define scan(any)       for(auto &i:any) cin>>i;
#define print(any)      for(auto i:any) cout<<i<<" "; 
#define endl            '\n'
#define pb              push_back
#define vll             vector<ll> 
#define f(i,x,y)        for(i=x;i<y;i++)
#define INF             LLONG_MAX
#define s(x)            sort(x.begin(),x.end())
#define all(v)          v.begin(),v.end()
#define p2(n,x)         cout << fixed << setprecision(x) <<n<<endl; 
#define pll             pair<ll,ll> 
#define ff              first
#define ss              second
#define blt(x)          __builtin_popcount(x)
void addedge(vector<ll> adj[],int u,int v)
{
    adj[u].pb(v);
    adj[v].pb(u);
}
void dfs(vll adj[],ll u,vector<bool> &vis,ll j,vll &m)
{
	vis[u]=true;
	ll i;
	m[u]=j;
	f(i,0,(int)adj[u].size())
	{
		if(!vis[adj[u][i]])
		{
			dfs(adj,adj[u][i],vis,j,m);
		}
	}
}
void solve()
{
    ll i,j,k,n,p;
    cin>>n>>k>>p;
    vector<pll> v(n);
    f(i,0,n)
    {
    	cin>>v[i].ff;
    	v[i].ss=i;
    }
    s(v);
    vll adj[n];
    f(i,0,n-1)
    {
    	if(v[i+1].ff-v[i].ff<=k)
    	{
    		addedge(adj,v[i].ss,v[i+1].ss);
    	}
    }
    vll m(n,-1);
    vector<bool> vis(n,false);
    j=0;
    f(i,0,n)
    {
    	if(!vis[i])
    	{
    		j++;
    		dfs(adj,i,vis,j,m);
    	}
    }
    while(p--)
    {
    	cin>>i>>j;
    	i--;
    	j--;
    	if(m[i]==m[j])
    		cout<<"Yes\n";
    	else
    		cout<<"No\n";
    }

}

int main()
{
    #ifdef Sudarshan
        freopen("F:/Programming/input.txt", "r", stdin);
        freopen("F:/Programming/output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll t = 1;
    while(t--) {
        solve();    
    }
    return 0;
}