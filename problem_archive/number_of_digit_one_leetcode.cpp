#include <bits/stdc++.h>

using namespace std;

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

pair<int, pair<int, int>> full_count(int n){
    cout<<"\nfull_count - "<<n<<endl;
    pair<int, pair<int,int>> temp;
    if(n==0){
        temp.first = 0;
        temp.second.first = 0;
        temp.second.second = 0;
        return temp; 
    }
    if(n==1){
        temp.first = 1;
        temp.second.first = 1;
        temp.second.second = 10;
        return temp;
    }
    pair<int, pair<int, int>> temp2 = full_count(n-1);
    temp.first = 10*temp2.first + temp2.second.second;
    temp.second.first = temp2.second.second + 9*temp2.second.first;
    temp.second.second = temp2.second.second * 10;
    return temp;
}
    
pair<int, pair<int, int>> vec_count(vector<int> num, int ind){
    cout<<"\nind = "<<ind<<endl;
    
    pair<int, pair<int, int>> temp;
    if(ind==num.size()-1){
        cout<<"last Index!"<<endl;
        if(num[ind]==0){
            temp.first = 0;
            temp.second.first = 0;
            temp.second.second = 1;
            cout<<"xr = "<<temp.first<<endl;
            cout<<"mr = "<<temp.second.first<<endl;
            cout<<"totr = "<<temp.second.second<<endl;
            return temp;
        }
        else{
            temp.first = 1;
            temp.second.first = 1;
            temp.second.second = num[ind]+1;
            cout<<"xr = "<<temp.first<<endl;
            cout<<"mr = "<<temp.second.first<<endl;
            cout<<"totr = "<<temp.second.second<<endl;
            return temp;
        }
        
    }
    
    cout<<"not_last index."<<endl;
    if(num[ind]==0){
        
        pair<int, pair<int, int>> temp2 = vec_count(num, ind+1);
        cout<<"x1 = "<<temp2.first<<endl;
        cout<<"m1 = "<<temp2.second.first<<endl;
        cout<<"tot1 = "<<temp2.second.second<<endl;
        temp.first = temp2.first;
        temp.second.first = temp2.second.first;
        temp.second.second = temp2.second.second;

        
        cout<<"xr = "<<temp.first<<endl;
        cout<<"mr = "<<temp.second.first<<endl;
        cout<<"totr = "<<temp.second.second<<endl;
        cout<<endl;
        return temp;
    }
    else if(num[ind]==1){
        
        pair<int, pair<int, int>> temp2 = vec_count(num, ind+1);
        cout<<"x1 = "<<temp2.first<<endl;
        cout<<"m1 = "<<temp2.second.first<<endl;
        cout<<"tot1 = "<<temp2.second.second<<endl;
        temp.first = temp2.first + temp2.second.second;
        temp.second.first = temp2.second.second;
        temp.second.second = temp2.second.second;

        temp2 = full_count(num.size() - ind -1);
        temp.first += temp2.first;
        temp.second.first += temp2.second.first;
        temp.second.second += temp2.second.second;
        cout<<"xr = "<<temp.first<<endl;
        cout<<"mr = "<<temp.second.first<<endl;
        cout<<"totr = "<<temp.second.second<<endl;
        cout<<endl;
        return temp;
    }
    else{
        pair<int, pair<int, int>> temp2 = full_count(num.size() - ind -1);
        int p = num[ind] - 1;
        cout<<"xf = "<<temp2.first<<endl;
        cout<<"mf = "<<temp2.second.first<<endl;
        cout<<"totf = "<<temp2.second.second<<endl;
        temp.first = p*(temp2.first) + temp2.first + temp2.second.second;
        temp.second.first = temp2.second.second + p*temp2.second.first;
        temp.second.second = (p+1)*temp2.second.second;
        
        
        temp2 = vec_count(num, ind + 1);
        cout<<"x2 = "<<temp2.first<<endl;
        cout<<"m2 = "<<temp2.second.first<<endl;
        cout<<"tot2 = "<<temp2.second.second<<endl;
        temp.first += temp2.first;
        temp.second.first += temp2.second.first;
        temp.second.second += temp2.second.second;
        cout<<"xr = "<<temp.first<<endl;
        cout<<"mr = "<<temp.second.first<<endl;
        cout<<"totr = "<<temp.second.second<<endl;
        cout<<endl;
        return temp;
    }

}
    
int countDigitOne(int n) {
    pair<int, pair<int,int>> temp;
    
    vector<int> num;
    while(n>0){
        num.insert(num.begin(), n%10);
        n = n/10;
    }
    temp = vec_count(num, 0);
    cout<<"\n\nx_ans = "<<temp.first<<endl;
    cout<<"m_ans = "<<temp.second.first<<endl;
    cout<<"tot_ans = "<<temp.second.second<<endl;
    return temp.first;
    
    }


int main(){
    int T;
    cin>>T;
    clock_t z = clock();
    while(T--){
        
       int n;
       cin>>n;
       //cout<<n;
       cout<<countDigitOne(n)<<endl;
        
    }
    debug("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);    
}