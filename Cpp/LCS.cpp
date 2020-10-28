#include <bits/stdc++.h>

using namespace std;

vector< vector<int>> DP(1000, vector<int>(1000, 0));
vector<int> x_sol(1000, 0);
vector<int> y_sol(1000, 0);

void print_vector(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

pair<int, string> longestCommonSubsequence(string text1, string text2, int n, int m) {

        pair<int, string> ans;
        if(n==0 && m==0){
            if(text1[0] == text2[0]){
                ans.first = 1;
                ans.second = text1[0];
            }
            else{
                ans.first = 0;
                ans.second = "";
            }
            return ans;
        }

        if(n==0){
            if(text1[0] == text2[m]){
                ans.first = 1;
                ans.second = text1[0];
            }
            else{
                ans = longestCommonSubsequence(text1, text2, 0, m-1);
            }
            return ans;
        }
        if(m==0){
            if(text1[n] == text2[0]){
                ans.first = 1;
                ans.second = text2[0];
            }
            else{
                ans = longestCommonSubsequence(text1, text2, n-1, 0);
            }
            return ans;
        }
        
        if(text1[n] == text2[m]){
            ans.first = 1 + longestCommonSubsequence(text1, text2, n-1, m-1);
            ans.second = text2[0];
        }
        else{
            ans = longestCommonSubsequence(text1, text2, n-1, 0);
        }
        return ans;

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