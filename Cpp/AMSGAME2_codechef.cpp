#include <bits/stdc++.h>

using namespace std;

#define debug(...) fprllf(stderr, __VA_ARGS__), fflush(stderr)
#define f(i,m, n) for(ll i=m;i<n;i++)
#define fr(i, m, n) for(ll i=m;i>n;i--)
#define fi(i, m, n) for(ll i=m;i<=n;i++)
#define fri(i, m, n) for(ll i=m;i>=n;i--)

#define ll long long
#define pii pair<ll, ll>
#define vi vector<ll>
#define vii vector<pair<ll, ll>>


const ll MOD = 1000000007;
inline ll add(ll a, ll b) { return a + b >= MOD ? a + b - MOD : a + b; }
inline void inc(ll& a, ll b) { a = add(a, b); }
inline ll sub(ll a, ll b) { return a - b < 0 ? a - b + MOD : a - b; }
inline void dec(ll& a, ll b) { a = sub(a, b); }





struct compare { 
    bool operator()(const pair<ll, ll>& value,  
                                const ll& key) 
    { 
        return (value.first < key); 
    } 
    bool operator()(const ll& key,  
                    const pair<ll, ll>& value) 
    { 
        return (key < value.first); 
    } 
}; 







ll DP[61][10001];

vi nums;

ll CC = 0;
ll count_gcd(ll pos, ll gcd){
    //cout<<++CC<<endl;

    //f(i, 0, pos) cout<<"  ";
    //cout<<nums[pos]<<" ";
    
    if(pos == nums.size()){
        //cout<<"END\n";
        if(gcd == 1) return 1;
        else return 0;
    }
    if(DP[pos][gcd] != -1){
        
        //cout<<" -> "<<DP[pos][gcd]<<endl;
        return DP[pos][gcd];
    } 


    ll count = 0;
    count += count_gcd(pos+1, gcd);
    if(gcd == 0)
        count += count_gcd(pos+1, nums[pos]);
    else count += count_gcd(pos+1, __gcd(gcd, nums[pos]));
 
    //cout<<" -> "<<count<<endl;
    DP[pos][gcd] = count;
    return count;
}

void solve(){
    ll N;
    cin>>N;
    nums.clear();
    CC=0;
    f(i, 0, N){
        ll temp;
        cin>>temp;
        nums.push_back(temp);
    } 
    memset(DP, -1, sizeof(DP));
    //cout<<DP[0][0]<<DP[1][1];

    ll ans = count_gcd(0, 0);

    cout<<ans<<endl;


}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll T;
    cin>>T;
    while(T--){
        clock_t z = clock();
        solve();
        //debug("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }    
}




    