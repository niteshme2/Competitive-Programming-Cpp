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
        int N, X, Y;
        cin>>N>>X>>Y;
        vii contests(N);
        vi V(X);
        vi W(Y);
        f(i, 0, N) cin>>contests[i].first>>contests[i].second;
        f(i, 0, X) cin>>V[i];
        f(i, 0, Y) cin>>W[i];


        sort(V.begin(), V.end());
        sort(W.begin(), W.end());

        int min_time = *(W.end()-1) - *V.begin() + 1;

        f(i,0,N){
            auto it = upper_bound(V.begin(), V.end(), contests[i].first);
            if(it == V.begin() && *it > contests[i].first) continue;
            int curr_entry = *(it - 1);

            int curr_exit = *lower_bound(W.begin(), W.end(), contests[i].second);
            if(curr_exit < contests[i].second) continue;
            int curr_time = curr_exit - curr_entry + 1;
            //cout<<i<<":"<<curr_entry<<"-"<<curr_exit<<endl;
            min_time = min(curr_time, min_time);
        }

        cout<<min_time<<endl;



    }

    int main(){
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        int T;
        T =1 ;
        while(T--){
            clock_t z = clock();
            solve();
            debug("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
        }    
    }




        