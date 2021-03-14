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
    int N, E, H, A, B, C;
    cin>>N>>E>>H>>A>>B>>C;

    vi a, b;

    a.push_back(0);
    b.push_back(0);

    if(E-N > 0){
        a.push_back(E-N);
        b.push_back(0);
    }
    else{
        b.push_back(N-E);
        a.push_back(0);
    }

    if(N - H > 0){
        a.push_back(N-H);
        b.push_back(0);
    }
    else{
        a.push_back(0);
        b.push_back((H-N)/2);

        a.push_back(0);
        b.push_back((H-N)/2 + 1);

        b.push_back((H-N)/2);
        a.push_back(2*((H-N)/2) - H + N);

        b.push_back((H-N)/2 + 1);
        a.push_back(2*((H-N)/2 + 1) - H + N);
    }

    a.push_back(2*E + H - N);
    b.push_back(E + H - 2*N);

    if( E%2 == 0){
        a.push_back(E/2);
        b.push_back(N - E/2);
    }
    else{
        a.push_back(E/2);
        b.push_back(E/2 - E + N);

        a.push_back(E/2 + 1);
        b.push_back(E/2 + 1 - E + N);

        a.push_back(E/2);
        b.push_back(N - E/2);

        a.push_back(E/2 + 1);
        b.push_back(N - E/2 + 1);

    }

    if( H%3 == 0){
        a.push_back(H/3);
        b.push_back(N - H/3);
    }
    else{
        b.push_back(N - H/3);
        a.push_back(2* (N - H/3)  - H + N);

        b.push_back(N - H/3 - 1);
        a.push_back(2* (N - H/3 - 1)  - H + N);

        b.push_back(N - H/3);
        a.push_back(H/3);

        b.push_back(N - H/3 - 1);
        a.push_back(H/3 + 1);
    }


    //f(i, 0, a.size()) cout<<"("<<a[i]<<", "<<b[i]<<")"<<endl;

    int min_price = -1;
    for(int i=0;i<a.size();i++){
        if(a[i] - b[i] <= E - N && 2*b[i] - a[i] <= H-N && a[i] + b[i] <= N && a[i] >=0 && b[i] >= 0){
            //cout<<a[i]<<" "<<b[i]<<" "<<N - a[i] - b[i]<<endl;
            if(min_price == -1){
                min_price = a[i]*A + b[i]*B + (N-a[i]-b[i])*C;
                
                //cout<<"."<<min_price<<endl;
            }
            else{
                min_price = min(min_price, a[i]*A + b[i]*B + (N-a[i]-b[i])*C);
                
                //cout<<min_price<<endl;
            }
        }
    }

    cout<<min_price<<endl;
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




    