// B. Candy Lottery
// https://www.xinyoudui.com/contest?courses=453&books=474&pages=14234&fragments=40471&problemId=14170
/*
Time limit: 1.00 s
Memory limit: 512 MB
There are n children, and each of them independently gets a random integer number of candies between 1 and k.
What is the expected maximum number of candies a child gets?

Input
The only input line contains two integers n and k.

Output
Print the expected number rounded to six decimal places.

Constraints
1≤n≤100
1≤k≤100

Example Input:
2 3

Example Output:
2.444444
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    double n, k; cin>>n>>k;
    double ans=0;
    vector<double> dp(k+1, 0);
    for (double j=k; j>=1; j--) {
        dp[j]=j;
        double prob=1;
        for (int x=0; x<n; x++) {
            prob*=(j/k);
        }
        double nope=1;
        for (int x=0; x<n; x++) {
            nope*=(j-1)/k;
        }
        prob-=nope;
        dp[j]*=prob;
        ans+=dp[j];
    }
    printf("%.6f", ans);
}