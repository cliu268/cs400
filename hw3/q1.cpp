// A. String Matching
// https://www.xinyoudui.com/contest?courses=453&books=473&pages=13115&fragments=33368&problemId=14195
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
ll base=31;
vector<ll> power;
vector<ll> hashStr(string s) {
    vector<ll> ans; ans.push_back(0);
    for (ll i=0; i<s.size(); i++) {
        ll curr=ans[ans.size()-1];
        curr=(curr+(s[i]*power[i])%MOD)%MOD;
        if (curr<0) {
            curr+=MOD;
        }
        ans.push_back(curr);
    }
    return ans;
}
int main() {
    string s; cin>>s;
    string p; cin>>p;
    power.push_back(base);
    for (ll i=1; i<=s.size(); i++) {
        power.push_back((power[i-1]*base)%MOD);
    }
    vector<ll> sHash=hashStr(s);
    vector<ll> pHash=hashStr(p);
    ll sum=(pHash[pHash.size()-1]*(power[s.size()-p.size()]%MOD))%MOD;
    // cout<<sum<<"\n";
    // for (auto i : pHash) {
    //     cout<<i<<" ";
    // }
    // cout<<"\n";
    // for (auto i : sHash) {
    //     cout<<i<<" ";
    // }
    // cout<<"\n";
    ll ans=0;
    for (ll i=p.size(); i<=s.size(); i++) {
        ll curr=(sHash[i]-sHash[i-p.size()])%MOD;
        if (curr<0) {
            curr+=MOD;
        }
        curr=(curr*(power[s.size()-i]%MOD))%MOD;
        if (curr==sum) {
            ans++;
        }
        // cout<<curr<<" ";
    }
    // cout<<((sHash[p.size()+1]-sHash[1])*(power[11]%MOD))%MOD<<" ";
    cout<<ans;
}