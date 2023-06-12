// B. Exponentiation II
// https://www.xinyoudui.com/contest?courses=453&books=474&pages=13493&fragments=35688&problemId=14160
/*
Time limit: 1.00 s
Memory limit: 512 MB
Your task is to efficiently calculate values a^(b^c) modulo 10^9+7.

Input
The first input line has an integer n: the number of calculations.
Afther this, there are n lines, each containing three integers a, b and c.

Output
Print each value a^(b^c) modulo 10^9+7.

Constraints
1≤n≤10^5
0≤a,b,c≤10^9

Example Input:
3
3 7 1
15 2 2
3 4 5

Example Output:
2187
50625
763327764
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll bexpo(ll a, ll b, ll MOD) {
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
    int t; cin>>t;
    while (t--) {
        ll a, b, c; cin>>a>>b>>c;
        ll exp=bexpo(b, c, 1E9+6);
        cout<<bexpo(a, exp, 1E9+7)<<"\n";
    }
}