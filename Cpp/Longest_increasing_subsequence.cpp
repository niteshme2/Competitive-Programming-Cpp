#include <bits/stdc++.h>

using namespace std;

void print_vector(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int T;
    cin>>T;
    while(T--){
       //cout<<"T = "<<T<<endl;
        int n;
        cin>>n;
        //cout<<"  "<<n<<endl;
        vector<int> arr(n, 0);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        //cout<<"  ";
        //print_vector(arr);
        //cout<<endl;
        vector<int> DP(n, 0);
        DP[0] = 1;

        for(int i=1;i<n;i++){
            int max = 0;
            for(int j=0;j<i;j++){
                //cout<<"j = "<<j<<" ";
                if(arr[i] >= arr[j]){
                    //cout<<"_1 ";
                    if(DP[j]+1 > max){
                        //cout<<"2 _";
                        max = DP[j] + 1;
                        //cout<<max<<"_";
                    }
                }
            }
            //cout<<endl;
            if(1 > max)
                max = 1;
            DP[i] = max;
        }

        //print_vector(DP);
        cout<<*max_element(DP.begin(), DP.end())<<endl;
        
    }
        
}

/*
ideas:
1. global DP, for speed.
2. filling DP while reading input
*/