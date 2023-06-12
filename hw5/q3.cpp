// C. Modern Art2
// https://www.xinyoudui.com/contest?courses=453&books=473&pages=13264&fragments=34370&problemId=15304
/*
Having become bored with standard 2-dimensional artwork (and also frustrated at others copying her work), the great bovine artist Picowso 
has decided to switch to a more minimalist, 1-dimensional style.

Although, her paintings can now be described by a 1-dimensional array of colors of length N (1≤N≤100,000), her painting style remains 
unchanged: she starts with a blank canvas and layers upon it a sequence of "rectangles" of paint, which in this 1-dimensional case are 
simply intervals. She uses each of the colors 1…N exactly once, although just as before, some colors might end up being completely covered 
up by the end.

To Picowso's great dismay, her competitor Moonet seems to have figured out how to copy even these 1-dimensional paintings, using a similar 
strategy to the preceding problem: Moonet will paint a set of disjoint intervals, wait for them to dry, then paint another set of disjoint 
intervals, and so on. Moonet can only paint at most one interval of each color over the entire process. Please compute the number of such 
rounds needed for Moonet to copy a given 1-dimensional Picowso painting.

INPUT FORMAT (file art2.in):
The first line of input contains N, and the next N lines contain an integer in the range 0…N indicating the color of each cell in the 
1-dimensional painting (0 for a blank cell).

OUTPUT FORMAT (file art2.out):
Please output the minimum number of rounds needed to copy this painting, or -1 if this could not have possibly been an authentic work of 
Picowso (i.e., if she could not have painted it using a layered sequence of intervals, one of each color).

SAMPLE INPUT:
7
0
1
4
5
1
3
3

SAMPLE OUTPUT:
2

In this example, the interval of color 1 must be painted in an earlier round than the intervals of colors 4 and 5, so at least two rounds 
are needed.
Problem credits: Brian Dean
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("art2.in", "r", stdin);
    // freopen("art2.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    vector<int> vect(n);
    vector<int> inv(n+1, -1);
    for (int i=0; i<n; i++) {
        cin>>vect[i];
        inv[vect[i]]=i;
    }
    vector<int> end(n+1, -1);
    for (auto i : inv) {
        if (i==-1) {
            continue;
        }
        end[i]=vect[i];
    }
    stack<int> s; int ans=0; int count=0;
    vector<bool> visited(n+1, false);
    for (int i=0; i<n; i++) {
        // cout<<i<<" ";
        if (vect[i]==0) {
            if (s.empty()) {
                continue;
            }
            else {
                ans=-1;
                break;
            }
        }
        s.push(vect[i]);
        if (!visited[vect[i]]) {
            count++;
        }
        ans=max(ans, count);
        visited[vect[i]]=true;
        if (end[i]==vect[i]) {
            while (!s.empty() && s.top()==vect[i]) {
                s.pop();
            }
            count--;
        }
        // cout<<ans<<" ";
    }
    if (!s.empty()) {
        ans=-1;
    }
    cout<<ans;
}