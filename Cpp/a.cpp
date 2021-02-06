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
    int n;
    cin>>n;
    vi A(n), B(n);
    int A_goals = 0, B_goals = 0;
    string temp;
    cin>>temp;
    f(i, 0, n){
        A[i] = temp[2*i] - '0';
        A_goals += A[i];
        if(A_goals > B_goals + n - i){
            cout << 2*i+1 << endl;
            break;
        }
        if( B_goals > A_goals + n - i - 1){
            cout << 2*i+1 << endl;
            break;
        }

        
        B[i] = temp[2*i+1] - '0';
        B_goals += B[i];

        if(A_goals > B_goals + n - i - 1){
            cout << 2*i+2 << endl;
            break;
        }
        if( B_goals > A_goals + n - i - 1){
            cout << 2*i+2 << endl;
            break;
        }
    }
    if(A_goals == B_goals){
        cout << 2*n << endl;
    }
    
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




    