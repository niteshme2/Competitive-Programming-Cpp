#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
#define ll long long int
#define ar array
#define ld long double
#define bigint int64_t
#define vll vector<ll>
#define pll ar<ll,2> 
#define vpll vector<pll>
#define pb push_back
#define sz(x) (int)(x).size()
#define ff first
#define ss second
#define ok order_of_key
#define fo find_by_order
#define en cout<<"\n"
#define LCM(a,b) (a*(b/__gcd(a,b)))
#define all(v) v.begin(),v.end()
#define maxqueue    priority_queue<int>
#define minqueue    priority_queue<int,vector<int>,greater<int> >
#define lb(v,val)  (lower_bound(v.begin(),v.end(),val)-v.begin())
#define ub(v,val)  (upper_bound(v.begin(),v.end(),val)-v.begin())
#define INF (ll) 1e18
#define NEGINF -INF
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define ini(a,b) memset(a,b,sizeof(a))
#define vvll vector<vector<ll>>
#define vt vector
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MEM(a, b) memset(a, b, sizeof(a))
#define MAXN (int)(1 * 1e6 + 10)
#define prec(n) fixed<<setprecision(n)
#define each(x, a) for (auto& x: a)
#define F_OR(i, a, b, s) for (ll i = (a); ((s) > 0 ? i < (b) : i > (b)); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define forn(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define pi 3.141592653589793238
const int MOD=1e9+7;

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using mset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k) : iterator to value at kth index in sorted array. 
// order_of_key(k) : Index of the value k

template <typename T>
void read(T &x) {
    cin >> x;
}
template <typename T , typename T0>
void read(T &x, T0 &y) {
    cin >> x >> y;
}

template <typename T , typename T0 , typename T1>
void read(T &x, T0 &y, T1 &z) {
    cin >> x >> y >> z;
}

template <typename T , typename T0 , typename T1 , typename T2>
void read(T &x, T0 &y, T1 &z, T2 &w) {
    cin >> x >> y >> z >> w;
}

template <typename T>
void read(vector< T > &oneD) {
    for (ll i = 0; i < sz(oneD); i++) {
        read(oneD[i]);
    }

}

template <typename T>
void read(T oneD[] , ll n) {
    for (ll i = 0; i < n; i++) {
        read(oneD[i]);
    }
}
template <typename T>
void write(T &x) {

    cout << x << " ";
}

template <typename T>
void write(vector< T > &oneD) {
    for (ll i = 0; i < sz(oneD); i++) {
        write(oneD[i]);
    }
    cout << endl;
}

template <typename T>
void write(T oneD[] , int n) {
    for (ll i = 0; i < n; i++) {
        write(oneD[i]);
    }
    cout << endl;
}

template <typename T> inline bool umax(T &x, T y) {return (y > x) ? x = y, true : false;}
template <typename T> inline bool umin(T &x, T y) {return (y < x) ? x = y, true : false;}


template<class T> void offset(ll o, T& x) {
    x+=o;
}
template<class T> void offset(ll o, vector<T>& x) {
    each(a, x)
        offset(o, a);
}
template<class T, size_t S> void offset(ll o, ar<T, S>& x) {
    each(a, x)
        offset(o, a);
}

template<size_t S> string to_string(bitset<S> b) {
    string res;
    forn(S)
        res+=char('0'+b[i]);
    return res;
}
string to_string(bool b) {
    return b?"true":"false";
}

inline bool isSquare(ll x)
{
    ll s = sqrt(x);
    return (s * s == x);
}
inline bool isPowerOfTwo(ll x)
{
    return ((1LL << (ll)log2(x)) == x);
}
template<class T> string to_string(T v) {
    bool f=1;
    string res;
    each(x, v) {
        if(!f)
            res+=' ';
        f=0;
        res+=to_string(x);
    }
    return res;
}
vector<ll> prime;
 
void sieve(ll N){
    bool isPrime[N+!1];
 
    for(ll i = 0; i <= N;++i) {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(ll i = 2; i * i <= N; ++i) {
            if(isPrime[i] == true) {   
                for(ll j = i * i; j <= N ;j += i)
                    isPrime[j] = false;
        }
    }
 
    for(ll i =2;i<=N;i++) {
        if(isPrime[i] == true) {
            prime.push_back(i);
        }
    }
}
 template<class A> void write(A x) {
    cout << to_string(x);
}
 
string to_string(const char* s) {
    return string(s);
}
ll minPrime[MAXN];
void factorSieve(ll n){
    memset(minPrime,0,sizeof(minPrime));
    for (ll i = 2; i * i <= n; ++i) {
        if (minPrime[i] == 0) {
            for (ll j = i * i; j <= n; j += i) {
                if (minPrime[j] == 0) {
                    minPrime[j] = i;
                }
            }
        }
    }
    for (ll i = 2; i <= n; ++i) {
        if (minPrime[i] == 0) {
            minPrime[i] = i;
        }
    }
}
template<class H, class... T> void write(const H& h, const T&... t) { 
    write(h);
    write(t...);
}
 string to_string(string s) {
    return s;
}
ll factorize(ll n) {
 
    map<ll,ll> m;
    m.clear();
    while (n != 1) {
        m[minPrime[n]]++;
        n /= minPrime[n];
    }
 
    for(auto i:m) {
        if(i.second>1) {
            return 0;
        }
    }
 
    return 1;
}
void print() {
    cout<<("\n");
}
template<class H, class... T> void print(const H& h, const T&... t) { 
    write(h);
    if(sizeof...(t))
        write(' ');
    print(t...);
}


string to_string(vt<bool> v) {
    string res;
    forn(sz(v))
        res+=char('0'+v[i]);
    return res;
}

string to_string(char c) {
    return string(1, c);
}

void DBG() {
    cerr << "]" << endl;
}
template<class H, class... T> void DBG(H h, T... t) {
    cerr << to_string(h);
    if(sizeof...(t))
        cerr << ", ";
    DBG(t...);
}
#define deb(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)

ll extended_GCD(ll a , ll b , ll &x , ll &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1 , y1;
    ll gcd = extended_GCD(b % a , a , x1 , y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

ll modinv(ll a , ll mod = MOD) {
    ll x , y, g;
    g = extended_GCD(a , mod , x , y);
    if (g != 1)
        return -1;
    else
    {
        if (x < 0) x += mod;
        return x;
    }
}

vll fact(200001);
void precompute_NCR(ll N)
{
    fact[0] = 1;
    forn(i, 1, (N +1), 1)
    {
        ll y = (i % MOD * fact[i - 1] % MOD) % MOD;
        fact[i] = y;
    }
}

ll choose(ll N, ll R, ll mod = MOD)              
{
    ll n = fact[N];
    ll r = fact[R];
    ll n_r = fact[N - R];
    ll y = (r % mod * n_r % mod) % mod;
    ll z = modinv(y, mod);
    ll ans = (n % mod * z % mod) % mod;
    return ans;
} 
inline ll mult(ll a,ll b){return (((a%MOD)*(b%MOD))%MOD);}
// bool safe(ll i, ll j) { return i >= 0 && i < n && j >= 0 && j < m; }
const ll N=1e4;
void solve() {
  ll n,m;
  read(n,m);
  ll arr[n][m];
  forn(i,n){
    read(arr[i],m);
  }
  string s[n];
  ll dp[n+1][m+1];
  ini(dp,0);
  forn(i,m){
    dp[0][i]=arr[0][i];
  }
  forn(i,1,n){
    forn(j,m){
      ll &ans=dp[i][j];
      ans=arr[i][j];
      if(j-1>=0){
        ans=max(ans,dp[i-1][j-1]);
      }
      if(j+1<m){
        ans=max(ans,dp[i-1][j+1]);
      }
      ans=max(ans,dp[i-1][j]);
    }
  }
  forn(i,n){
    s[i]=string(m,'0');
    forn(j,m){
      if(dp[i][j]<=arr[i][j]){
        s[i][j]='1';
      }
    }
  }
  forn(i,n){
    cout<<s[i];
    en;
  }
}
int main() {
    fast;
    int t=1;
    read(t);
    forn(t) {
        // cout << "Case #" << i+1 << ": ";
        solve();
    }
}

