// A. Dice Probability
// https://www.xinyoudui.com/contest?courses=453&books=474&pages=14234&fragments=40471&problemId=14168
/*
Time limit: 1.00 s
Memory limit: 512 MB
You throw a dice n times, and every throw produces an outcome between 1 and 6. What is the probability that the sum of outcomes is 
between a and b?

Input
The only input line contains three integers n, a and b.

Output
Print the probability rounded to six decimal places.

Constraints
1≤n≤100
1≤a≤b≤6n

Example Input:
2 9 10

Example Output:
0.194444
*/
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i=a; i<b; i++)
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b; cin>>n>>a>>b;
    vector<vector<double>> dp(n+1, vector<double>(601, 0));
    for (int i=1; i<=6; i++) {
        dp[1][i]=(double)1/6;
    }
    for (int i=2; i<=n; i++) {
        for (int j=i; j<=6*i; j++) {
            for (int k=1; k<min(7, j); k++) {
                dp[i][j]+=dp[i-1][j-k]*(double)1/6;
            }
        }
    }
    double ans=0;
    for (int i=a; i<=b; i++) {
        ans+=dp[n][i];
        // cout<<dp[n][i]<<" ";
    }
    printf("%.6f", ans);
}