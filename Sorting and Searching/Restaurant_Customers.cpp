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
int main()
{
    long n, i;
    cin >> n;
    vector<pair<long, long>> a(n);
    for(i = 0; i < n; ++i)
        cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());

    long res = 0, start = -1, end = -1, count = 0;
    for(i = 0; i < n; ++i){
        if(start == -1 && end == -1){
            start = a[i].first;
            end = a[i].second;
            count++;
        }
        else
        {
            count++;
            if(a[i].first > start && a[i].first < end)
                start = a[i].first;

            if(a[i].second < end && a[i].second > start)
                end = a[i].second;
            
            if(a[i].first > end || a[i].second < start)
            {
                count--;
                if(count > res)
                    res = count;
                count = 0;
                start = -1;
                end = -1;
                --i;
            }
        }
        // cout << start << " " << end << endl;
    }
    cout << max(res, count) << endl;
    return 0;
}