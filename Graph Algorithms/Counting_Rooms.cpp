#include <bits/stdc++.h>

using namespace std;

#define N 100005
#define MOD 1000000007
#define fo(i, b, n) for (long i = b; i < n; ++i)
#define rfo(i, b, n) for (long i = b; i >= n; --i)
#define all(ar) ar.begin(), ar.end()
#define rall(ar) ar.rbegin(), ar.rend()
#define mem(ar, val) memset(ar, (val), sizeof(ar))
#define fi first
#define se second
#define pb push_back
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.precision(12);

typedef long long ll;
typedef pair<long, long> pll;
typedef pair<ll, ll> plll;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vl> vvl;
typedef vector<vll> vvll;

const double PI = 3.141592653589793238;
const ll oo = 1e18;

/*
This problem can be solved using the concept of connected components.
For each floor (.) in the building run a DFS traversal through the building matrix, and mark
the neighbouring floor cells as visited. If the floor cell is already visited, do not need to
run a DFS on it. Thus the number of times we intiate the DFS call from the main would be 
counted as the number of disconnected components or floors.

EXAMPLE -

# # # # # # # #       - - - - - - - -
# . . # . . . #       - 1 1 - 3 3 3 -
# # # # . # . #   =>  - - - - 3 - 3 -
# . . # . . . #       - 2 2 - 3 3 3 -
# # # # # # # #       - - - - - - - -

 Original Matrix        Marked Matrix
                     (with component no.)

We can mark different components with different numbers, to determine which component a particular
cell belongs to, if needed. Here, a normal boolean matrix would suffice. Just mark the 
visited cells and count the number of floors.

Articles -
> https://cp-algorithms.com/graph/search-for-connected-components.html
> https://www.geeksforgeeks.org/connected-components-in-an-undirected-graph/
*/

int dx[4] = {1, -1, 0, 0}, n;
int dy[4] = {0, 0, 1, -1}, m;

// check for validity of coordinates
bool isValid(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m);
}

// standard DFS traversal function
void dfs(vector<string> &building, vvb &vis, int x, int y)
{
    vis[x][y] = 1;
    fo(i, 0, 4)
    {
        int xi = x + dx[i], yi = y + dy[i];
        if (isValid(xi, yi) && building[xi][yi] == '.' && !vis[xi][yi])
            dfs(building, vis, xi, yi);
    }
}

signed main()
{
    fastIO;
    cin >> n >> m;
    vector<string> building(n);
    vvb vis(n, vb(m, 0));
    fo(i, 0, n) cin >> building[i];

    int res = 0;
    fo(i, 0, n)
    {
        fo(j, 0, m)
        {
            // if current cell if a floor, run a DFS traversal
            if (building[i][j] == '.' && !vis[i][j])
            {
                res++;
                dfs(building, vis, i, j);
            }
        }
    }
    cout << res;
    return 0;
}