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
    bool odd = false;
    cin >> s;
    if(s.size() % 2 != 0)
      odd = true;
    
    ll i, n = s.size(), cnt[26] = {0};
    for(i = 0; i < n; ++i)
        cnt[(int)s[i] - 65]++;
    string sol;
    for(i = 0; i < 26; ++i)
    {
        if(cnt[i] % 2 != 0)
        {
            if(odd){
                odd = false;
                
            }
        }
        if(cnt[i] != 0)
        {
            for(int j = 0; j < cnt[i]; ++j)
              sol.push_back('A' + i);
        }
    }
    return 0;
}