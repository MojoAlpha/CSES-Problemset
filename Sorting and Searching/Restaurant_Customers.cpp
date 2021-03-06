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
    vector<pair<long, bool>> a;

    for (int i = 0; i < n; ++i)
    {
        long x, y;
        cin >> x >> y;
        a.push_back(make_pair(x, true));
        a.push_back(make_pair(y, false));
    }

    sort(a.begin(), a.end());

    long res = INT_MIN, curr = 0;

    for (long i = 0; i < a.size(); ++i)
    {
        if (a[i].second == true)
        {
            curr++;
            res = max(curr, res);
        }
        else
            curr--;
    }

    cout << res << endl;
    return 0;
}