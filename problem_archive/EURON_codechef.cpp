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


ll total_violations = 0;


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


void merge(vi &arr, int start1, int end1, int start2, int end2){
    vi temp(end1 + end2 - start1 - start2 + 2);
    int ind1 = start1, ind2 = start2, ind_temp=0;
    while(ind1 <= end1 || ind2 <= end2){
        if(ind1 <= end1 && (arr[ind1] <= arr[ind2] || ind2 > end2)){
            temp[ind_temp] = arr[ind1];
            ind1++;
        }
        else if(ind2 <= end2 && (arr[ind2] < arr[ind1] || ind1 > end1)){
            temp[ind_temp] = arr[ind2];
            ind2++;
            total_violations += end1 - ind1 >= 0 ? end1 - ind1 + 1 : 0;
        }
        ind_temp++;
    }

    ind1 = start1;
    ind2 = start2;
    ind_temp=0;
    while(ind1 <= end1 || ind2 <= end2){
        if(ind1 <= end1){
            arr[ind1] = temp[ind_temp];
            ind1++;
        }
        else{
            arr[ind2] = temp[ind_temp];
            ind2++;
        }

        ind_temp++;

    }

    

}


void merge_sort(vi &arr, int start, int end){
    
    if( end - start == 0) return;

    merge_sort( arr, start, (start+end)/2 );
    merge_sort( arr, (start+end)/2+1, end );
    merge(arr, start, (start+end)/2, (start+end)/2+1, end);
    
}





void solve(){
    int n;
    cin>>n;
    vi arr(n);
    f(i, 0, n) cin>>arr[i];
    
    merge_sort(arr, 0, n-1);
    //f(i, 0, n) cout<<arr[i]<<" ";cout<<endl;    
    cout<<total_violations<<endl;


}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    T = 1;
    while(T--){
        clock_t z = clock();
        solve();
        debug("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }    
}




    