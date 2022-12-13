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


bool subsetSum_recursive(int set[], int sum, int n){
    if(sum==0) return true;   //here n = number of element left(baki)
    if(n == 0 ) return false;

    //base case
    if(set[n-1] > sum) {
        return subsetSum_recursive(set, sum, n-1); //exclude
                                 //n-1,because elements start from 0 index
    }
    else {
        //consider both case(include,exclude) and if any one is ture return true otherwise false
        bool include = subsetSum_recursive(set, sum-set[n-1], n-1);
        bool exclude = subsetSum_recursive(set, sum, n-1);
        return include || exclude;
    }

}

void subsetSum_tabular(int set[], int sum, int n){
    bool dp[n+1][sum+1];
    for(int i=0; i<=n; i++) dp[i][0] = true;
    for(int j=1; j<=sum; j++) dp[0][j] = false;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            
            if(set[i-1] > j) {
                dp[i][j] = dp[i-1][j]; //exclude
                                            //n-1,because elements start from 0 index
            }
            else {
                bool include = dp[i-1][j-set[i-1]];
                bool exclude = dp[i-1][j];
                if(include || exclude) dp[i][j] = true;
                else dp[i][j] = false;
            }
        }
    }

    //printing the subset(if sum is possible)
    if(dp[n][sum]){
        cout<<"True\n";
        int i=n, j=sum;

        while(dp[i][j] != false){
            if(dp[i][j]==dp[i-1][j]){
                i--;
            }
            else{
                cout<<set[i-1]<<" ";
                j = j - set[i-1];
                i--;
            }
            if(i==0 && j==0) break;
        }
        return;
    }    
    cout<<"False\n";
}


int main()
{
    fastIO
    #ifndef ONLINE_JUDGE
        fileIO
    #endif
    
    int n,sum; cin>>n;
    int set[n];
    for(int i=0; i<n; i++) cin>>set[i];
    cin>>sum;

    subsetSum_tabular(set,sum,n);
    
    return 0;
}
