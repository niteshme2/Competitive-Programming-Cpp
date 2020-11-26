#include <bits/stdc++.h>

using namespace std;

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define fo(i,n) for(int i=0;i<=n;i++)
#define foi(i,n) for(int i=0;i<n;i++)
#define fora(i,m,n) for(int i=m;i<=n;i++)
#define ll long long

const int mod = 1000000009;
inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline void inc(int& a, int b) { a = add(a, b); }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline void dec(int& a, int b) { a = sub(a, b); }

vector<int> DP(1000001, -1);


int count_ways(){

    DP[1] = 0;
    DP[2] = 1;
    DP[3] = 1;
    DP[4] = 1;

    fora(i, 5, 1000000) DP[i] = (DP[i-2] + DP[i-3])%mod;
    

}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    count_ways();
    
    int T;
    cin>>T;
    while(T--){
        clock_t z = clock();
        int X;
        cin>>X;
        cout<<DP[X]<<endl;
        //debug("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }    
}