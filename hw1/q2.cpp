// B. Advertisement
// https://www.xinyoudui.com/contest?courses=453&books=473&pages=12827&fragments=31088&problemId=14046
/*
Time limit: 1.00 s
Memory limit: 512 MB
A fence consists of n vertical boards. The width of each board is 1 and their heights may vary.
You want to attach a rectangular advertisement to the fence. What is the maximum area of such an advertisement?

Input
The first input line contains an integer n: the width of the fence.
After this, there are n integers k1,k2,…,kn: the height of each board.

Output
Print one integer: the maximum area of an advertisement.

Constraints
1≤n≤2⋅10^5
1≤ki≤10^9

Example Input:
8
4 1 5 3 3 2 4 1

Example Output:
10
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll n; cin>>n;
  vector<ll> vect(n);
  for (ll i=0; i<n; i++) {
    cin>>vect[i];
  }
  vector<ll> area(n, 0);
  stack<ll> s;
  s.push(0);
  ll ans=0;
  //go forward
  for (ll i=1; i<n; i++) {
    if (vect[i]>vect[s.top()]) {
      s.push(i);
      continue;
    }
    while (!s.empty() && vect[i]<=vect[s.top()]) {
      s.pop();
    }
    if (s.empty()) {
      area[i]+=(i+1)*vect[i];
    }
    else {
      area[i]+=(i-s.top())*vect[i];
    }
    s.push(i);
  }
  while (!s.empty()) {
    s.pop();
  }
  //go backward
  s.push(n-1);
  for (ll i=n-2; i>=0; i--) {
    if (vect[i]>vect[s.top()]) {
      s.push(i);
      continue;
    }
    while (!s.empty() && vect[i]<=vect[s.top()]) {
      s.pop();
    }
    if (s.empty()) {
      if (area[i]==0) {
        area[i]+=(n-i)*vect[i];
      }
      else {
        area[i]+=(n-i-1)*vect[i];
      }
    }
    else {
      if (area[i]==0) {
        area[i]+=(s.top()-i)*vect[i];
      }
      else {
        area[i]+=(s.top()-i-1)*vect[i];
      }
    }
    s.push(i);
  }
  for (ll i=0; i<n; i++) {
    ans=max(ans, area[i]);
    // cout<<area[i]<<" ";
  }
  cout<<ans;
}