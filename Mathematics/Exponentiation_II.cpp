#include <bits/stdc++.h>
#define ll long long
#define N 100005
#define M 10000007
#define O 1000000007
#define vll vector<long long>
#define vl vector<long>
#define dis(n) cout << n << endl
#define fo(i, N) for (int i = 0; i < N; ++i)
#define fos(i, b, N) for (int i = b; i < N; ++i)
#define forr(i, N) for (i = N; i >= 0; --i)

using namespace std;

ll exponent(ll a, ll b, ll mod)
{
    ll res = 1, fac = a;
    while (b)
    {
        if (b % 2 == 1)
        {
            res = (res * fac) % mod;
            b--;
            continue;
        }

        fac = (fac * fac) % mod;
        b /= 2;
    }

    return res;
}

int main()
{
    long n;
    cin >> n;
    while (n--)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        ll p = exponent(b, c, O -1);    //Fermat's Little Theorem
        ll res = exponent(a, p, O);

        cout << res << endl;
    }
    return 0;
}