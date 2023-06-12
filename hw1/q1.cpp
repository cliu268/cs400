// A. Nearest Smaller Values
// https://www.xinyoudui.com/contest?courses=453&books=473&pages=12827&fragments=31088&problemId=14100
/*
Time limit: 1.00 s
Memory limit: 512 MB
Given an array of n integers, your task is to find for each array position the nearest position to its left having a smaller value.

Input
The first input line has an integer n: the size of the array.
The second line has n integers x1,x2,…,xn: the array values.

Output
Print n integers: for each array position the nearest position with a smaller value. If there is no such position, print 0.

Constraints
1≤n≤2⋅10^5
1≤xi≤10^9

Example Input:
8
2 5 1 4 8 3 2 5

Example Output:
0 1 0 3 4 3 3 7
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin>>n;
  vector<int> vect(n);
  for (int i=0; i<n; i++) {
    cin>>vect[i];
  }
  stack<int> s;
  s.push(0);
  vector<int> ans(n); ans[0]=0;
  for (int i=1; i<n; i++) {
    while (!s.empty()) {
      if (vect[s.top()]>=vect[i]) {
        s.pop();
      }
      else {
        ans[i]=s.top()+1;
        s.push(i);
        break;
      }
    }
    if (s.empty()) {
      s.push(i);
      ans[i]=0;
    }
  }
  for (auto i : ans) {
    cout<<i<<" ";
  }
}