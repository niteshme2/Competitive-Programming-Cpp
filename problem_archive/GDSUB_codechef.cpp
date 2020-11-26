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
#define vii vector< pair<int, int> >

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

vi arr(8001, 0);

vii dist;

int K;

int DP[1010][1010];

int solve(int pos, int used){

    if(DP[pos][used] != -1) return DP[pos][used];

    if(pos==dist.size()){
        if(used <= K) return 1;
        else return 0;
    }

    ll count = 0;
    count += ( (ll)dist[pos].second*(ll)solve(pos+1, used+1) )%MOD;
    count = count%MOD;
    count += (ll)solve(pos+1, used);
    count = count%MOD;
    //cout<<pos<<" ";
    //cout<<used<<" ";
    //cout<<count<<endl;
    DP[pos][used] = count;
    return (int)count;

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    clock_t z = clock();
    int N;
    cin>>N>>K;

    vii vec;

    f(i, 0, N){
        int temp;
        cin>>temp;
        arr[temp]++;
    }



    f(i, 0, 8001){
        if(arr[i]){
            dist.push_back(make_pair(i, arr[i]));
        }
    }

    //f(i, 0, dist.size()){
      //  cout<<"("<<dist[i].first<<", "<<dist[i].second<<") ";
    //}
    //cout<<endl;
    
    //cout<<dist.size()<<endl;

    memset(DP, -1, sizeof(DP));
    

    int ans = solve(0, 0);
    cout<<ans;



}