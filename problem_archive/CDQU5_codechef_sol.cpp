#include <bits/stdc++.h>
using namespace std;

unsigned long int func(int X)
{
    
    
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    unsigned long int a=0,b=1,c=1,ans[1000001];
    
    ans[1]=a;
    ans[2]=b;
    ans[3]=c;
    
    for(int i=4;i<=1000000;i++)
    {
        ans[i]=(a+b)%1000000009;
        a=b%1000000009;
        b=c;
        c=ans[i];
    }
    
    int T;
    cin>>T;
    
    while(T--)
    {
        int X;
        cin>>X;
        
        cout<<ans[X]<<endl;
        
    }
	// your code goes here
	return 0;
}