#include <bits/stdc++.h>
using namespace std;

void rodCuttingTabular(int length[], int price[], int maxLen, int N){
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

    int i=N, j=maxLen;
    cout<<"income "<<dp[i][j]<<" taka\n";
    while(dp[i][j] != 0){
            if(dp[i][j]==dp[i-1][j]){
                i--;
            }
            else{
                cout<<length[i-1]<<" pieces together "<<price[i-1]<<" taka\n";
                j = j - length[i-1];
            }
    }
}


int main()
{
    int n; cin>>n;
    int length[n],price[n];
    for(int i=0;i<n;i++) {
        cin>>price[i];
        length[i] = i+1;
    }
    rodCuttingTabular(length,price,n,n);
    
    return 0;
}

