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
    int N;
    cin>>N;
    vii points(N);
    f(i, 0, N) cin>>points[i].first>>points[i].second;

    sort(points.begin(), points.end());

    vi next_left(N, -1), next_right(N, -1);

    stack<int> stk;

    f(i, 0, N){
        if(stk.empty()) stk.push(i);
        else{
            if(points[stk.top()].second <= points[i].second){
                stk.push(i);
            }
            else{
                while(!stk.empty() && points[stk.top()].second > points[i].second){
                    next_right[stk.top()] = i;
                    stk.pop();
                }
                stk.push(i);
            }
        }
    }

    stk = stack<int>();

    fri(i, N-1, 0){
        if(stk.empty()) stk.push(i);
        else{
            if(points[stk.top()].second <= points[i].second){
                stk.push(i);
            }
            else{
                while(!stk.empty() && points[stk.top()].second > points[i].second){
                    next_left[stk.top()] = i;
                    stk.pop();
                }
                stk.push(i);
            }
        }
    }

    //f(i, 0, N) cout<<next_left[i]<<" ";cout<<endl; 
    //f(i, 0, N) cout<<next_right[i]<<" ";cout<<endl; 


    int max_area = 0;
    f(i, 0, N){
        int height = points[i].second;
        int width;

        int left_point = next_left[i];
        if(left_point == -1) left_point = 0;
        else left_point = points[left_point].first;

        int right_point = next_right[i];
        if(right_point == -1) right_point = 100000;
        else right_point = points[right_point].first;

        width = right_point - left_point;

        int area = width*height;
        max_area = max(area, max_area);
    }
    //cout<<max_area<<endl;

    max_area = max(500*points[0].first, max_area);
    f(i, 0, N-1){
        max_area = max(500*(points[i+1].first - points[i].first), max_area);
    }
    max_area = max(500*(100000 - points[N-1].first), max_area);
    
    cout<<max_area<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    T=1;
    while(T--){
        clock_t z = clock();
        solve();
        debug("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }    
}




    