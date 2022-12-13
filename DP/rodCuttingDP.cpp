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

//similar to knapsack(unbound knapsack)
// length = item weight
// price = profit
// maxLen = max rod size = knapsack size(W)
// N = 
int rodCuttingTabular(int length[], int price[], int maxLen, int N){
    int dp[N+1][maxLen+1];

    for(int i=0; i<=N; i++){
        for(int j=0; j<=maxLen; j++){
            if(i==0 || j==0) dp[i][j] = 0;
            else if(length[i-1] > j){   //check current length of cutting point is greater than current capasity
                //then exclude
                dp[i][j] = dp[i-1][j];
            }
            else {
                int include = price[i-1] + dp[i][j-length[i-1]];
                int exclude = dp[i-1][j];
                dp[i][j] = max(include,exclude);
            }
        }
    }

    return dp[N][maxLen];
}


int main()
{
    fastIO
    #ifndef ONLINE_JUDGE
        fileIO
    #endif
    
    int n; cin>>n;
    int length[n],price[n];
    for(int i=0;i<n;i++) {
        cin>>price[i];
        length[i] = i+1;
    }
    cout<<rodCuttingTabular(length,price,n,n)<<endl;
    
    return 0;
}

