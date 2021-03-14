#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int start=0;int end=0;
          ll tot=a[0];
             ll ma=a[0];vector<pair<int,int>>v;v.push_back({0,0});
          for(int i=1;i<n;i++)
          {
              if(tot>=0)
              {
                  tot+=a[i];end=i;
                
              }
              else
              {
                  start=i;tot=a[i];
                  end=i;
              }
           
           if(tot>ma)
           {
               while(v.empty()==false)
               {
                   v.pop_back();
               }
               v.push_back({start,end});
           }
           else if(tot==ma)
           {
               v.push_back({start,end});
           }
            ma=max(tot,ma);
          }


          for(int i=0;i<v.size();i++)
          {
              int p1=v[i].first;int p2=v[i].second;
              if(p2-p1>=1)
              {int val=INT_MAX;ll sum=0;
                 for(int k=p1;k<=p2;k++)
                 {sum+=a[k];
                   val=min(val,a[k]);
                 }

                 if(val<0)
                 {
                     ma=max(ma,sum-val);
                 }
              }
          } 
          cout<<ma<<endl;
    }

}