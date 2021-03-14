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


int y_level;

bool compare_x(int a){
    cout<<"? "<<a<<" "<<y_level<<endl;
    //fflush(stdout);

    string s;
    cin>>s;
    if(s == "YES") return true;
    else return false;

}

bool compare_y(int a){

    cout<<"? "<<0<<" "<<a<<endl;
    fflush(stdout);

    string s;
    cin>>s;
    if(s == "YES") return true;
    else return false;

}

int binary_search_y(int min_ind, int max_ind){
    //cout<<"searching..."<<endl;
    //cout<<min_ind<<"-"<<max_ind<<endl;
    if(max_ind - min_ind == 1){
        if(compare_y(max_ind)) return max_ind;
        else return min_ind;
    }

    //cout<<"comparing mid..."<<endl;

    int mid_ind = (min_ind + max_ind)/2;
    //cout<<min_ind<<"+"<<max_ind<<endl;
    //cout<<mid_ind<<endl;
    if(compare_y(mid_ind)){
        return binary_search_y( mid_ind, max_ind);
        
    }
    else{
        return binary_search_y( min_ind, mid_ind);
    }

}

int binary_search_x(int min_ind, int max_ind){
    //cout<<"searching..."<<endl;
    //cout<<min_ind<<" - "<<max_ind<<endl;


    if(max_ind - min_ind == 1){
        if(compare_x(min_ind)) return min_ind;
        else return max_ind;
    }

    //cout<<"comparing mid..."<<endl;

    int mid_ind = (min_ind + max_ind)/2;
    //cout<<min_ind<<"+"<<max_ind<<endl;
    //cout<<mid_ind<<endl;
    if(compare_x(mid_ind)){
        return binary_search_x( min_ind, mid_ind);
        
    }
    else{
        return binary_search_x( mid_ind, max_ind);
    }

}


void solve(){
    
    y_level = 0;

    int box_side = abs(2 * binary_search_x(-1000, 0));
    
    y_level = abs(box_side);

    int half_base = abs(binary_search_x(-1000, 0));
    
    int height = binary_search_y(0, 1000);
    //cout<<"height = "<<height<<endl;
    int height_tri = height - box_side;
    
    int square_area = abs(box_side * box_side);
    //cout<<box_side<<endl;
    //cout<<square_area<<endl;cout<<endl;

    int tri_area = abs(half_base*height_tri);
    //cout<<half_base<<endl;
    //cout<<height<<endl;
    //cout<<height_tri<<endl;
    //cout<<tri_area<<endl;cout<<endl;

    int total_area = square_area + tri_area;
    cout<<"! "<<total_area<<endl;

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    T = 1;
    while(T--){
        clock_t z = clock();
        solve();
        //debug("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }    
}




    