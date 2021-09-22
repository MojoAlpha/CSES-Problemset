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

/*
Constructive Algorithm :-
Observe the condition to make a beautiful array, 

For n = 2, the possible arrays are {1, 2}, {2, 1}, none of which is beautiful
For n = 3, the possible arrays are {1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}
            none of these is beautiful
For n > 3, beautiful array always exists
Just place all the elements with even value and then place all elements with odd value or vice versa
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long n;
    cin >> n;
    if (n == 1)
        printf("1\n");
    else if (n == 2 || n == 3)
        printf("NO SOLUTION\n");
    else
    {
        long i;
        for (i = 2; i <= n; i += 2)
            printf("%ld ", i);
        for (i = 1; i <= n; i += 2)
            printf("%ld ", i);
    }

    return 0;
}