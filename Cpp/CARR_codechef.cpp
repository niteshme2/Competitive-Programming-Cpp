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

ll N, M;

void multiply(vector<vector<ll>> &a,  vector<vector<ll>> &b) { 
    
    int n = a.size(); 
    
    vector<vector<ll>> mul(n, vector<ll>(n, 0)); 
    
    for (int i = 0; i < 2; i++) 
    { 
        for (int j = 0; j < 2; j++) 
        { 
            mul[i][j] = 0; 
            for (int k = 0; k < 2; k++) 
                mul[i][j] += (a[i][k]*b[k][j])%MOD;
                mul[i][j] %= MOD; 
                
        } 
    } 
    
    // storing the multiplication result in a[][] 
    for (int i=0; i<2; i++) 
        for (int j=0; j<2; j++) 
            a[i][j] = mul[i][j];  // Updating our matrix
     
}


void mat_power(vector<vector<ll>> &F, ll n){

    
    if(n==1)
        return;
    
    if(n%2==0){
        mat_power(F, n/2);
        multiply(F, F);
    }
    
    else{
        vector<vector<ll>> temp = F;
        mat_power(F, n/2);
        mat_power(F, 2);
        multiply(F, temp);
    }
    

}


void solve(){
    cin>>N>>M;

    if(N==1){
        cout<<M%MOD<<endl;
        return; 
    }
    if(N==2){
        cout<<((M%MOD)*(M%MOD))%MOD<<endl;
        return;
    }

    vector<ll> base_case = {((M%MOD)*((M-1)%MOD))%MOD, M%MOD};
    vector<vector<ll>> F = {{(M-1)%MOD, (M-1)%MOD}, {1,0}};
    mat_power(F, N-2);
    /*
    cout<<"matrix = "<<endl;
    f(i, 0, F.size()){
        f(j, 0, F.size()) cout<<F[i][j]<<" ";
        cout<<endl;
    }
    cout<<"base = "<<endl;
    cout<<base_case[0]<<" "<<base_case[1]<<endl; 
    
    cout<<(((F[0][0] + F[1][0])%MOD)*base_case[0])%MOD<<" + "<<(((F[0][1] + F[1][1])%MOD)*base_case[1])%MOD<<endl; 
    */
    cout<<((((F[0][0] + F[1][0])%MOD)*base_case[0])%MOD + (((F[0][1] + F[1][1])%MOD)*base_case[1])%MOD)%MOD<<endl; 
    


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




    