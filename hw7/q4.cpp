// D. String Matching
// https://www.xinyoudui.com/contest?courses=453&books=474&pages=13493&fragments=35688&problemId=14195
/*
Time limit: 1.00 s
Memory limit: 512 MB
Given a string and a pattern, your task is to count the number of positions where the pattern occurs in the string.

Input
The first input line has a string of length n, and the second input line has a pattern of length m. Both of them consist of characters a–z.

Output
Print one integer: the number of occurrences.

Constraints
1≤n,m≤10^6

Example Input:
saippuakauppias
pp

Example Output:
2
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll MOD=1E9+9;
vector<ll> power;
vector<ll> preHash(string s) {
  vector<ll> vect(s.size()+1, 0);
  for (ll i=1; i<=s.size(); i++) {
    vect[i]=(vect[i-1]+((power[i]*s[i-1])%MOD))%MOD;
  }
  return vect;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s, p; cin>>s>>p;
  power.push_back(1);
  for (ll i=1; i<=s.size(); i++) {
    power.push_back((power[i-1]*123)%MOD);
  }
  vector<ll> pre=preHash(s);
  ll val=(preHash(p)[p.size()]*power[s.size()-p.size()])%MOD;
  // cout<<val<<"\n";
  ll ans=0;
  for (ll i=p.size(); i<=s.size(); i++) {
    ll curr=((pre[i]-pre[i-p.size()])*power[s.size()-i])%MOD;
    if (curr<0) {
      curr+=MOD;
    }
    // cout<<curr<<" ";
    if (curr==val) {
      ans++;
    }
  }
  cout<<ans;
}