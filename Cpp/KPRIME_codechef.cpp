#include <bits/stdc++.h>

using namespace std;

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define fo(i,n) for(int i=0;i<n;i++)
#define fore(i, n) for(int i=n;i>=0;i--)
#define foi(i,n) for(int i=0;i<=n;i++)
#define fora(i,m,n) for(int i=m;i<=n;i++)
#define forera(i, m, n) for(int i=m;i>=n; i--)
#define foerera(i, m, n) for(int i=m; i>n;i--)
#define foste(i, st, n) for(int i=0; i<n; i+=st)
#define fosti(i, st, n) for(int i=0; i<=n; i+=st)
#define fostera(i, st, m, n) for(int i=m; i<=n; i+=st)
#define ll long long
#define pii pair<int, int>

const int mod = 1000000007;
inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline void inc(int& a, int b) { a = add(a, b); }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline void dec(int& a, int b) { a = sub(a, b); }

int N = 100000;
vector<int> primes(N+1, 0);
vector< vector< pii> > k_primes;



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

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    fora(i, 2, N) if(primes[i] == 0) fostera(j, i, i, N) primes[j] += 1; 
    //fora(i, 2, N) cout<<primes[i]<<" "; cout<<endl;


    pii temp;

    vector<pii> vecc(1, pii(0,0));
    k_primes.push_back(vecc);
    fora(k, 1, 5){
        temp.first = 0;
        temp.second = 0;
        vector<pii> vec;
        fora(i, 2, N){
            //cout<<i<<"-"<<primes[i]<<"__";
            if(primes[i] == k){
                temp.first = i;
                temp.second += 1;
                //cout<<temp.second<<endl;
                vec.push_back(temp);
            }
            //else cout<<"NO\n";
        }
        //cout<<endl;
        k_primes.push_back(vec);
        //fo(i, vec.size()) cout<<vec[i].first<<" "; cout<<endl;
        //fo(i, vec.size()) cout<<vec[i].second<<" "; cout<<endl;cout<<endl;
        
    }

    //cout<<k_primes.size()<<endl<<endl;
    //fora(i, 1, 5) cout<<k_primes[i-1].size()<<endl;
    
    //foi(i, N) cout<<primes[i]<<" ";
    
    int T, A, B, K;
    cin>>T;
        clock_t z = clock();
    while(T--){
        cin>>A>>B>>K;
        A--;
        //fora(i, 0, B) cout<<k_primes[K][i].first<<" "; cout<<endl;

        int a_ind = lower_bound(k_primes[K].begin(), k_primes[K].end(), A, compare()) - k_primes[K].begin();
        if(k_primes[K][a_ind].first != A) a_ind--;
        
        int b_ind = lower_bound(k_primes[K].begin(), k_primes[K].end(), B, compare()) - k_primes[K].begin();
        if(k_primes[K][b_ind].first != B) b_ind--;
        //cout<<a_ind<<" "<<b_ind<<endl;
        int a_count = (a_ind < 0) ? 0 : k_primes[K][a_ind].second, b_count = (b_ind < 0) ? 0 : k_primes[K][b_ind].second;

        cout<<b_count - a_count<<endl;
    }    
        debug("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
}
