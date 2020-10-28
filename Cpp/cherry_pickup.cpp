#include <bits/stdc++.h>

using namespace std;

int cherryPicked(vector<vector<int>>& grid){
    int N = grid.size();
    int prev1, prev2, prev3, prev4;        
    vector< vector< vector<int>>> DP(N, vector<vector<int>>(N, vector<int>(N, -2)));
    //cout<<DP.size()<<" "<<DP[0].size()<<" "<<DP[0][0].size()<<endl;
    
    DP[0][0][0] = grid[0][0];
    cout<<"DP["<<0<<"]["<<0<<"]["<<0<<"] = "<<DP[0][0][0]<<endl;
     for(int j=1; j<N; j++){
        int i = 0;
        int k = 0;
        if(DP[i][j-1][k] == -1 || grid[i][j] == -1)
            DP[i][j][k] = -1;
        else{
            DP[i][j][k] = DP[i][j-1][k] + grid[i][j];
        }
        cout<<"DP["<<i<<"]["<<j<<"]["<<k<<"] = "<<DP[i][j][k]<<endl;
        
    }
    cout<<"1-loop"<<endl;
    for(int i=1; i<N; i++){
        int j = 0;
        int k = i;
        if(DP[i-1][j][k-1] == -1 || grid[i][j] == -1)
            DP[i][j][k] = -1;
        else{
            DP[i][j][k] = DP[i-1][j][k-1] + grid[i][j];
        }
        cout<<"DP["<<i<<"]["<<j<<"]["<<k<<"] = "<<DP[i][j][k]<<endl;
        
    }

    cout<<"2-loop"<<endl;

    for(int i=1; i<N; i++){
        //cout<<i<<" ";
        int j = 0;
        int k = j;
        if(DP[i-1][j][k] == -1 || grid[i][j] == -1 || grid[k][i+j-k] == -1)
            DP[i][j][k] = -1;
        else{
            DP[i][j][k] = DP[i-1][j][k] + grid[i][j] + grid[k][i+j-k];
        }
        cout<<"DP["<<i<<"]["<<j<<"]["<<k<<"] = "<<DP[i][j][k]<<endl;
        
    }
  
    cout<<"3-loop"<<endl;


    for(int j=1; j<N; j++){
        cout<<j<<" ";
        int i = 0;
        int k = j;
        if(DP[i][j-1][k-1] == -1 || grid[i][j] == -1  || grid[k][i+j-k] == -1)
           DP[i][j][k] = -1;
        else{
           DP[i][j][k] = DP[i][j-1][k-1] + grid[i][j] + grid[k][i+j-k];
        }
        cout<<"DP["<<i<<"]["<<j<<"]["<<k<<"] = "<<DP[i][j][k]<<endl;
        
    }

    cout<<"4-loop"<<endl;
   
    for(int i=1; i<N; i++){
        for(int j=1; j<N; j++){
            for(int k=max(0, i+j-N+1); k<=min(N-1, i+j); k++){
                
                if(i+j-k-1 >= 0){
                    prev1 = DP[i-1][j][k];
                    cout<<"["<<i-1<<"]["<<j<<"]["<<k<<"]-"<<prev1<<"  ";
                    prev3 = DP[i][j-1][k];
                    cout<<"["<<i<<"]["<<j-1<<"]["<<k<<"]-"<<prev3<<"  ";
                }
                else{
                    prev1 = -1;
                    cout<<"["<<i-1<<"]["<<j<<"]["<<k<<"]-"<<prev1<<"  ";
                    prev3 = -1;
                    cout<<"["<<i<<"]["<<j-1<<"]["<<k<<"]-"<<prev3<<"  ";
                }
                
                if(k-1 >= 0){
                    prev2 = DP[i-1][j][k-1];
                    cout<<"["<<i-1<<"]["<<j<<"]["<<k-1<<"]-"<<prev2<<"  ";
                    prev4 = DP[i][j-1][k-1];
                    cout<<"["<<i<<"]["<<j-1<<"]["<<k-1<<"]-"<<prev4<<"  ";
                }
                    
                else{
                    prev2 = -1;
                    cout<<"["<<i-1<<"]["<<j<<"]["<<k-1<<"]-"<<prev2<<"  ";
                    prev4 = -1;
                    cout<<"["<<i<<"]["<<j-1<<"]["<<k-1<<"]-"<<prev3<<"  ";
                } 
                    
                //cout<<prev1<<","<<prev2<<","<<prev3<<","<<prev4<<" - ";
                
                    
                if(grid[i][j] == -1 || grid[k][i+j-k] == -1){ 
                    cout<<"gird[i][j] = -1"<<endl;
                    DP[i][j][k] = -1;
                }
                else{
                    int curr_cherry = 0;
                    if(max({prev1, prev2, prev3, prev4}) == -1)
                        DP[i][j][k] = -1;
                    else
                        if(k==i)
                            DP[i][j][k] = max({prev1, prev2, prev3, prev4}) + grid[i][j];
                        else
                            DP[i][j][k] = max({prev1, prev2, prev3, prev4}) + grid[i][j] + grid[k][i+j-k];
                }
                cout<<"      DP["<<i<<"]["<<j<<"]["<<k<<"] = "<<DP[i][j][k];
                int temp = DP[i][j][k];
                DP[k][i+j-k][i] = temp;
                cout<<"      DP["<<k<<"]["<<i+j-k<<"]["<<i<<"] = "<<DP[k][i+j-k][i]<<endl;
            }
                
        }
            
    }
    
    cout<<"\nFull DP:"<<endl;
    for(int i=0;i<N;i++){
        cout<<DP[i][i][i]<<endl;
    }

    int ans = DP[N-1][N-1][N-1];

    if(ans==-1){
        ans = 0;
    }

    return ans;    
}

int main(){
    int n;
    cin>>n;
    //cout<<"n = "<<n<<endl;
    //cout<<"input..."<<endl;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
            //cout<<"input - "<<i<<" "<<j<<endl;
        }
        //cout<<i<<endl;
    }

    cout<<"grid=\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<grid[i][j]<<" ";
        cout<<endl;
    }
    cout<<"...........\n";
    int ans = cherryPicked(grid);

    cout<<"cherries_picked = "<<ans<<endl;
        
}