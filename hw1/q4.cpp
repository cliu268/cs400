// D. Cow Frisbee
// https://www.xinyoudui.com/contest?courses=453&books=473&pages=12827&fragments=31088&problemId=15525
/*
Farmer John's N cows (N≤3×10^5) have heights 1,2,…,N. One day, the cows are standing in a line in some order playing frisbee; let h1…hN 
denote the heights of the cows in this order (so the h's are a permutation of 1…N).

Two cows at positions i and j in the line can successfully throw the frisbee back and forth if and only if every cow between them has height 
lower than min(hi,hj).

Please compute the sum of distances between all pairs of locations i<j at which there resides a pair of cows that can successfully throw the 
frisbee back and forth. The distance between locations i and j is j−i+1.

INPUT FORMAT (input arrives from the terminal / stdin):
The first line of input contains a single integer N. The next line of input contains h1…hN, separated by spaces.

OUTPUT FORMAT (print output to the terminal / stdout):
Output the sum of distances of all pairs of locations at which there are cows that can throw the frisbee back and forth. Note that the large 
size of integers involved in this problem may require the use of 64-bit integer data types (e.g., a "long long" in C/C++).

SAMPLE INPUT:
7
4 3 1 2 5 6 7

SAMPLE OUTPUT:
24

The pairs of successful locations in this example are as follows:
(1, 2), (1, 5), (2, 3), (2, 4), (2, 5), (3, 4), (4, 5), (5, 6), (6, 7)

SCORING
Test cases 1-3 satisfy N≤5000.
Test cases 4-11 satisfy no additional constraints.
Problem credits: Quanquan Liu
*/
#include <iostream>
#include <stack>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
    ll n; cin>>n;
    vector<ll> vect(n);
    for (ll i=0; i<n; i++) {
        cin>>vect[i];
    }
 	stack<ll> s;
    s.push(0);
    ll ans=0;
    for (ll i=1; i<n; i++) {
		if (vect[i]<vect[s.top()]) {
            ans+=2;
            s.push(i);
            continue;
        }
        while (!s.empty() && vect[s.top()]<vect[i]) {
			ans+=i-s.top()+1;
            s.pop();
        }
        if (!s.empty()) {
            ans+=i-s.top()+1;
        }
        s.push(i);
    }
    cout<<ans;
}