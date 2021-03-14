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
        vector<long long> chefs(N, 0);
        f(i, 0, N) cin>>chefs[i];
        stack<long long> stk;
        vector<long long> fear(N, 1);

        f(i, 0, N){
            if(stk.empty()){
                stk.push(i);
            }
            else{
                if(chefs[i] >= chefs[stk.top()]){
                    stk.push(i);
                }
                else{
                    while( !stk.empty()  && chefs[stk.top()] > chefs[i]){
                        fear[stk.top()] = i - stk.top() + 1;
                        stk.pop(); 
                    }
                    stk.push(i);
                }
            }
        }

        long long ans = 1;
        //f(i, 0, N) cout<<fear[i]<<" ";cout<<endl;
        f(i, 0, N) ans = (ans * fear[i])%MOD;

        cout<<ans<<endl;

    }

    int main(){
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        int T;
        T=1;
        while(T--){
            clock_t z = clock();
            solve();
            debug("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
        }    
    }




        