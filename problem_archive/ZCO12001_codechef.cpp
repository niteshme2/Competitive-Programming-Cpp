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
    vi brackets(n);
    f(i, 0, n) cin>>brackets[i];

    int ind = 0, max_depth=0, max_len=0, depth_ind = -1, len_ind = -1;
    while(ind < n){
        int curr_depth=0, curr_len=0, start_ind=ind;
        stack<int> stk;
        stk.push(brackets[ind]);
        curr_depth = 1;
        curr_len = 1;
        if(curr_depth > max_depth){
            max_depth = curr_depth;
            depth_ind = ind;
        }
        ind++;
        while( ind < n && !stk.empty() ){
            if( stk.top() != brackets[ind]){
                stk.pop();
                ind++;
                curr_depth--;
            }
            else{
                stk.push(brackets[ind]);
                curr_depth++;
                if(curr_depth > max_depth){
                    max_depth = curr_depth;
                    depth_ind = ind;
                }
                ind++;
            }
            curr_len++;
        }
        if(curr_len > max_len){
            max_len = curr_len;
            len_ind = start_ind;
        }
    }

    cout<<max_depth<<" "<<depth_ind+1<<" "<<max_len<<" "<<len_ind+1<<endl;

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    T = 1;
    while(T--){
        clock_t z = clock();
        solve();
        debug("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }    
}




    