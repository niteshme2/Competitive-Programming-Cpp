#include <bits/stdc++.h>

using namespace std;

void print_vector(vector<int> a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;

    vector<int> ugly_numbers = vector<int>(n, 0);
    ugly_numbers[0] = 1;
    //cout<<1<<endl;
    int ugly2=0, ugly3=0, ugly5=0, ugly_count=1;

    while(ugly_count < n){
        int next_ugly_num_2 = ugly_numbers[ugly2]*2;
        int next_ugly_num_3 = ugly_numbers[ugly3]*3; 
        int next_ugly_num_5 = ugly_numbers[ugly5]*5; 
        //cout<<ugly2<<ugly3<<ugly5<<endl;
        int next_ugly_num = min(min(next_ugly_num_2, next_ugly_num_3), next_ugly_num_5);
        
        if(next_ugly_num == next_ugly_num_2) ugly2++;
        if(next_ugly_num == next_ugly_num_3) ugly3++;
        if(next_ugly_num == next_ugly_num_5) ugly5++;
        //cout<<ugly_count<<" - ";
        //print_vector(ugly_numbers);
        ugly_numbers[ugly_count] = next_ugly_num;
        ugly_count++;
        //cout<<next_ugly_num<<endl;
        
    }
    cout<<ugly_numbers[n-1]<<endl;

    return 0;
}