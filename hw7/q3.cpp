// C. Common Divisors
// https://www.xinyoudui.com/contest?courses=453&books=474&pages=13493&fragments=35688&problemId=14013
/*
Time limit: 1.00 s
Memory limit: 512 MB
You are given an array of n positive integers. Your task is to find two integers such that their greatest common divisor is 
as large as possible.

Input
The first input line has an integer n: the size of the array.
The second line has n integers x1,x2,…,xn: the contents of the array.

Output
Print the maximum greatest common divisor.

Constraints
2≤n≤2⋅10^5
1≤xi≤10^6

Example Input:
5
3 14 15 7 9

Example Output:
7
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int MAX=1E6;
    int n; cin>>n;
    vector<int> vect(n);
    vector<int> count(MAX+1, 0);
    for (int i=0; i<n; i++) {
        cin>>vect[i];
        count[vect[i]]++;
    }
    for (int i=MAX; i>0; i--) {
        int num=0;
        for (int j=i; j<=MAX; j+=i) {
            num+=count[j];
        }
        if (num>=2) {
            cout<<i;
            break;
        }
    }

}