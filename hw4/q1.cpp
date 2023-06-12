// A. Dishwashing
// https://www.xinyoudui.com/contest?courses=453&books=473&pages=13168&fragments=33945&problemId=15375
/*
Bessie and Elsie are helping Farmer John wash the dishes, a more complicated process than one might think due to their lack of opposable thumbs.

The two cows decide that Bessie will apply soap, and Elsie will rinse. Bessie is given a dirty stack of plates labeled 1 through N (1≤N≤10^5) 
Elsie has an empty stack, where clean plates will go. There is a counter in between Bessie and Elsie for soapy stacks.

At each step, either:
- Bessie takes a plate from the top of the dirty stack, applies soap, and then places it on the counter. When placing a soapy plate on the 
counter, Bessie must either (i) place the plate on top of an existing non-empty soapy stack or (ii) create a new soapy stack to the right 
of all existing soapy stacks.
- Elsie takes a plate from the top of the leftmost soapy stack. Elsie rinses the plate, then places it on top of the clean stack.

The goal is for the clean stack to have all plates in order, with the smallest label on the bottom and the largest label on the top. 
It may not be possible for the cows to achieve this goal for the entire stack of plates, so please determine the length of the largest 
prefix of the input ordering for which the goal is achievable.

INPUT FORMAT (file dishes.in):
The first line of input contains N. The next N lines specify the order of the dishes in Bessie's stack, with the first number being the 
dish on top of the stack.

OUTPUT FORMAT (file dishes.out):
Please output the length of the longest prefix of the input stack that can be successfully washed so that the plates end up ordered properly 
in the clean stack.

SAMPLE INPUT:
5
4
5
2
3
1

SAMPLE OUTPUT:
4

Problem credits: George Xing
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("dishes.in", "r", stdin);
    // freopen("dishes.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    vector<vector<int>> vect;
    int maxi=0; int ans=n; int mini=0;
    bool end=false;
    for (int i=0; i<n; i++) {
        int curr; cin>>curr;
        if (end) {
            continue;
        }
        if (curr<maxi) {
            ans=i;
            end=true;
            continue;
        }
        int ind=-1;
        for (int j=mini; j<vect.size(); j++) {
            if (vect[j][0]>curr) {
                ind=j;
                break;
            }
        }
        if (ind==-1) {
            vect.push_back({curr});
        }
        else {
            bool bruh=false;
            while (vect[ind].back()<curr) {
                bruh=true;
                maxi=vect[ind].back();
                vect[ind].pop_back();
            }
            vect[ind].push_back(curr);
            if (bruh) {
                mini=ind;
            }
        }
        // for (auto k : vect) {
        //     for (auto j : k) {
        //         cout<<j<<" ";
        //     }
        //     cout<<"\n";
        // }
    }
    cout<<ans;
}