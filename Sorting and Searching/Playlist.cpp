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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long n, k;
    cin >> n;
    vector<long> a(n);
    map<long, bool> songs;
    long maxx = 0, curr = 0, j = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> k;
        a[i] = k;
        if (songs.find(k) == songs.end() || songs[k] == false)
        {
            songs[k] = true;
            curr++;
            maxx = max(curr, maxx);
        }
        else
        {
            while (a[j] != k)
            {
                songs[a[j]] = false;
                j++;
            }

            curr = i - j;
            j++;
        }
    }

    cout << maxx << endl;
    return 0;
}