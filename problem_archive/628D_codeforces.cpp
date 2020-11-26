#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define fo(i,n) for(int i=0;i<=n;i++)
#define foi(i,n) for(int i=0;i<n;i++)
#define fora(i,m,n) for(int i=m;i<=n;i++)
#define ll long long 

const int mod = 1000000007;
inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline void inc(int& a, int b) { a = add(a, b); }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline void dec(int& a, int b) { a = sub(a, b); }

int DP[2001][2000][2];

vector<int> num;

int m, d;

bool good(string s) {
    int rm = 0;
    foi(i, s.size()) {
        int p = int(s[i] - '0');
        if ((i & 1) && p != d) return false;
        if (!(i & 1) && p == d) return false;
        rm = (rm * 10 + p) % m;
    }
    return !rm;
}

int magic_count(int pos, int rem, int tight){
    
    if(DP[pos][rem][tight]!=-1) return DP[pos][rem][tight];
    
    int count=0;
    if(pos == num.size()-1){
        int lim = tight ? 9: num[pos];
        fo(dgt, lim){
            if( (pos&1) && dgt!=d) continue;
            if( !(pos&1) && dgt==d) continue;
            if( !pos && !dgt) continue;
            int new_rem = (rem*10 + dgt)%m;
            count += !new_rem ? 1 : 0;
        }
        DP[pos][rem][tight] = count;
        return count;
    }

    if(DP[pos][rem][tight]!=-1) return DP[pos][rem][tight];
    
    int lim = tight ? 9: num[pos];
    fo(dgt, lim){
        if( (pos&1) && dgt!=d) continue;
        if( !(pos&1) && dgt==d) continue;
        if( !pos && !dgt) continue;
        int new_rem = (rem*10 + dgt)%m;
        int new_tight = (dgt==lim && !tight) ? 0 : 1;
        inc( count, magic_count(pos+1, new_rem, new_tight));
        
    }
    DP[pos][rem][tight] = count;
    return count;
    
} 

int solve1(int ord){
    //clock_t z = clock();
    num.clear();
    string temp; 
    cin>>temp;
    for(int i=0;i<temp.size();i++){
        num.push_back(temp[i] - '0');
    }
    
    //debug("Total Time %d: %.3f\n", ord, (double)(clock() - z) / CLOCKS_PER_SEC);
    //clock_t zz = clock();
    //debug("Total Time %d: %.3f\n", ord, (double)(clock() - zz) / CLOCKS_PER_SEC);
    //cout<<"num input - ";
    //for(int i=0;i<temp.size();i++) cout<<num[i];
    //cout<<endl;
    //clock_t zzz = clock();
    memset(DP, -1, sizeof(DP));
    int ans = magic_count(0,0,0);
    //cout<<ord<<" "<<good(temp)<<endl;
    if(ord==1 && good(temp)){
        //cout<<ans;
        dec(ans, 1);
        //cout<<ans;
    }
    //debug("Total Time %d: %.3f\n", ord, (double)(clock() - zzz) / CLOCKS_PER_SEC);
    return ans;
}

void solve(){

    while(true){
        
        cin>>m>>d;
        //cout<<a<<" "<<b<<endl;
        int a_count = solve1(1);
        //cout<<a_count<<endl;
        int b_count = solve1(2);
        //cout<<b_count<<endl;
        int ans=0;
        //cout<<ans<<endl;
        inc(ans, b_count);
        //cout<<ans<<endl;
        dec(ans, a_count);
        //cout<<ans<<endl;
        
        //cout<<b_count<<" - ";
        //cout<<a_count<<" = ";
        
        cout<<ans<<"\n";
        //cout<<b_count<<endl;
        break;

    }

}



int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    //clock_t z = clock();
    solve();
    //debug("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
           
}