// B. Finding Borders
// https://www.xinyoudui.com/contest?courses=453&books=473&pages=13115&fragments=33368&problemId=14175
/*
Time limit: 1.00 s
Memory limit: 512 MB
A border of a string is a prefix that is also a suffix of the string but not the whole string. For example, 
the borders of abcababcab are ab and abcab.

Your task is to find all border lengths of a given string.

Input
The only input line has a string of length n consisting of characters a–z.

Output
Print all border lengths of the string in increasing order.

Constraints
1≤n≤10^6

Example Input:
abcababcab

Example Output:
2 5
*/
// ****************************NOT ACCURATE YET*************************
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll MOD=1E9+9;
ll base=31;
vector<ll> power;

vector<ll> prefHash(string s) {
    vector<ll> ans; ans.push_back(0);
    for (ll i=0; i<s.size(); i++) {
        ll curr=ans[i];
        curr=(curr+s[i]*power[i]%MOD)%MOD;
        ans.push_back(curr);
    }
    return ans;
}
vector<ll> suffHash(string s) {
    vector<ll> ans; ans.push_back(0);
    for (ll i=s.size()-1; i>=0; i--) {
        ll curr=ans[ans.size()-1]*base%MOD;
        curr=(curr+s[i]*base%MOD)%MOD;
        ans.push_back(curr);
    }
    return ans;
}
int main() {
    string s; cin>>s;
    power.push_back(base);
    for (ll i=1; i<=s.size(); i++) {
        power.push_back(power[i-1]*base%MOD);
    }
    vector<ll> pref=prefHash(s);
    vector<ll> suff=suffHash(s);
    // for (auto i : pref) {
    //     cout<<i<<" ";
    // }
    // cout<<"\n";
    // for (auto j : suff) {
    //     cout<<j<<" ";
    // }
    // cout<<"\n";
    for (ll i=1; i<s.size(); i++) {
        if (pref[i]==suff[i]) {
            cout<<i<<" ";
        }
    }
}