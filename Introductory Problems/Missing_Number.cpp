#include <bits/stdc++.h>
#define ll long long
#define N 100005
#define M 10000007
#define O 1000000009
#define vll vector<long long>
#define dis(n) cout << n << endl
#define fo(i, N) for (int i = 0; i < N; ++i)
#define fos(i, b, N) for (int i = b; i < N; ++i)
#define forr(i, N) for (i = N; i >= 0; --i)

using namespace std;

/*
Since we will have all the numbers between 1 to n, just take the sum of 
all the numbers & subtract it from the sum of series 1 + 2 + 3 + ... + n

One other easy ways to accomplish this task is to use XOR, by calculating the total 
XOR of array elements and XOR of numbers from 1 to n. Final answer is XOR of these two.
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long n, i, t;
    cin >> n;
    ll sum = 0;
    for (i = 1; i < n; ++i)
    {
        cin >> t;
        sum += t;
    }
    cout << (n * (n + 1)) / 2 - sum;
    return 0;
}