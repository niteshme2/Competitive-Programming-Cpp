#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define fo(i,n) for(int i=0;i<=n;i++)
#define ll long long 

ll DP[10][90][2];

vector<int> num;


ll sum_digits(int pos, ll sum, int tight){
    
    //cout<<"     "<<pos<<"/"<<num.size()<<"\n";
    if(pos == num.size()) return sum;
    if(DP[pos][sum][tight]!=-1) return DP[pos][sum][tight];
    
    int lim = 0;
    if(tight == 0)
        lim = num[pos];
    else lim = 9;
    ll ans = 0;
    
    fo(dig,lim){
        if(dig == lim && tight == 0)
            ans += sum_digits(pos+1, sum+dig, 0);
        else ans += sum_digits(pos+1, sum+dig, 1);
    }
    //cout<<"     pos,sum-"<<pos<<","<<sum<<" = "<<ans<<endl;
    DP[pos][sum][tight] = ans;
    return ans;
    
} 

ll solve1(int a){
    if(a<=0){
        return 0;
    }
    //cout<<"doing "<<a<<"..."<<endl;
    num.clear();
    while(a != 0){
        num.push_back(a%10);
        //cout<<a<<endl;
        a /= 10;
    }
    memset(DP, -1, sizeof(DP));
    reverse(num.begin(), num.end());
    //cout<<"going in sum_digits....\n";
    ll ans = sum_digits(0,0,0);
    
    return ans;
}

void solve(){

    while(true){
        int a, b;
        cin>>a>>b;
        //cout<<a<<" "<<b<<endl;
        ll a_sum = solve1(a-1);
        //cout<<"a_sum = "<<a_sum<<", ";
        ll b_sum = solve1(b);
        //cout<<"b_sum = "<<b_sum<<" = ";
        if(a != -1 && b != -1)
            cout<<b_sum - a_sum<<"\n";
        else break;

    }

}



int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    clock_t z = clock();
    solve();
    //debug("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
           
}