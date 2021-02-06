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
    int n, q;
    cin >> n >> q;
    vector< int > arr(n);
    set< int > subarray;

    f(i, 0, n) cin >> arr[i];
    
    if(n==1){
        subarray.insert(0);
    }
    else{
        f(i, 0, n-1){
            subarray.insert(i);
            while(i < n-1 && arr[i+1] % arr[i] == 0) i++;
        }
        if(arr[n-1] % arr[n-2] != 0){
            subarray.insert(n-1);
        }    
        
    }
    
    f(j, 0, q){
        int query, i, x;
        cin >> query;
        if(query == 1){
            cin >> i >> x;
            i--;
            auto it = subarray.lower_bound(i);
            if(it==subarray.end()) it--;
            if( *it == i){
                arr[i] = x;
                if( i > 0 && arr[i] % arr[i-1] == 0){
                    subarray.erase(it);
                }
                if( i < n-1 ) subarray.insert(i+1);
                if( i < n-1 && arr[i+1] % arr[i] == 0){
                    subarray.erase(subarray.lower_bound(i+1));
                }
            }
            else{
                it--;
                arr[i] = x;
                subarray.insert(i);
                if( i < n-1 ) subarray.insert(i+1);
                if( arr[i] % arr[i-1] == 0){
                    subarray.erase(subarray.lower_bound(i));
                }
                if( i < n-1 && arr[i+1] % arr[i] == 0){
                    subarray.erase(subarray.lower_bound(i+1));
                }

            }

        }
        else{
            cin >> i;
            i--;
            auto it = subarray.lower_bound(i);
            if(it == subarray.end()){
                it--;
                cout<<*it + 1<<endl;
            }
            else if( *it == i) cout<<i+1<<endl;
            else{
                it--;
                cout<<*it + 1<<endl;
            }

        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
        clock_t z = clock();
        solve();
}




    