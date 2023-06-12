// D. Censoring (Silver)
// https://www.xinyoudui.com/contest?courses=453&books=473&pages=13168&fragments=33945&problemId=15193
/*
Farmer John has purchased a subscription to Good Hooveskeeping magazine for his cows, so they have plenty of material to read while waiting 
around in the barn during milking sessions. Unfortunately, the latest issue contains a rather inappropriate article on how to cook the perfect 
steak, which FJ would rather his cows not see (clearly, the magazine is in need of better editorial oversight).

FJ has taken all of the text from the magazine to create the string S of length at most 10^6 characters. From this, he would like to remove 
occurrences of a substring T to censor the inappropriate content. To do this, Farmer John finds the first occurrence of T in S and deletes it. 
He then repeats the process again, deleting the first occurrence of T again, continuing until there are no more occurrences of T in S. 
Note that the deletion of one occurrence might create a new occurrence of T that didn't exist before.

Please help FJ determine the final contents of S after censoring is complete.

INPUT FORMAT: (file censor.in)
The first line will contain S. The second line will contain T. The length of T will be at most that of S, and all characters of S and T 
will be lower-case alphabet characters (in the range a..z).

OUTPUT FORMAT: (file censor.out)
The string S after all deletions are complete. It is guaranteed that S will not become empty during the deletion process.

SAMPLE INPUT:
whatthemomooofun
moo

SAMPLE OUTPUT:
whatthefun

[Problem credits: Mark Gordon, 2015]
*/
// ****************************NOT CORRECT YET************************** hw3 q3.cpp has it solved but in different ways??
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//   ios_base::sync_with_stdio(false);
//   cin.tie(0);
  string s, p; cin>>s>>p;
  vector<int> lps(p.size()+1, 0);
  lps[1]=0;
  for (int i=2; i<=p.size(); i++) {
    int curr=lps[i-1]+1;
    int prev=lps[i-1];
    while (curr!=0 && p[i-1]!=p[curr-1]) {
      curr=prev;
      prev=lps[curr];
    }
    lps[i]=curr;
  }
  // for (auto i : lps) {
  //   cout<<i<<" ";
  // }
  int i=0; int j=0;
  vector<int> ans;
  vector<int> mem(s.size());
  while (i<s.size()) {
    if (s[i]==p[j]) {
      if (j==p.size()-1) {
        for (int x=1; x<p.size(); x++) {
          ans.pop_back();
        }
        j=mem[ans.back()];
      }
      else {
        ans.push_back(i);
        j++;
        mem[i]=j;
      }
      i++;
    }
    else {
      if (j==0) {
        ans.push_back(i);
        i++;
        mem[i]=mem[i-1];
      }
      else {
        j=lps[j];
        mem[i]=j;
      }
    }
  }
  // cout<<count<<"\n";
  for (auto i : ans) {
    cout<<s[i];
  }
}