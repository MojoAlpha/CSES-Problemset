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
This is a standard BFS (Breadth First Search) problem on a matrix.
The main idea of the problem is to traverse through the matrix (excluding the wall - #), and
determining the reach from the start position, A. After the traversal, if the end position, B
if unmarked, then that position is unreachable, and thus answer is NO. Else if it is marked, 
then track the answer backward from end position to start position, and construct the path 
accordingly.

EXAMPLE CASE - 
# # # # # # # #      # # # # # # # #       - - - - - - - -  |   - => represents walls
# . A # . . . #      # v < # . . . #       - D L - R R D -  |   L,D,R,U => represents direction to
# . # # . # B #  =>  # v # # . # B #   =>  - D - - U - B -  |              follow for shortest path
# . . . . . . #      # > > > > > ^ #       - R R R R R U -  |
# # # # # # # #      # # # # # # # #       - - - - - - - -  |

 Original Matrix       Path Matrix        Path With Direction

I have generated the path using a matrix to store the direction to take after reaching a cell. Another way 
can be, by storing the distance of that particular cell from the source (like in standard BFS). To generate
path in this method, just start from the final position. Let's say the final position is (Fx, Fy) and distance
value is d. So find its neighbouring cell with a value of (d - 1), and move pointer to that position. Repeat 
these steps until the distance is 0. This is how the path can be constructed.

Articles On BFS :-
> https://cp-algorithms.com/graph/breadth-first-search.html
> https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/tutorial/
*/

// direction array for matrix BFS
int dx[4] = {1, -1, 0, 0}, n;
int dy[4] = {0, 0, 1, -1}, m;
string direction = "DURL";

// check for validity of coordinates of labyrinth
bool isValid(int x, int y)
{
    return (x >= 0 && y >= 0 && x < n && y < m);
}

// standard BFS method
void bfs(vector<string> &lab, vector<string> &dir, int x, int y, vvb &vis)
{
    queue<vi> q;
    q.push({x, y});
    vis[x][y] = 1;

    while (!q.empty())
    {
        vi p = q.front();
        q.pop();

        fo(i, 0, 4)
        {
            int xi = p[0] + dx[i], yi = p[1] + dy[i];
            if (isValid(xi, yi) && lab[xi][yi] != '#' && !vis[xi][yi])
            {
                q.push({xi, yi});
                vis[xi][yi] = 1;
                dir[xi][yi] = direction[i];
            }
        }
    }
}

// generating the path string, '-' represents wall
string generatePath(vector<string> &dir, int x, int y)
{
    if (dir[x][y] == '-')
        return "";
    else
    {
        string path = "";
        while (dir[x][y] != '-')
        {
            path.pb(dir[x][y]);
            if (dir[x][y] == 'U')
                x++;
            else if (dir[x][y] == 'D')
                x--;
            else if (dir[x][y] == 'L')
                y++;
            else
                y--;
        }

        // since we are starting from end it would generate reversed path
        reverse(all(path));
        return path;
    }
}

signed main()
{
    fastIO;
    cin >> n >> m;
    vector<string> lab(n), dir(n);
    vvb vis(n, vb(m, 0));

    fo(i, 0, n)
    {
        cin >> lab[i];
        dir[i].resize(m, '-');
    }
    int x1, x2, y1, y2;

    // determining the position of source & destination
    fo(i, 0, n)
    {
        fo(j, 0, m)
        {
            if (lab[i][j] == 'A')
            {
                x1 = i;
                y1 = j;
            }
            else if (lab[i][j] == 'B')
            {
                x2 = i;
                y2 = j;
            }
        }
    }
    bfs(lab, dir, x1, y1, vis);

    string res = generatePath(dir, x2, y2);
    if (res == "")
        cout << "NO";
    else
        cout << "YES\n"
             << res.size() << endl
             << res;
    return 0;
}