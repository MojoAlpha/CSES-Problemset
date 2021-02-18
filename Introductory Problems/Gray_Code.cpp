#include<bits/stdc++.h>
#define ll long long
#define N 100005
#define M 10000007
#define O 1000000009
#define vll vector<long long>
#define vl vector<long>
#define dis(n) cout<<n<<endl
#define fo(i,N) for(int i=0; i<N; ++i)
#define fos(i,b,N) for(int i=b; i<N; ++i)
#define forr(i,N) for(i=N; i>=0; --i)

using namespace std;

vector<string> GrayGen(int n) {
    if(n == 1) {
        vector<string> res = {"0", "1"};
        return res;
    }

    vector<string> s = GrayGen(n - 1);
    vector<string> t(s);
    reverse(t.begin(), t.end());
    int m = s.size();
    fo(i, m) s[i] = "0" + s[i];
    fo(i, m) t[i] = "1" + t[i];

    vector<string> res(2 * m);
    merge(s.begin(), s.end(), t.begin(), t.end(), res.begin());
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<string> vs = GrayGen(n);
    fo(i, vs.size()) cout << vs[i] << endl;
    return 0;
}