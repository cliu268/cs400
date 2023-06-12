// A. Line Segment Intersection
// https://www.xinyoudui.com/contest?courses=453&books=474&pages=14335&fragments=41283&problemId=14261
/*
Time limit: 1.00 s
Memory limit: 512 MB
There are two line segments: the first goes through the points (x1,y1) and (x2,y2), and the second goes through the points (x3,y3) and (x4,y4).

Your task is to determine if the line segments intersect, i.e., they have at least one common point.

Input
The first input line has an integer t: the number of tests.
After this, there are t lines that describe the tests. Each line has eight integers x1, y1, x2, y2, x3, y3, x4 and y4.

Output
For each test, print "YES" if the line segments intersect and "NO" otherwise.

Constraints
1≤t≤10^5
−10^9≤x1,y1,x2,y2,x3,y3,x4,y4≤10^9
(x1,y1)≠(x2,y2)
(x3,y3)≠(x4,y4)

Example Input:
5
1 1 5 3 1 2 4 3
1 1 5 3 1 1 4 3
1 1 5 3 2 3 4 1
1 1 5 3 2 4 4 1
1 1 5 3 3 2 7 4

Example Output:
NO
YES
YES
YES
YES
*/
#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i, a, b) for (ll i=a; i<b; i++)
using namespace std;

ll cross(pair<ll, ll> a, pair<ll, ll> b) {
    return a.first*b.second-a.second*b.first;
}
ll dot(pair<ll, ll> a, pair<ll, ll> b) {
    return a.first*b.first+a.second*b.second;
}
pair<ll, ll> sub(pair<ll, ll> a, pair<ll, ll> b) {
    return {a.first-b.first, a.second-b.second};
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t; cin>>t;
    while (t--) {
        vector<pair<ll, ll>> vect(4);
        for (ll i=0; i<4; i++) {
            cin>>vect[i].first>>vect[i].second;
        }
        auto bc=sub(vect[2], vect[1]);
        auto bd=sub(vect[3], vect[1]);
        auto ac=sub(vect[2], vect[0]);
        auto ad=sub(vect[3], vect[0]);
        auto ab=sub(vect[1], vect[0]);
        auto ba=sub(vect[0], vect[1]);
        auto ca=sub(vect[0], vect[2]);
        auto dc=sub(vect[2], vect[3]);
        ll cross1=cross(ba, bc);
        ll cross2=cross(ba, bd);
        bool opp=true;
        if (cross1>0 && cross2>0) {
            opp=false;
        }
        else if (cross1<0 && cross2<0) {
            opp=false;
        }
        else if (cross1==0 && cross2==0) {
            ll a=min(vect[0].first, vect[1].first);
            ll b=max(vect[0].first, vect[1].first);
            if (vect[3].first>vect[2].first) {
                if (vect[3].first<a || vect[2].first>b) {
                    opp=false;
                }
            }
            else if (vect[3].first<vect[2].first) {
                if (vect[2].first<a || vect[3].first>b) {
                    opp=false;
                }
            }
            else {
                a=min(vect[1].second, vect[0].second);
                b=max(vect[1].second, vect[0].second);
                if (vect[3].second>vect[2].second) {
                    if (vect[3].second<a || vect[2].second>b) {
                        opp=false;
                    }
                }
                else if (vect[3].second<vect[2].second) {
                    if (vect[2].second<a || vect[3].second>b) {
                        opp=false;
                    }
                }
            }
        }
        if (!opp) {
            cout<<"NO\n";
            continue;
        }
        ll bruh1=cross(ca, dc);
        ll bruh2=cross(ba, dc);
        string ans;
        if ((bruh1>=0 && bruh2>=0) || (bruh1<=0 && bruh2<=0)) {
            if (abs(bruh1)>abs(bruh2)) {
                ans="NO";
            }
            else {
                ll amog1=cross(ac, ba);
                ll amog2=cross(dc, ba);
                if ((amog1>=0 && amog2>=0) || (amog1<=0 && amog2<=0)) {
                    if (abs(amog1)>abs(amog2)) {
                        ans="NO";
                    }
                    else {
                        ans="YES";
                    }
                }
                else {
                    ans="NO";
                }
            }
        }
        else {
            ans="NO";
        }
        cout<<ans<<"\n";
    }   
}