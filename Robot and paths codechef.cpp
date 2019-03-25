#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007

ll m,n,p,dp[2000][2000],memo[2010][2010];

ll robot_path(ll i,ll j)
{
    if(memo[i][j]!=-1)
    {
        return memo[i][j];
    }

    if(i==m||j==n)
    {
        return 0;
    }
    if(dp[i][j]==1)
    {
        return 0;
    }
    if(i==m-1&&j==n-1)
    {
        return 1;
    }

    ll ans = ((robot_path(i+1,j))%MOD + (robot_path(i,j+1)%MOD))%MOD;
     memo[i][j] = ans;
     return ans;
}

int main()
{
    memset(dp,0,sizeof(dp));
    memset(memo,-1,sizeof(memo));
    cin>>m>>n>>p;
    ll support = p;

    while(support--)
    {
        ll x,y;
        cin>>x>>y;
        dp[x-1][y-1]= 1;
    }

    /*for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    cout<<robot_path(0,0)<<endl;
    return 0;
}
