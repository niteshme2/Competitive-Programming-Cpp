#include <bits/stdc++.h>

using namespace std;

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define f(i,m, n) for(int i=m;i<n;i++)
#define fr(i, m, n) for(int i=m;i>n;i--)
#define fi(i, m, n) for(int i=m;i<=n;i++)
#define fri(i, m, n) for(int i=m;i>=n;i--)

#define ll long long
#define ld long double
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>


const int MOD = 1000000007;
inline int add(int a, int b) { return a + b >= MOD ? a + b - MOD : a + b; }
inline void inc(int& a, int b) { a = add(a, b); }
inline int sub(int a, int b) { return a - b < 0 ? a - b + MOD : a - b; }
inline void dec(int& a, int b) { a = sub(a, b); }


bool sortbysec(const pair<ld,ld> &a, const pair<ld,ld> &b) 
{ 
    return (a.second < b.second); 
} 


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



ld euclid_dist(pair<ld, ld> &x, pair<ld, ld> &y){
    return sqrt( (x.first - y.first)*(x.first - y.first) + (x.second - y.second)*(x.second - y.second) );
}

ld euclid_dist_tri(pair<ld, ld> &x, pair<ld, ld> &y, pair<ld, ld> &z){
    return euclid_dist(x, y) + euclid_dist(y, z) + euclid_dist(z, x);
}


ld get_min_dist(vector<pair<ld, ld>> &p, int l, int r){
    //cout<<l<<" "<<r<<endl;
   
        
        
    if(l == r)
        return 1e9;
    if(l+1 == r)
        return 1e9;
    if(l+2 == r)
        return euclid_dist_tri(p[l],p[l+1],p[l+2]); 
      
    
    ld left = get_min_dist(p, l, (l+r)/2);
    

    ld right = get_min_dist(p, (l+r)/2+1, r);
    
    //cout<<left<<endl;
    //cout<<right<<endl;
    vector< pair<ld, ld>> p_strp;

    ld min_dist = min(left, right);

    pair<ld, ld> mid_p = p[(l+r/2)];

    p_strp.push_back(mid_p);
    //cout<<"P_strp:"<<endl;
    //f(i, 0, p_strp.size()) cout<<p_strp[i].first<<" "<<p_strp[i].second<<endl;
    //cout<<endl;
    int temp = (l+r)/2 - 1 ;
    while(temp>=0 && abs(mid_p.first - p[temp].first) <= min_dist){
        p_strp.push_back(p[temp]);
        temp--;
    }
    //cout<<"P_strp:"<<endl;
    //f(i, 0, p_strp.size()) cout<<p_strp[i].first<<" "<<p_strp[i].second<<endl;
    //cout<<endl;
    temp = (l+r)/2 + 1 ;
    while(temp<p.size() && abs(mid_p.first - p[temp].first) <= min_dist){
        p_strp.push_back(p[temp]);
        temp++;
    }
    //cout<<"P_strp:"<<endl;
    //f(i, 0, p_strp.size()) cout<<p_strp[i].first<<" "<<p_strp[i].second<<endl;
    //cout<<endl;

    sort(p_strp.begin(), p_strp.end(), sortbysec);
    
    //cout<<"min = "<<min_dist<<endl;
    f(i, 1, p_strp.size()){
        int j = i-1;
        while(j>=0 && euclid_dist(p_strp[i], p_strp[j]) <= min_dist){
            //cout<<"pd: "<<euclid_dist(p_strp[i], p_strp[j])<<endl;
            int k = j-1;
            while(k>=0 && euclid_dist(p_strp[j], p_strp[k]) <= min_dist){
                //cout<<"pd: "<<euclid_dist(p_strp[i], p_strp[j])<<endl;
                min_dist = min(min_dist, euclid_dist_tri(p_strp[i], p_strp[j], p_strp[k]));
                //cout<<" "<<min_dist<<endl;
                k--;
            }
            //cout<<" "<<min_dist<<endl;
            j--;
        }
    }
    
    return min_dist;

}


void solve(){
    int n;
    cin>>n;

    vector<pair<ld, ld>> p(n);

    f(i, 0, n) cin>>p[i].first>>p[i].second;

    sort(p.begin(), p.end());
    cout<<n<<endl;
    cout<<get_min_dist(p, 0, n-1)<<endl;

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin>>T;
    cout.precision(17);
    while(T--){
        clock_t z = clock();
        solve();
        debug("Total Time: %.6f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }    
}




    