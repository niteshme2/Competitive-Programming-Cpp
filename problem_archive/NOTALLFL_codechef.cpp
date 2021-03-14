#include <bits/stdc++.h>

using namespace std;

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define f(i,m, n) for(int i=m;i<n;i++)
#define fr(i, m, n) for(int i=m;i>n;i--)
#define fi(i, m, n) for(int i=m;i<=n;i++)
#define fri(i, m, n) for(int i=m;i>=n;i--)

#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>


const int MOD = 1000000007;
inline int add(int a, int b) { return a + b >= MOD ? a + b - MOD : a + b; }
inline void inc(int& a, int b) { a = add(a, b); }
inline int sub(int a, int b) { return a - b < 0 ? a - b + MOD : a - b; }
inline void dec(int& a, int b) { a = sub(a, b); }





struct compare { 
    bool operator()(const pair<int, int>& value,  
                                const int& key) 
    { 
        return (value.first < key); 
    } 
    bool operator()(const int& key,  
                    const pair<int, int>& value) 
    { 
        return (key < value.first); 
    } 
}; 










void solve(){
    int N, K;
    cin>>N>>K;
    vi arr(N, 0);
    map<int, int> m;
    set<pair<int, int>> s;
    f(i, 0, N){
        cin>>arr[i];
        m[arr[i]] = -1;
    }

    if(m.size() < K){
        cout<<N<<endl;
        return;
    }

    for(auto p : m) s.insert(make_pair(p.second, p.first));
    int max_len = 0;
    f(i, 0, N){
        s.erase( make_pair( m[arr[i]], arr[i] ) );
        m[arr[i]] = i;
        s.insert( make_pair( m[arr[i]], arr[i] ) );
        max_len = max(max_len, i - (*s.begin()).first);
    }
    cout<<endl;

    cout<<max_len<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        clock_t z = clock();
        solve();
        debug("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }    
}




    