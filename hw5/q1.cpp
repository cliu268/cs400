// A. Finding Periods
// https://www.xinyoudui.com/contest?courses=453&books=473&pages=13264&fragments=34370&problemId=14176
/*
Time limit: 1.00 s
Memory limit: 512 MB
A period of a string is a prefix that can be used to generate the whole string by repeating the prefix. The last repetition may be partial. 
For example, the periods of abcabca are abc, abcabc and abcabca.

Your task is to find all period lengths of a string.

Input
The only input line has a string of length n consisting of characters a–z.

Output
Print all period lengths in increasing order.

Constraints
1≤n≤10^6

Example Input:
abcabca

Example Output:
3 6 7
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll MOD=1E9+7;
vector<ll> power;

vector<ll> hashPref(string s) {
    vector<ll> pref(s.length()+1, 0);
    for (ll i=0; i<s.length(); i++) {
        pref[i+1]=(pref[i]+(s[i]*power[i])%MOD)%MOD;
    }
    return pref;
}
int main() {
    string s; cin>>s;
    power.push_back(1);
    for (ll i=1; i<=s.length(); i++) {
        power.push_back((power[power.size()-1]*31) % MOD);
    }
    auto pref=hashPref(s);
    // for (auto i : pref) {
    //     cout<<i<<" ";
    // }
    for (ll i=1; i<=s.length(); i++) {
        for (ll j=2; j<=s.length()/i; j++) {
            ll curr=(pref[i]*power[i*j-i])%MOD;
            ll temp=(pref[i*j]-pref[i*j-i])%MOD;
            if (temp<0) {
                temp+=MOD;
            }
            if (curr!=temp) {
                goto outer;
            }
        }
        // cout<<i<<" ";
        if (s.length()%i!=0) {
            int curr=(pref[s.length()%i]*power[s.length()-s.length()%i])%MOD;
            int temp=(pref[s.length()]-pref[s.length()-s.length()%i])%MOD;
            if (temp<0) {
                temp+=MOD;
            }
            if (curr!=temp) {
                goto outer;
            }
        }
        cout<<i<<" ";
        outer:;
    }
}