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




int debug = 0;





void solve(){
    int X, B, C;
    cin>>X;
    cin>>B;
    vii dishes(B, make_pair(0, 0));
    f(i, 0, B) cin>>dishes[i].first>>dishes[i].second;

    cin>>C;
    vector< pair<int, pii>> tribes(C, make_pair(0, make_pair(0, 0)));

    f(i, 0, C) cin>>tribes[i].first>>tribes[i].second.first>>tribes[i].second.second;


    //if(debug) f(i, 0, B) cout<<dishes[i].first<<" ";
    //if(debug) cout<<endl;
    //if(debug) f(i, 0, C) cout<<tribes[i].first<<" ";
    //if(debug) cout<<endl;
    //if(debug) f(i, 0, B+C) cout<<dist[i]<<" ";
    //if(debug) cout<<endl;
    

    int dish_ind = B-1, tribe_ind =C-1;
    int min_chef = 1;
    while(dish_ind >= 0 && tribe_ind >= 0){
        if(debug) cout<<dish_ind<<" - "<<tribe_ind<<": ";

        if(dishes[dish_ind].first > tribes[tribe_ind].first){
            min_chef += dishes[dish_ind].second;
            dish_ind--;
        }
        else{
            if(tribes[tribe_ind].second.first < min_chef){
                min_chef = max(tribes[tribe_ind].second.first, min_chef - tribes[tribe_ind].second.second);
            }
            tribe_ind--;
        }
        if(debug) cout<<min_chef<<endl;
    }

    while(dish_ind >= 0 ){
        if(debug) cout<<dish_ind<<" - "<<tribe_ind<<": ";
        min_chef += dishes[dish_ind].second;
        dish_ind--;
        if(debug) cout<<min_chef<<endl;
    }

    while(tribe_ind >= 0){
        if(debug) cout<<dish_ind<<" - "<<tribe_ind<<": ";

        
        if(tribes[tribe_ind].second.first < min_chef){
            min_chef = max(tribes[tribe_ind].second.first, min_chef - tribes[tribe_ind].second.second);
        }
        tribe_ind--;
        
        if(debug) cout<<min_chef<<endl;
    }

    cout<<min_chef<<endl;

}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        clock_t z = clock();
        solve();
        debug("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }    
}




    