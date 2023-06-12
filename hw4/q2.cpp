// B. String Matching
// https://www.xinyoudui.com/contest?courses=453&books=473&pages=13168&fragments=33945&problemId=14195
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

Output:
2
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s, p; cin>>s>>p;
  vector<int> lps(p.size()+1, 0);
  lps[1]=0;
  for (int i=1; i<p.size(); i++) {
    int curr=lps[i]+1;
    int prev=lps[i];
    while (p[curr-1]!=p[i] && curr!=0) {
      curr=prev;
      prev=lps[curr];
    }
    lps[i+1]=curr;
  }
  int i=0; int j=0;
  int ans=0;
  while (i<s.size()) {
    if (s[i]==p[j]) {
      if (j+1==p.size()) {
        ans++;
      }
      i++; j++;
    }
    else {
      if (j==0) {
        i++;
      }
      else {
        j=lps[j];
      }
    }
    // cout<<i<<" "<<j<<"\n";
  }
  cout<<ans;
}