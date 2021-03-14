#include <bits/stdc++.h>

using namespace std;

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define f(i,m, n) for(int i=m;i<n;i++)
#define fr(i, m, n) for(int i=m;i>n;i--)
#define fi(i, m, n) for(int i=m;i<=n;i++)
#define fri(i, m, n) for(int i=m;i>=n;i--)

#define ll long long
#define int long long int
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
    int N, Q;
    cin>>N>>Q;
    vi mot(N, 0), sat(N, 0);
    f(i, 0, N) cin>>mot[i];
    f(i, 0, N) cin>>sat[i];

    vi queries(Q, 0);
    f(i, 0, Q) cin>>queries[i];

    sort(mot.begin(), mot.end());
    sort(sat.begin(), sat.end());

    int max_query = *max_element(queries.begin(), queries.end());
    vi sums(max_query+1, -1);

    vi min_index(N, 0);

    priority_queue<pii> pq;

    f(i, 0, N) pq.push( make_pair(-1 * (mot[i] + sat[min_index[i]]), i ));

    // while(pq.size()){
    //     cout<<-1*pq.top().first<<" "<<pq.top().second<<endl;
    //     pq.pop();
    // }
    // cout<<endl;

    int index = 1;
    while(index < sums.size()){
        sums[index] = -1* pq.top().first;
        
        int mot_ind = pq.top().second;
    
        min_index[mot_ind]++;
        //f(i, 0, sums.size()) cout<<sums[i]<<" ";cout<<endl;
        pq.push(  make_pair(-1 * (mot[mot_ind] + sat[min_index[mot_ind]]), mot_ind ) );
        pq.pop();
        index++;
    }
    //cout<<endl;

    for(auto q: queries){
        cout<<sums[q]<<endl;
    }

    

}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        clock_t z = clock();
        solve();
        //debug("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }    
}




    