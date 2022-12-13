#include <bits/stdc++.h>
using namespace std;
void solve();

#define mod							1000000007
#define INF                         1000000000
#define ll							long long
#define pi							acos(-1)
#define setzero(a)				    memset(a,0,sizeof(a))
#define pb(a)						push_back(a)
#define fastIO ios_base::sync_with_stdio(true); cin.tie(NULL);
#define fileIO  freopen("input.txt", "r", stdin); \
                             freopen("output.txt", "w", stdout);


//tabular method
//tutorial link : https://www.youtube.com/watch?v=ZI17bgz07EE

int coinChangeTabular(int A, int coin[], int n){
    int dp[n+1][A+1];
    for(int i=1;i<=A;i++) dp[0][i] = INF; 
    for(int i=0;i<=n;i++) dp[i][0] = 0;

    for(int c=1; c<=n; c++){
        for(int a=1; a<=A; a++){
            if(coin[c-1] > a){
                dp[c][a] = dp[c-1][a];
            }
            else {
                int include = 1 + dp[c][a-coin[c-1]];
                int exclude = dp[c-1][a];
                dp[c][a] = min(include,exclude);
            }
        }
    }

    //printing the dp
    // for(int c=0; c<=n; c++){
    //     for(int a=0; a<=A; a++){
    //         cout<<dp[c][a]<<" ";
    //     }
    //     cout<<endl;
    // }

    //finding the coins used
    cout<<"Total Coin: "<<dp[n][A]<<endl;
    cout<<"Coins are: ";

    int i=n, j=A;

    while(dp[i][j] != 0){
        if(dp[i-1][j] != dp[i][j]){
            cout<<coin[i-1]<<" ";
            j = j - coin[i-1];
        }
        else {
            i--;
        }
    }

    return dp[n][A];
}

//recursive approach

ll coinChangeDPrecursive(int A, int coin[], int i, int n){
    if(A == 0) return 0;
    if(A < 0 || i == n) return INF;

    ll res_1 = 1 + coinChangeDPrecursive(A - coin[i], coin, i, n);
    ll res_2 = coinChangeDPrecursive(A, coin, i + 1, n);

    return (ll) min(res_1,res_2);
}

int main()
{
    fastIO
    #ifndef ONLINE_JUDGE
        fileIO
    #endif
    
    int A,n; cin>>A>>n;
    int coin[n];
    for(int i=0;i<n;i++) cin>>coin[i];
    coinChangeTabular(A,coin,n);
    
    return 0;
}
