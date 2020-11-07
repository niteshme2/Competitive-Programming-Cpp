#include <bits/stdc++.h>

using namespace std;

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define fo(i,n) for(int i=0;i<n;i++)
#define fore(i, n) for(int i=n;i>=0;i--)
#define foi(i,n) for(int i=0;i<=n;i++)
#define fora(i,m,n) for(int i=m;i<=n;i++)
#define forera(i, m, n) for(int i=m;i>=n; i--)
#define foerera(i, m, n) for(int i=m; i>n;i--)
#define ll long long

const int mod = 1000000007;
inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline void inc(int& a, int b) { a = add(a, b); }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline void dec(int& a, int b) { a = sub(a, b); }

int N;

vector<int> arr;




void solve(){
    int temp;
    cin>>N;

    vector<int> DP(N, 0);    
    
    arr.clear();
    fo(i,N){
        cin>>temp;
        arr.push_back(temp);
    }
    if(N==1){ cout<<1<<endl; return;}
    
    ll sub_ar_count = 0;
    
    DP[N-1] = 1;
    forera(i, N-2, 0) DP[i] = (arr[i] <= arr[i+1]) ? (1 + DP[i+1]) : 1;
    //fo(i, N) cout<<DP[i]<<" ";
    //cout<<endl;
    fo(i, N) sub_ar_count += DP[i];

    cout<<sub_ar_count<<endl;
    





}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin>>T;
    int case_count=0;
    while(T--){
        clock_t z = clock();
        solve();
        debug("time %d: %.3f\n", case_count++, (double)(clock() - z) / CLOCKS_PER_SEC);
    }    
}