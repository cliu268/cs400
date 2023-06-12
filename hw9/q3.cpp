// C. Help Yourself
// https://www.xinyoudui.com/contest?courses=453&books=474&pages=14234&fragments=40471&problemId=15423
/*
Bessie has been given N segments (1≤N≤10^5) on a 1D number line. The ith segment contains all reals x such that li≤x≤ri.

Define the union of a set of segments to be the set of all x that are contained within at least one segment. 
Define the complexity of a set of segments to be the number of connected regions represented in its union.

Bessie wants to compute the sum of the complexities over all 2^N subsets of the given set of N segments, modulo 10^9+7.
Normally, your job is to help Bessie. But this time, you are Bessie, and there's no one to help you. Help yourself!

SCORING:
Test cases 2-3 satisfy N≤16.
Test cases 4-7 satisfy N≤1000.
Test cases 8-12 satisfy no additional constraints.

INPUT FORMAT (file help.in):
The first line contains N.
Each of the next N lines contains two integers li and ri. It is guaranteed that li<ri and all li,ri are distinct integers in the range 1…2N.

OUTPUT FORMAT (file help.out):
Output the answer, modulo 10^9+7.

SAMPLE INPUT:
3
1 6
2 3
4 5

SAMPLE OUTPUT:
8

The complexity of each nonempty subset is written below.

The answer is 1+1+1+1+1+2+1=8.
Problem credits: Benjamin Qi
*/
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i=a; i<b; i++)
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int MOD=1E9+7;
    int n; cin>>n;
    vector<int> vect(2*n+2, 0);
    vector<pair<int, int>> store(n);
    for (int i=0; i<n; i++) {
        int a, b; cin>>a>>b;
        vect[a]++;
        vect[b+1]--;
        store[i]={a, b};
    }
    for (int i=1; i<=2*n; i++) {
        vect[i]+=vect[i-1];
        // cout<<vect[i]<<" ";
    }
    vector<int> power2(n, 1);
    for (int i=1; i<n; i++) {
        power2[i]=(power2[i-1]*2)%MOD;
    }
    int ans=0;
    for (auto i : store) {
        ans=(ans+power2[n-vect[i.second]])%MOD;
        // cout<<ans<<" ";
    }
    cout<<ans;
}