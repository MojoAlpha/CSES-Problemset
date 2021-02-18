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

int main()
{
    long n;
    cin >> n;
    while (n--)
    {
        ll a, b;
        cin >> a >> b;
        ll res = 1, fac = a;
        while (b)
        {
            if (b % 2 == 1)
            {
                res = (res * fac) % O;
                b--;
                continue;
            }

            fac = (fac * fac) % O;
            b /= 2;
        }

        cout << res << endl;
    }
    return 0;
}