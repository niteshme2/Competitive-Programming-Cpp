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
#define vvi vector<vector<int>>
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
    int N, M;
    cin>>N>>M;
    vvi clean(N, vi(M, 0));
    vvi is_clean(N, vi(M, 5));
    
    f(i, 0, N) f(j, 0, M) cin>>clean[i][j];
    //cout<<"input_done"<<endl;
    int least = 1;
    //cout<<N<<" "<<M<<endl;
    f(i, 0, N) f(j, 0, M){
        //cout<<i<<" "<<j<<endl;
        int ind_x, ind_y;
        f(k, 0, N) f(l, 0, M) if(clean[k][l] == least){ind_x=k;ind_y=l;break;};
        //cout<<"found min at "<<ind_x<<" "<<ind_y<<endl;
        f(k, ind_x, N) f(l, ind_y, M) is_clean[k][l] = 0;
        is_clean[ind_x][ind_y] = 1;
        //cout<<"cleanup done\n";
        //cout<<endl;
        least++;
    }
    
    f(i, 0, N) {
        f(j, 0, M) cout<<is_clean[i][j];
        cout<<endl;
    }


}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        //cout<<"solving "<<T<<endl;
        clock_t z = clock();
        solve();
        //debug("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }    
}




    