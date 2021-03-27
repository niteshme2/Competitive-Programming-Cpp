#include <bits/stdc++.h>

using namespace std;

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define f(i,m, n) for(int i=m;i<n;i++)
#define fr(i, m, n) for(int i=m;i>n;i--)
#define fi(i, m, n) for(int i=m;i<=n;i++)
#define fri(i, m, n) for(int i=m;i>=n;i--)

#define ll long long
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










void solve(int n, int q){
    

    vi arr;
    cout<<"1 2 3"<<endl;
    int s = 3, med;
    cin>>med;

    if(med==2){
        arr.push_back(1);
        arr.push_back(2);
        arr.push_back(3);
    }
    if(med==3){
        arr.push_back(1);
        arr.push_back(3);
        arr.push_back(2);
    }
    if(med==1){
        arr.push_back(2);
        arr.push_back(1);
        arr.push_back(3);
    }
    f(i, 4, n+1){
        int beg = 0;
        int end = s - 1;
        while(beg<end){
            ll mid=beg+((end-beg)/2);
            cout<<arr[mid]<<" "<<arr[mid+1]<<" "<<(i)<<endl;
            cin>>med;
            if(med==arr[mid]){
                end=mid;
            }
            else if(med==arr[mid+1]){
                
                beg=mid+1;
            }
            else{
                arr.insert(arr.begin()+mid+1,i);
                s++;
                break;
            }
        }

        if(s!=i){
            if(beg==0) arr.insert(arr.begin(),i);
            else arr.push_back(i);
            s++;
        }
    }
    f(i,0,arr.size()) cout<<arr[i]<<" "; cout<<endl;
    cin>>med;
    if(med==-1) return;
    
}

int32_t main(){
ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin>>T;
    int n, q;
    cin>>n>>q;
    while(T--){
        clock_t z = clock();
        solve(n, q);
        debug("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }    
}