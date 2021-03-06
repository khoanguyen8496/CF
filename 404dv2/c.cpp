
#include <bits/stdc++.h>
// #define DEBUG
#define PB push_back
#define MP make_pair
#define REP(i, n) for (int (i)=0, _n(n); (i) < _n; ++i)
#define FOR(i, a, b) for (int (i)=(a), _b(b); i <= _b; ++i)
#define REPR(i, n) for (int i=(n)-1; i >= 0; --i)
#define FORR(i, a, b) for (int (i)=(a), _b(b); i >= _b; --i)
#define TR(it, container) \
    for (typeof(container.begin()) it = container.begin(); it!= container.end(); ++it)
#define ALL(a) a.begin(),a.end()
#define SZ(a) a.size()
#define EB emplace_back
#define F first
#define S second
#define DB(a) \
  {cerr<< #a << " : " << a << '\n';}

using namespace std;
typedef pair<int, int> II;
typedef vector<II> VII;
typedef vector<string> VS;
typedef long long LL;
typedef vector<LL> VLL;
typedef vector<int> VI;
typedef vector<double> VD;
typedef pair<double, double> DD;
typedef vector<DD> VDD;
typedef vector<VI> VVI;
typedef vector<VD> VVD;
LL n, m;

int main()
{
#ifdef DEBUG
    freopen("in", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    if ( n <= m) {
        cout << n << endl;
        return 0;
    }
    if (n-m-1 == 0) {
        cout << m+1 << endl;
        return 0;
    }
    LL res = m;
    // cerr << "RES " << res << endl;
    LL l(1), r(n-m);
    while (l + 1 < r) {
        LL mid = (l+r) >> 1;
        // cerr << l << ' ' << r  << endl;
        if ((double)mid >= (n-m)*2.0/(mid+1.0))
            r = mid;
        else
            l = mid+1;
    }
    // cerr << l << ' ' << r << endl;
    if ((double)l >= (n-m)*2.0/(l+1.0)) {
        res +=l;
    }
    else res += r;
    cout << res << endl;
    return 0;
}
