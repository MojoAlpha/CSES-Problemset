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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    bool odd = false, solExist = true;
    cin >> s;
    if (s.size() % 2 != 0)
        odd = true;

    ll i, n = s.size(), cnt[26] = {0};
    for (i = 0; i < n; ++i)
        cnt[(int)s[i] - 65]++;

    string sol;
    char mid;
    for (i = 0; i < 26; ++i)
    {
        if (cnt[i] > 0)
        {
            if (cnt[i] % 2 == 0)
                for (int j = 0; j < cnt[i] / 2; ++j)
                    sol.push_back('A' + i);
            else
            {
                if (!odd)
                {
                    solExist = false;
                    break;
                }
                else
                {
                    mid = 'A' + i;
                    for (int j = 0; j < cnt[i] / 2; ++j)
                        sol.push_back('A' + i);
                    odd = false;
                }
            }
        }
    }

    if (!solExist)
    {
        cout << "NO SOLUTION\n";
    }
    else
    {
        if (n % 2 == 1)
            sol.push_back(mid);

        ll start = n % 2 == 0 ? sol.size() - 1 : sol.size() - 2;
        while (start >= 0)
        {
            sol.push_back(sol[start]);
            start--;
        }

        cout << sol << endl;
    }
    return 0;
}