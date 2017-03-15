
#include <bits/stdc++.h>
//#define DEBUG
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
#define GCD(a, b) \
((b) == 0)? (b) : GCD((b), (a)%(b))
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
#define eps 1e-7
int n;
VII a;
vector<pair<double, double>> it;
bool calc(double mid)
{
    //calculate intervals;
    REP(i, n) {
        it[i] = MP(a[i].F - a[i].S*mid, a[i].F + a[i].S*mid);
    }
    double left = it[0].F, right = it[0].S;
    REP(i, n) {
        left = max(it[i].F, left);
        right = min(it[i].S, right);
    }
    // printf("lr %lf %lf\n", left, right);
    return left + eps <= right;
}
int main()
{
#ifdef DEBUG
    freopen("in", "r", stdin);
#endif
    scanf("%d", &n);
    a.resize(n);
    it.resize(n);
    for (auto & x : a) {
        scanf("%d", &x.F);
    }
    for (auto & x : a) {
        scanf("%d", &x.S);
    }
    double l = 0, r = fabs(a[n-1].F - a[0].F)/(double)a[n-1].S;
    // cerr << l << ' ' << r << endl;
    for (auto & x : a) {
        r = max(r, fabs(a[0].F - x.F)/(double)x.S);
    }
    while (l + eps < r) {
        double mid = (l+r)/2;
        // printf("%lf %lf\n", l, r);
        if (calc(mid))
            r = mid;
        else l = mid;
    }
    printf("%.6lf\n", l);
    return 0;
}
