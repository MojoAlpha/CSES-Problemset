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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long n, x;
    vl hash(1000001, 0);
    cin >> n;
    while (n--)
    {
        cin >> x;
        if (hash[x] != 0)
        {
            cout << hash[x] << endl;
            continue;
        }
        long res = 0, lim = floor(sqrt(x));

        for (long i = 1; i <= lim; ++i)
        {
            if (x % i == 0)
                res += 2;
            if (i * i == x)
                res--;
        }
        hash[x] = res;
        cout << res << endl;
    }
    return 0;
}