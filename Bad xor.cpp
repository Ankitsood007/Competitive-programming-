#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 100000007

ll int m1,brr[1050];

// Returns count of subsets of arr[] with XOR value equals
// to k.
ll int subsetXOR(int arr[], int n)
{
    // Find maximum element in arr[]
    int max_ele = arr[0];
    for (int i=1; i<n; i++)
       if (arr[i] > max_ele)
           max_ele = arr[i];

    // Maximum possible XOR value
    long long int m = (1 << (int)(log2(max_ele) + 1) ) - 1;

    // The value of dp[i][j] is the number of subsets having
    // XOR of their elements as j from the set arr[0...i-1]
    ll int dp[1050][1050];

    // Initializing all the values of dp[i][j] as 0
    for (int i=0; i<=n; i++)
        for (int j=0; j<=max(m1,m); j++)
            dp[i][j] = 0;

    // The xor of empty subset is 0
    dp[0][0] = 1;

    // Fill the dp table
    for (int i=1; i<=n; i++)
        for (int j=0; j<=1024; j++)
            dp[i][j] = (dp[i-1][j] + dp[i-1][j^arr[i-1]])%mod;

    //  The answer is the number of subset from set
    //  arr[0..n-1] having XOR of elements as k
    ll int sum =0;
    for(int i=0;i<m1;i++)
    {
    //    cout<<dp[n][brr[i]]<<endl;
    sum = (sum + dp[n][brr[i]])%mod;
    }
    return sum;
}

// Driver program to test above function
int main()
{
    int t;
    cin>>t;
    int test=1;
    while(t--)
    {
        int n;
        cin>>n>>m1;
        int arr[1050];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        for(int i=0;i<m1;i++)
        {
            cin>>brr[i];
        }
        long long int help = 1;
        for(int i=1;i<=n;i++)
        {
           help = (help<<1)%mod;
        }

        long long int result = (help - subsetXOR(arr,n) + mod)%mod;
        cout<<"Case "<<test<<": "<<result<<endl;
        test++;
    }
    return 0;
}

