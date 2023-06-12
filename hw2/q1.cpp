// A. Distinct Numbers
// https://www.xinyoudui.com/contest?courses=453&books=473&pages=13018&fragments=32711&problemId=14078
/*
Time limit: 1.00 s​  Memory limit: 512 MB
Description:
You are given a list of n integers, and your task is to calculate the number of distinct values in the list.

Input:
The first input line has an integer n: the number of values.
The second line has n integers x_1, x_2, ...... , x_n.

Output:
Print one integers: the number of distinct values.

Sample Input:
5
2 3 2 2 3

Sample Output:​
​2

Constraints:
1 <= n <= 2 ........ 10^5
1 <= x_i < =10^9
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
  ll ans=0;
  ll MOD=10000003;
  vector<ll> heads(MOD, -1);
  vector<ll> arr(n, -1);
  vector<ll> prev(n, -1);
  vector<ll> next(n, -1);
  for (ll i=0; i<n; i++) {
    bool found=false;
    ll ind=heads[vect[i]%MOD];
    while (ind!=-1) {
      if (arr[ind]==vect[i]) {
        found=true;
        break;
      }
      ind=next[ind];
    }
    if (!found) {
      ans++;
      if (heads[vect[i]%MOD]==-1) {
        heads[vect[i]%MOD]=i;
        arr[i]=vect[i];
      }
      else {
        ind=prev[ind];
        next[ind]=i;
        prev[i]=ind;
        arr[i]=vect[i];
      }
    }
  }
  cout<<ans;
}