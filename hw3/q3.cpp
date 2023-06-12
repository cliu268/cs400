// C. Censoring (Silver)
// https://www.xinyoudui.com/contest?courses=453&books=473&pages=13115&fragments=33368&problemId=15193
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
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll MOD=1E9+9;
ll base=31;
vector<ll> power;

ll strHash(string s) {
    ll ans=0;
    for (int i=0; i<s.size(); i++) {
        ans=(ans+s[i]*power[i+1]%MOD)%MOD;
    }
    return ans;
}
int main() {
    string s; cin>>s;
    string t; cin>>t;
    power.push_back(1);
    for (int i=1; i<=s.size(); i++) {
        power.push_back(power[i-1]*base%MOD);
    }
    ll tHash=strHash(t);
    vector<int> ans;
    vector<ll> sHash(s.size()+1); sHash[0]=0;
    ll ind=1;
    // cout<<tHash<<"\n";
    for (int i=0; i<s.size(); i++) {
        // cout<<ind<<" ";
        sHash[ind]=(sHash[ind-1]+power[ind]*s[i]%MOD)%MOD;
        ans.push_back(i);
        if (ind<t.size()) {
            ind++;
            continue;
        }
        ll check=(sHash[ind]-sHash[ind-t.size()])%MOD;
        if (check<0) {
            check+=MOD;
        }
        ll check2=tHash*power[ind-t.size()]%MOD;
        if (check==check2) {
            for (int j=0; j<t.size(); j++) {
                ans.pop_back();
            }
            // for (auto j : ans) {
            //     cout<<j<<" ";
            // }
            // cout<<"\n";
            ind-=t.size();
        }
        // cout<<check<<" "<<check2<<"\n";
        ind++;
    }
    for (auto i : ans) {
        cout<<s[i];
    }
}  