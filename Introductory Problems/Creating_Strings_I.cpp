#include<bits/stdc++.h>
#define ll long long
#define N 100005
#define M 10000007
#define O 1000000009
#define vll vector<long long>
#define dis(n) cout<<n<<endl
#define fo(i,N) for(int i=0; i<N; ++i)
#define fos(i,b,N) for(int i=b; i<N; ++i)
#define forr(i,N) for(i=N; i>=0; --i)

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    vector<string> sol;
    sort(s.begin(), s.end());
    sol.push_back(s);
    while (next_permutation(s.begin(), s.end()))
        sol.push_back(s);
    cout << sol.size()<<endl;
    for(int i = 0; i < sol.size(); ++i){
        cout << sol[i] << endl;
    }
    return 0;
}