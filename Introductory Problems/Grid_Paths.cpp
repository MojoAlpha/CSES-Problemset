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

string s;
ll ans;
bool board[7][7];

void calcPaths(int pos, int x, int y, int m, int n)
{
    if (pos == 48 && x == m && y == n)
    {
        ans++;
        return;
    }
    if (pos == 48)
        return;

    if (((x + 1 == n || (board[x + 1][y] && board[x - 1][y])) && y - 1 >= 0 && y + 1 < 7 && !board[x][y - 1] && !board[x][y + 1]) ||
        ((y + 1 == n || (board[x][y - 1] && board[x][y + 1])) && x - 1 >= 0 && x + 1 < n && !board[x - 1][y] && !board[x + 1][y]) ||
        ((x == 0 || (board[x + 1][y] && board[x - 1][y])) && y - 1 >= 0 && y + 1 < n && !board[x][y - 1] && !board[x][y + 1]) ||
        ((y == 0 || (board[x][y + 1] && board[x][y - 1])) && x - 1 >= 0 && x + 1 < n && !board[x - 1][y] && !board[x + 1][y]))
        return;

    if (s[pos] != '?')
    {
        switch (s[pos])
        {
        case 'L':
            if (x - 1 >= 0 && !board[x - 1][y])
            {
                board[x - 1][y] = true;
                calcPaths(pos + 1, x - 1, y, m, n);
                board[x - 1][y] = false;
            }
            break;
        case 'R':
            if (x + 1 < 7 && !board[x + 1][y])
            {
                board[x + 1][y] = true;
                calcPaths(pos + 1, x + 1, y, m, n);
                board[x + 1][y] = false;
            }
            break;
        case 'U':
            if (y - 1 >= 0 && !board[x][y - 1])
            {
                board[x][y - 1] = true;
                calcPaths(pos + 1, x, y - 1, m, n);
                board[x][y - 1] = false;
            }
            break;
        case 'D':
            if (y + 1 < 7 && !board[x][y + 1])
            {
                board[x][y + 1] = true;
                calcPaths(pos + 1, x, y + 1, m, n);
                board[x][y + 1] = false;
            }
            break;
        }
    }
    else
    {
        if (x + 1 < 7 && !board[x + 1][y])
        {
            board[x + 1][y] = true;
            calcPaths(pos + 1, x + 1, y, m, n);
            board[x + 1][y] = false;
        }
        if (x - 1 >= 0 && !board[x - 1][y])
        {
            board[x - 1][y] = true;
            calcPaths(pos + 1, x - 1, y, m, n);
            board[x - 1][y] = false;
        }
        if (y - 1 >= 0 && !board[x][y - 1])
        {
            board[x][y - 1] = true;
            calcPaths(pos + 1, x, y - 1, m, n);
            board[x][y - 1] = false;
        }
        if (y + 1 < 7 && !board[x][y + 1])
        {
            board[x][y + 1] = true;
            calcPaths(pos + 1, x, y + 1, m, n);
            board[x][y + 1] = false;
        }
    }
}

int main()
{
    cin >> s;
    ans = 0;
    fo(i, 7)
        fo(j, 7)
            board[i][j] = false;
    board[0][0] = true;
    calcPaths(0, 0, 0, 6, 0);
    cout << ans;
    return 0;
}