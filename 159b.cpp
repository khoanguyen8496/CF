#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define REP(i, n) for (int (i)=0, _n(n); (i) < _n; ++i)
#define FOR(i, a, b) for (int (i)=(a), _b(b); i <= _b; ++i)
#define REPR(i, n) for (int i=(n)-1; i >= 0; --i)
#define FORR(i, a, b) for (int (i)=(a), _b(b); i >= _b; --i)
#define all(a) a.begin(),a.end()
#define sz(a) a.size()
#define eb emplace_back
#define fir first
#define sec second
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
int n, m;
int main()
{
    scanf("%d%d", &n, &m);
    vii a, b;
    vi ca(1001, 0), cb(1001, 0);
    REP(i, n) {
        int x, y;
        scanf("%d%d", &x, &y);
        a.eb(y, x);
        ca[y]++;
    }
    REP(i, m) {
        int x,y ;
        scanf("%d%d", &x, &y);
        b.eb(y, x);
        cb[y]++;
    }
    sort(all(a));
    sort(all(b));
    int res1 = 0;
    FOR(i, 1, 1000) {
        int mn = min(ca[i], cb[i]);
        res1 += mn;
    }
    int i = 0, j = 0;
    int res2 = 0;
    while (i < n && j < m) {
        if (a[i].fir < b[j].fir) i++;
        else if (a[i].fir > b[j].fir) j++;
        else if (a[i].sec > b[j].sec) j++;
        else if (a[i].sec < b[j].sec) i++;
        else {
            res2++;
            i++; j++;
        }
    }
    cout << res1 << ' ' << res2 << '\n';
    return 0;
}
