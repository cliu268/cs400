// A. Exponentiation
// https://www.xinyoudui.com/contest?courses=453&books=474&pages=13493&fragments=35688&problemId=14025
/*
Time limit: 1.00 s
Memory limit: 512 MB
Your task is to efficiently calculate values a^b modulo 10^9+7.

Input
The first input line contains an integer n: the number of calculations.
After this, there are n lines, each containing two integers a and b.

Output
Print each value a^b modulo 10^9+7.

Constraints
1≤n≤2⋅10^5
0≤a,b≤10^9

Example Input:
3
3 4
2 8
123 123

Example Output:
81
256
921450052
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll MOD=1E9+7;
ll bexpo(ll a, ll b) {
    ll ans=1;
    while (b>0) {
        if (b%2==0) {
            a=(a*a)%MOD;
            b/=2;
        }
        else {
            ans=(ans*a)%MOD;
            b--;
            if (b==0) {
                break;
            }
            a=(a*a)%MOD;
            b/=2;
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t; cin>>t;
    while (t--) {
        ll a, b; cin>>a>>b;
        cout<<bexpo(a, b)<<"\n";
    }
}