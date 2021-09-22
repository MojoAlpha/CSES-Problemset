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
n! = 1 x 2 x 3 x ...x n
we get a 0 at the end of a number only when it is divisible by 10, which means there is
a factor of 5 and 2 behind the generation of a trailing zero.
We also know that number of 2's will always be greater than number of 5's in n!
The only task remains is to count the number of multiples of 5^1, 5^2...5^k , where 5^k <= n, occur
in the value of n!
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    ll f = 5, zeros = 0;
    while (f <= t)
    {
        zeros += t / f;
        f *= 5;
    }
    cout << zeros << endl;
    return 0;
}