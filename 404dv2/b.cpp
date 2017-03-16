
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
const int N = 200001;
VII a, b;
bool cmp1(const II & a, const II & b)
{
    return a.F < b.F;
}
bool cmp2(const II & a, const II & b)
{
    return a.S < b.S;
}
int main()
{
    int n;
    scanf("%d", &n);
    REP(i, n) {
        int l, r;
        scanf("%d%d", &l, &r);
        a.emplace_back(l, r);
    }
    int m;
    scanf("%d", &m);
    REP(i, m) {
        int l, r;
        scanf("%d%d", &l, &r);
        b.emplace_back(l, r);
    }
    sort(ALL(a), cmp1);
    sort(ALL(b), cmp2);
    long long res = a[n-1].F - b[0].S;
    sort(ALL(a), cmp2);
    sort(ALL(b), cmp1);
    res = max(res, (long long)b[m-1].F - a[0].S);
    res = max(0LL, res);
    cout << res << endl;
    return 0;
}
