    #include <bits/stdc++.h>

    using namespace std;

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

    void longestCommonSubsequence(string text1, string text2) {
            int n, m;
            n = text1.size();
            m = text2.size();
            vector< vector<int>> DP(n, vector<int>(m, 0));
            
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

        

            for(int i=1;i<n;i++){
                
                for(int j=1;j<m;j++){
                    if(text1[i] == text2[j]) 
                        DP[i][j] = 1 + DP[i-1][j-1];
                    else DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
                }
            }

            

            
            //cout<<"retrieving..."<<endl;
            int count = DP[n-1][m-1] - 1;
            
            vector<char> z(count+1);
            vector<int> p(count+1);
            vector<int> q(count+1);
            int i=n-1, j=m-1;
            while(count >= 0){
                //cout<<count<<" "<<i<<" "<<j<<" - ";
                if(text1[i] == text2[j]){
                    z[count] = text1[i];
                    //cout<<z[count]<<" "<<p[count]<<" "<<q[count]<<endl;
                    p[count] = i;
                    q[count] = j;
                    //cout<<z[count]<<" "<<p[count]<<" "<<q[count]<<endl;
                    i--;
                    j--; 
                    count--;
                }
                else{
                    if(i == 0 && j == 0){
                        
                    }
                    else if(i==0){
                        if(DP[0][j] >= DP[0][j-1]){
                            j--; 
                        }
                    }
                    else if(j==0){
                        if(DP[i][0] >= DP[i-1][0]){
                            i--; 
                        }
                    }
                    else if(DP[i-1][j] > DP[i][j-1]){
                        i--; 
                    }
                    else{
                        j--; 
                    }
                } 
                //cout<<endl;
            }
            
            count = DP[n-1][m-1];
            if(count>1){
                printf("Y\n%d\n", count);
            }
            else{
                printf("N\n");
                //cout<<count<<endl;
                return;
            }
            for(int i=0;i<count;i++){
                cout<<z[i]<<" "<<p[i]+1<<" "<<q[i]+1<<endl;
            }
            
        }



    int main(){
        int T;
        cin>>T;
        clock_t z = clock();
        for(int t=0;t<T;t++){
            
		
            int n,m;
            string s1, s2;
            cin>>n>>s1>>m>>s2;
            printf("case %d ", t+1);
            longestCommonSubsequence(s1, s2);
            
            
        }
        debug("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
            
    }