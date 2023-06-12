// C. Christmas Party
// https://www.xinyoudui.com/contest?courses=453&books=474&pages=14335&fragments=41283&problemId=14164
/*
Time limit: 1.00 s
Memory limit: 512 MB
There are n children at a Christmas party, and each of them has brought a gift. The idea is that everybody will get a gift brought 
by someone else.

In how many ways can the gifts be distributed?

Input
The only input line has an integer n: the number of children.

Output
Print the number of ways modulo 10^9+7.

Constraints
1≤n≤10^6

Example Input:
4

Example Output:
9
*/
#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i, a, b) for (ll i=a; i<b; i++)
using namespace std;

ll MOD=1E9+7;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n; cin>>n;
    vector<ll> fact(n+1); fact[n]=1;
    for (ll i=n-1; i>=0; i--) {
        fact[i]=(fact[i+1]*(i+1))%MOD;
        // cout<<fact[i]<<" ";
    }
    ll ans=0;
    for (ll i=0; i<=n; i++) {
        if (i%2==0) {
            ans=(ans+fact[i]%MOD)%MOD;
        }
        else {
            ans=(ans-fact[i]%MOD)%MOD;
        }
        // cout<<ans<<" ";
    }
    if (ans<0) {
        ans+=MOD;
    }
    cout<<ans;
}