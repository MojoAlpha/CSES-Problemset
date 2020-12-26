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
int main()
{
    long n;
    cin >> n;
    vector<pair<long, long>> a;

    for (int i = 0; i < n; ++i)
    {
        long x, y;
        cin >> x >> y;
        a.push_back(make_pair(y, x));
    }

    sort(a.begin(), a.end());

    long res = 1, curr = a[0].first;
    for (int i = 1; i < a.size(); ++i)
    {
        if (a[i].second >= curr)
        {
            res++;
            curr = a[i].first;
        }
    }

    cout << res << endl;
    return 0;
}