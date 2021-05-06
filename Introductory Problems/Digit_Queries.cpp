#include <bits/stdc++.h>
#define ll long long
#define N 100005
#define M 10000007
#define O 1000000009
#define vll vector<long long>
#define vl vector<long>
#define dis(n) cout << n << endl
#define fo(i, N) for (int i = 0; i < N; ++i)
#define fos(i, b, N) for (int i = b; i < N; ++i)
#define forr(i, N) for (i = N; i >= 0; --i)

using namespace std;

ll ind_pos(ll n, ll pos)
{
    ll i = 1;
    while (n > 0)
    {
        ll tmp = n % 10;
        if (i == pos)
            return tmp;
        n /= 10;
        ++i;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll q;
    cin >> q;
    while (q--)
    {
        ll n;
        cin >> n;
        ll digs = 1, curr = 0, c = 1;

        while (n > digs * 9 * c)
        {
            n -= digs * 9 * c;
            digs++;
            curr = curr * 10 + 9;
            c *= 10;
        }

        ll tmp1 = n / digs;
        curr += tmp1;
        ll tmp2 = n % digs;

        if (tmp2 == 0)
            cout << ind_pos(curr, 1);
        else
            cout << ind_pos(curr + 1, digs - tmp2 + 1);
        cout << endl;
    }
    return 0;
}