#include <bits/stdc++.h>

using namespace std;

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define f(i,m, n) for(int i=m;i<n;i++)
#define fr(i, m, n) for(int i=m;i>n;i--)
#define fi(i, m, n) for(int i=m;i<=n;i++)
#define fri(i, m, n) for(int i=m;i>=n;i--)

#define int long long
#define vi vector<int>

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




void rev(int i, int j, vi &arr){
	int p = i;
	int q = j;
	
	while(p<=q)
	{
		swap(arr[p], arr[q]);
		p++;
		q--;
	}
}





void solve(int cs){
    int n;
    cin>>n;

    vi arr(n);

    f(i,0,n) cin>>arr[i];

    int res = 0;

    fri(i, n-1, 0){
        int mn_i = n-1;
        int mn_t = INT_MAX;

        fri(j, n-1, i){
            if(arr[j] < mn_t){
                mn_t = arr[j];
                mn_i = j;
            }
        }

        rev(i, mn_i, arr);
        res += mn_i - i + 1;
    }

    cs++;
    cout<<"Case #"<<cs<<":"<<" "<<res<<"\n";



}

int32_t main(){
ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin>>T;
    int cs = 1;
    while(T--){
        clock_t z = clock();
        solve(cs);
        cs++;
        debug("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }    
}