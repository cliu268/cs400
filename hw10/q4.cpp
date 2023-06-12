// D. Prime Multiples
// https://www.xinyoudui.com/contest?courses=453&books=474&pages=14335&fragments=41283&problemId=14257
/*
Time limit: 1.00 s
Memory limit: 512 MB
You are given k distinct prime numbers a1,a2,…,ak and an integer n.

Your task is to calculate how many of the first n positive integers are divisible by at least one of the given prime numbers.

Input
The first input line has two integers n and k.
The second line has k prime numbers a1,a2,…,ak.

Output
Print one integer: the number integers within the interval 1,2,…,n that are divisible by at least one of the prime numbers.

Constraints
1≤n≤10^18
1≤k≤20
2≤ai≤n

Example Input:
20 2
2 5

Example Output:
12

Explanation: the 12 numbers are 2,4,5,6,8,10,12,14,15,16,18,20.
*/
#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i, a, b) for (ll i=a; i<b; i++)
using namespace std;

ll n, k;
vector<ll> vect(20);
map<ll, bool> visited;
ll solve(ll lower, ll curr, ll num) {
    ll ans=0;
    for (ll i=lower; i<k; i++) {
        if (vect[i]>(n/curr)) {
            continue;
        }
        if (num%2==0) {
            ans+=solve(i+1, curr*vect[i], num+1)+n/(curr*vect[i]);
        }
        else {
            ans+=-n/(curr*vect[i])+solve(i+1, curr*vect[i], num+1);
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for (ll i=0; i<k; i++) {
        cin>>vect[i];
    }
    cout<<solve(0, 1, 0);
}