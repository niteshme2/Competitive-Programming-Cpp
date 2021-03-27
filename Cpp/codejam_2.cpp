#include <bits/stdc++.h>

using namespace std;

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define f(i,m, n) for(int i=m;i<n;i++)
#define fr(i, m, n) for(int i=m;i>n;i--)
#define fi(i, m, n) for(int i=m;i<=n;i++)
#define fri(i, m, n) for(int i=m;i>=n;i--)

#define ll long long

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










void solve(int cs){
    int x,y;
    string str;
    int c=0, res=0;
    cin>>x>>y>>str;
    
    int ind1;
    for(ind1=0;ind1<str.length();ind1++)
    {
        if(str[ind1]=='?')
            c++;
    }
    if(c==str.length() || c==str.length()-1)
    {
        cout<<"Case #"<<cs<<":"<<" "<<0<<"\n";
        return;
    }
    
    int ind2;
    for(ind2=0;ind2<str.length()-1;ind2++) if(str[ind2]!='?') break;
    
    if(ind2==0) ind2++;
    ind1=ind2;
    int ind3;
    while(ind1<str.length()-1)
    {
        if(str[ind1]=='?')
        {
            if(str[ind1-1]!=str[ind1+1] && str[ind1+1]!='?')
            {
                if(str[ind1-1]=='J')
                    res+=y;
                else
                    res+=x;
            }
            else if(str[ind1-1]!=str[ind1+1] && str[ind1+1]=='?')
            {
                ind3=ind1+2;
                while(str[ind3]=='?' && ind3<str.length()) ind3++;
                if(ind3==str.length()) break;
                
                if(str[ind1-1]!=str[ind3])
                {
                    if(str[ind1-1]=='J')
                        res+=y;
                    else
                        res+=x;
                }
                ind1=ind3;
            }
        }
        ind1++;
    }
    for(ind1=0;ind1<str.length()-1;ind1++)
    {
        if(str[ind1]=='J' && str[ind1+1]=='C')
            res+=y;
        else if(str[ind1]=='C' && str[ind1+1]=='J')
            res+=x;
    }
    cout<<"Case #"<<cs<<":"<<" "<<res<<"\n";

}

int main(){
ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin>>T;
    int cs=1;
    while(T--){
        clock_t z = clock();
        solve(cs);
        cs++;
        debug("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }    
}