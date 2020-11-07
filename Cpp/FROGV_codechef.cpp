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
    int N,K,P,A,B;
    cin>>N>>K>>P;
    vii pos(N, make_pair(0,0));
    f(i,0,N) cin>>pos[i].first;
    f(i,0,N) pos[i].second = i+1;
    vii f_pairs(P);
    f(i, 0, P) cin>>f_pairs[i].first>>f_pairs[i].second;

    vector<int> groups(N+1, 0);
    sort(pos.begin(), pos.end());
    int group_count = 1;
    groups[pos[0].second] = 1;
    f(i, 1, N){
        if(pos[i].first - pos[i-1].first > K) group_count++;
        groups[pos[i].second] = group_count;    
    }

    //f(i, 1, N+1) cout<<groups[i]<<" ";cout<<endl;

    f(i, 0, P){
        if(groups[f_pairs[i].first] == groups[f_pairs[i].second]) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    clock_t z = clock();
    solve();
    //debug("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
        
}