#include <bits/stdc++.h>
#define ll long long
#define N 100005
#define M 10000005
#define O 1000000007
#define vi vector<int>
#define vl vector<long>
#define vb vector<bool>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long, long>
#define fo(i, N) for (long i = 0; i < N; ++i)
#define fos(i, b, N) for (long i = b; i < N; ++i)
#define forr(i, N) for (long i = N; i >= 0; --i)
const double PI = 3.141592653589793238;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

using namespace std;
int ans = 0;
string board[8];
vb cols(8, false), ldiag(16, false), rdiag(16, false);

void calculate(int r)
{
    if (r == 8)
    {
        ans++;
        return;
    }
    for (int i = 0; i < 8; ++i)
    {
        if (board[r][i] == '.')
        {
            if (!cols[i] && !ldiag[r + i] && !rdiag[r - i + 7])
            {
                cols[i] = ldiag[r + i] = rdiag[r - i + 7] = true;
                calculate(r + 1);
                cols[i] = ldiag[r + i] = rdiag[r - i + 7] = false;
            }
        }
    }
}

int main()
{
    fo(i, 8) cin >> board[i];
    calculate(0);
    cout << ans;
    return 0;
}