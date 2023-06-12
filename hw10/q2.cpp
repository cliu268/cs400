// B. Polygon Area
// https://www.xinyoudui.com/contest?courses=453&books=474&pages=14335&fragments=41283&problemId=14262
/*
Time limit: 1.00 s
Memory limit: 512 MB
Your task is to calculate the area of a given polygon.

The polygon consists of n vertices (x1,y1),(x2,y2),…,(xn,yn). The vertices (xi,yi) and (xi+1,yi+1) are adjacent for i=1,2,…,n−1, 
and the vertices (x1,y1) and (xn,yn) are also adjacent.

Input
The first input line has an integer n: the number of vertices.
After this, there are n lines that describe the vertices. The ith such line has two integers xi and yi.
You may assume that the polygon is simple, i.e., it does not intersect itself.

Output
Print one integer: 2a where the area of the polygon is a (this ensures that the result is an integer).

Constraints
3≤n≤1000
−10^9≤xi,yi≤10^9

Example Input:
4
1 1
4 2
3 5
1 4

Example Output:
16
*/
#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i, a, b) for (ll i=a; i<b; i++)
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n; cin>>n;
    vector<pair<ll, ll>> vect(n);
    for (ll i=0; i<n; i++) {
        cin>>vect[i].first>>vect[i].second;
    }
    vect.push_back(vect[0]);
    ll ans=0;
    FOR(i, 0, n) {
        ans+=vect[i].first*vect[i+1].second;
    }
    FOR(i, 0, n) {
        ans-=vect[i].second*vect[i+1].first;
    }
    ans=abs(ans);
    cout<<ans;
}