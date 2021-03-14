#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace __gnu_pbds;


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

#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update>


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
    vi arr(N);
    f(i, 0, N) cin>>arr[i];
  
    int sub_count = 0;
    int j=0;
    vi mp(2001, 0);
    ordered_set o_set;
    f(i, 0, N){
        
        if(i%2==0){
            
            while(j<N){
                //cout<<i<<"-"<<j<<endl;
                mp[arr[j]]++;

                o_set.insert(make_pair(arr[j], j));
                int len = j - i + 1;
                int m = K%len==0 ? K/len : K/len + 1;
                int k_temp = K%m==0 ? K/m : K/m + 1;

                
                int X = (*(o_set.find_by_order(k_temp-1))).first;
                

                int F = mp[X];
                //cout<<m<<", "<<k_temp<<", "<<X<<", "<<F<<endl;
                // for (auto const& pair: mp) {
                //     cout << "{" << pair.first << ": " << pair.second << "}, ";
                // }
                // cout<<endl;
                
                //for (auto const& pair: o_set) {
                //     cout << pair.first << ", ";
                //}
                //cout<<endl;
                //cout<<F<<endl;
                if(mp[F] > 0) sub_count++;
                j++;

            }
            mp[arr[i]]--;
            o_set.erase(make_pair(arr[i], i));
            j = N-1;
        }
        else{
            
            while(j>=i){
                //cout<<i<<"--"<<j<<endl;
                
                int len = j - i + 1;
                int m = K%len==0 ? K/len : K/len + 1;
                int k_temp = K%m==0 ? K/m : K/m + 1;

                
                int X = (*(o_set.find_by_order(k_temp-1))).first;
                

                int F = mp[X];
                //cout<<m<<", "<<k_temp<<", "<<X<<", "<<F<<endl;
                // for (auto const& pair: mp) {
                //     cout << "{" << pair.first << ": " << pair.second << "}, ";
                // }
                // cout<<endl;;
                //for (auto const& pair: o_set) {
                //     cout << pair.first << ", ";
                //}
                //cout<<endl;
                
                //cout<<F<<endl;
                if(mp[F] > 0) sub_count++;
                
                mp[arr[j]]--;
                o_set.erase(make_pair(arr[j], j));
                j--;

            }
            
            j=i+1;
        }
    }

    cout<<sub_count<<endl;
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




    