#include<bits/stdc++.h>
#define ll long long

using namespace std;

int fun(ll a[],ll n,ll d,ll b){
    if(a[0]>=b){
        return 1;
    }
    ll diff = 0;
    for(ll i=0;i<n;i++){
        diff += b-a[i];
        if(diff> d*(n-i-1)*(i+1)){
            return false;
        }
    }
    return true;
}
int main(){
    
    ll n,d,ans = 0;
    cin>>n>>d;
    ll a[n];
    for(ll i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    ll s = 0,e = 1e9,m;
    while(s<=e){
        m = (s+e)/2;
        if(fun(a,n,d,m)){
            ans = max(ans,m);
            s = m+1;
        }
        else{
            e = m-1;
            
        }
    }
    cout<<ans<<endl;
}
