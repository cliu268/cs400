// D. Finding Patterns
// https://www.xinyoudui.com/contest?courses=453&books=473&pages=13115&fragments=33368&problemId=14217
/*
Time limit: 1.00 s
Memory limit: 512 MB
Given a string and patterns, check for each pattern if it appears in the string.

Input
The first input line has a string of length n.
The next input line has an integer k: the number of patterns. Finally, there are k lines that describe the patterns.
The string and the patterns consist of characters a–z.

Output
For each pattern, print "YES" if it appears in the string and "NO" otherwise.

Constraints
1≤n≤10^5
1≤k≤5⋅10^5
the total length of the patterns is at most 5⋅10^5

Example Input:
aybabtu
3
bab
abc
ayba

Output:
YES
NO
YES
*/
// ************************NOT YET CORRECT.. TLE************************
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll MOD=1E9+9;
ll base=31;
vector<ll> power;
ll strHash(string s) {
    ll ans=0;
    for (ll i=0; i<s.size(); i++) {
        ans=(ans+s[i]*power[i+1]%MOD)%MOD;
    }
    return ans;
}
int main() {
    string s; cin>>s;
    power.push_back(1);
    for (ll i=1; i<=s.size(); i++) {
        power.push_back(power[i-1]*base%MOD);
    }
    ll k; cin>>k;
    multiset<pair<ll, pair<ll, ll>>> vect;
    for (ll i=0; i<k; i++) {
        string x; cin>>x;
        if (x.length()>s.length()) {
            continue;
        }
        vect.insert({x.size(), {strHash(x), i}});
    }
    vector<string> ans(k, "NO");
    vector<ll> sHash(s.size()+1); sHash[0]=0;
    for (ll i=1; i<=s.size(); i++) {
        sHash[i]=(sHash[i-1]+power[i]*s[i-1]%MOD)%MOD;
        vector<pair<ll, pair<ll, ll>>> trash;
        for (auto j : vect) {
            if (j.first>i) {
                break;
            }
            ll curr=(sHash[i]-sHash[i-j.first])%MOD;
            if (curr<0) curr+=MOD;
            ll querie=j.second.first*power[i-j.first]%MOD;
            if (curr==querie) {
                ans[j.second.second]="YES";
                trash.push_back(j);
            }
        }
        for (auto j : trash) {
            vect.erase(vect.find(j));
        }
    }
    for (auto i : ans) {
        cout<<i<<"\n";
    }
}