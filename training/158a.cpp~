
#include <bits/stdc++.h>

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
int n, k;
VI a;
int main()
{
    scanf("%d%d", &n, &k);
    a.resize(n);
    REP(i, n) {
        scanf("%d", &a[i]);
    }
    int l = 0, r = n-1;
    for (; r >= 0; --r) {
        if (a[r] > 0) break;
    }
    while (l+1 < r) {
        int mid = (l+r) >> 1;
        if (a[mid] >= a[k-1]) l = mid;
        else r = mid - 1;
    }
    // cout << l << ' ' << r << endl;
    if (r < 0) {
        cout << 0 << endl;
    } else if (a[r] >= a[k-1]) {
        cout << r + 1 << endl;
    } else {
        cout << l + 1 << endl;
    }
    return 0;
}
