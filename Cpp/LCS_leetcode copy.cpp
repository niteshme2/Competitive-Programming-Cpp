#include <bits/stdc++.h>

using namespace std;

void print_vector(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int longestCommonSubsequence(string text1, string text2) {
        int n, m;
        n = text1.size();
        m = text2.size();
        vector< vector<int>> DP(n, vector<int>(m, 0));
        cout<<"DP:"<<endl;
        for(int i=0;i<n;i++){
            print_vector(DP[i]);
        }
        if(text1[0] == text2[0]) DP[0][0] = 1;
        for(int i=1;i<n;i++){
            if(text1[i] == text2[0]) 
                DP[i][0] = 1;
            else DP[i][0] = DP[i-1][0];


        }
        for(int i=1;i<m;i++){
            if(text1[0] == text2[i]) 
                DP[0][i] = 1;
            else DP[0][i] = DP[0][i-1];
        }

        cout<<"DP:"<<endl;
        for(int i=0;i<n;i++){
            print_vector(DP[i]);
        }

        for(int i=1;i<n;i++){
            
            for(int j=1;j<m;j++){
                if(text1[i] == text2[j]) 
                    DP[i][j] = 1 + DP[i-1][j-1];
                else DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
            }
        }

        cout<<"DP:"<<endl;
        for(int i=0;i<n;i++){
            print_vector(DP[i]);
        }

        return DP[n-1][m-1];

    }

int main(){
    int T;
    cin>>T;
    while(T--){
        int n,m;
        string s1, s2;
        cin>>n>>s1>>m>>s2;
        cout<<n<<endl;
        cout<<s1<<endl;
        cout<<m<<endl;
        cout<<s2<<endl;
        cout<<longestCommonSubsequence(s1, s2);

        
    }
        
}