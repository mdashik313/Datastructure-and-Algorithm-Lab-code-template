#include <bits/stdc++.h>
using namespace std;

#define mod							1000000007;
#define ll							long long
#define pi							acos(-1)
#define setzero(a)				    memset(a,0,sizeof(a))
#define pb(a)						push_back(a)
#define fastIO ios_base::sync_with_stdio(true); cin.tie(NULL);
#define fileIO  freopen("input.txt", "r", stdin); \
                             freopen("output.txt", "w", stdout);

// W = knapsack capasity
// N = number of items
int knapsackTabular(int wt[], int profit[], int W, int N){
    int dp[N+1][W+1];

    for(int i=0; i<=N; i++){
        for(int j=0; j<=W; j++){
            if(i==0 || j==0) dp[i][j] = 0;
            else if(wt[i-1] > j){   //check current weight of item is greater than current capasity
                //then exclude
                dp[i][j] = dp[i-1][j];
            }
            else {
                int include = profit[i-1] + dp[i-1][j-wt[i-1]];
                int exclude = dp[i-1][j];
                dp[i][j] = max(include,exclude);
            }
        }
    }

    return dp[N][W];
}


int main()
{
    fastIO
    #ifndef ONLINE_JUDGE
        fileIO
    #endif
    
    int W,n; cin>>W>>n;
    int wt[n],profit[n];
    for(int i=0;i<n;i++) cin>>wt[i];
    for(int i=0;i<n;i++) cin>>profit[i];
    cout<<knapsackTabular(wt,profit,W,n)<<endl;
    
    return 0;
}

