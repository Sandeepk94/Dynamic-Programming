#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define _ ios::sync_with_stdio(false);
#define mem(x,a) memset(x,(a),(int)(sizeof(x)))
#define pii pair<int,int>
#define fr(i,a,n) for(int i=(a);i<=(n);i++)
#define frd(i,a,n) for(int i=(a);i>=(n);i--)
#define nl cout<<endl
#define sp cout<<" "
#define pb push_back
#define mp make_pair 
#define F first 
#define S second
#define si size()
#define V vector
ll mod=1e9+7;
int n,q,d,m;
int dp[205][21][21],a[205];
int find(int idx,int rem_elem,int sum)
{
   //cout<<idx<<" "<<rem_elem<<" "<<sum<<endl;
   if(rem_elem ==0 && sum==0)return 1;
   else if((idx<=0 && rem_elem) || (rem_elem<=0 && sum))return 0;
   else if(dp[idx][rem_elem][sum])return dp[idx][rem_elem][sum];
   else
   {
      for(int i=idx;i>=1;i--)
      {
         dp[idx][rem_elem][sum]+=find(i-1,rem_elem-1,(sum-a[i]+d)%d);
         //cout<<dp[idx][rem_elem][sum]<<endl;
      }
      return dp[idx][rem_elem][sum];
   }
}
int main() {_
   int T=1,t=1;
   while(cin>>n>>q)
   {
      if(n==0 && q==0)break;
      cout<<"SET "<<T++<<":\n";
      t=1;
      fr(i,1,n)cin>>a[i];
      fr(i,1,q)
      {
         cin>>d>>m;
         mem(dp,0);
         fr(i,0,n)dp[i][0][0]=1;
         dp[n][m][0]=find(n,m,0);
         cout<<"QUERY "<<t++<<": ";
         cout<<dp[n][m][0]<<endl;
      }
   }
   return 0;
}