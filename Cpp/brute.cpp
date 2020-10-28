#include <bits/stdc++.h>

using namespace std;

bool isUgly(int num) {
        if(num<=0) return false;
    
    while(num>1){
        if(num%2==0) num/=2;
        else if(num%3==0) num/=3;
        else if(num%5==0) num/=5;
        else return false;
    }
        return true;
    
}

int main(){

    int n;
    cin>>n;
    vector<int> ugly_nums = vector<int>(n, 0);
    ugly_nums[0] = 1;
    //cout<<1<<endl;
    int ugly_count = 1;
    int num = 1;
    while (ugly_count < n){
        num++;
        int num_is_ugly = isUgly(num);
        if(num_is_ugly){
            ugly_nums[ugly_count] = num;
            ugly_count++;
            //cout<<num<<endl;
        }
    }
    cout<<ugly_nums[n-1]<<endl;

    return 0;
    
}