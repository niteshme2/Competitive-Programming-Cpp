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
#define vvi vector< vector<int> > 


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
    int N, M;
    cin>>N>>M;
    vvi clean(N, vector<int>(M, 0));
    vvi is_clean(N, vector<int>(M, 0));
    f(i, 0, N) f(j, 0, M) cin>>clean[i][j];

    

    

    f(j, 0, M) is_clean[0][j] = 1;
    

    f(i, 1, N) f(j, 0, M){
        
        int left, middle, right;
        left = j-1 >= 0 ? clean[i-1][j-1] : 0;
        right = j+1 < M ? clean[i-1][j+1] : 0;
        middle = clean[i-1][j];
        
        
        is_clean[i][j] = (clean[i][j] > left && clean[i][j] > middle && clean[i][j] > right) ? 1 : 0;
        clean[i][j] = max({clean[i][j], left, middle, right});
    }

    f(i, 0, N){
        f(j, 0, M){
            cout<<is_clean[i][j];
        }
        cout<<endl;
    }



}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        clock_t z = clock();
        solve();
        //debug("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }    
}




    