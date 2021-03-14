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






ll DP[53][52][710];

vector<ll> letters(52, 0);
ll L, S;

ll count_seq(ll pos, ll len, ll sum){
    //if(sum==L) return 1;
    //f(i, 0, pos) cout<<"  ";
    //cout<<pos<<","<<len<<","<<sum;
    if(len==L && sum==S) return  1;
    else if( len==L && sum != S ) return 0;
    else if( len!=L && sum == S ) return 0;
    else if(len > L) return 0;

    if(pos > 51) return 0;
    //cout<<"no corner\n";
    if(DP[pos][len][sum] != -1) return DP[pos][len][sum];

    ll count =0;

    count += count_seq(pos+1, len, sum);
    count += count_seq(pos+1, len+1, sum+letters[pos]);

    DP[pos][len][sum] = count;
    //f(i, 0, pos) cout<<"  ";
    //cout<<count<<endl;
    return DP[pos][len][sum];

}

void solve(){
     
    cin>>L>>S;
    //if(L==0 && S==0){
    //    cout<<"0\n";
    //    return;
    //}
    memset(DP, -1, sizeof(DP));

    cout<<count_seq(0, 0, 0)<<endl;

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll T;
    cin>>T;

    ll sum = 0;
    f(i, 0, 52) letters[i] = i+1;
    
    ll case_count = 1;
    while(T--){
        
        clock_t z = clock();
        cout<<"Case "<<case_count<<": ";
        solve();
        case_count++;
        //debug("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }    
}




    