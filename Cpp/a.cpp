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
#define vl vector<long long>
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
    vl arr(n,0);
    f(i, 0, n) cin>>arr[i];

    vii sum_range(n, make_pair(0,0));
    vl sum(n, 0);

    sum[0] = arr[0];
    f(i, 1, n){
        if(sum[i-1] >= 0){
            sum[i] = sum[i-1] + arr[i];
            sum_range[i] = make_pair(sum_range[i-1].first, i);
        } 
        else{
            sum[i] = arr[i];
            sum_range[i] = make_pair(i, i);
        }
    }

    //f(i, 0, n) cout<<sum[i]<<" ";cout<<endl;
    //f(i, 0, n) cout<<sum_range[i].first<<","<<sum_range[i].second<<"__";cout<<endl;

    vii max_indices;

    ll max_sum = *max_element(sum.begin(), sum.end());

    f(i, 0, n){
        if(sum[i] == max_sum){
            max_indices.push_back(sum_range[i]);
        }
    }

    int min = 0;
    f(i, 0, max_indices.size()){
        if(max_indices[i].first != max_indices[i].second){
            int sub_array_min = *min_element(arr.begin()+max_indices[i].first, arr.begin()+max_indices[i].second);
            if(sub_array_min < 0) min = min < sub_array_min  ? min : sub_array_min;
        }
    }

    //cout<<min<<endl;
    cout<<max_sum - min<<endl;
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




    