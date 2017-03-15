
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
int n;
int main()
{
    scanf("%d", &n);
    vector<int> a(2*n, 0);
    REP(i, 2*n) {
        scanf("%d", &a[i]);
    }
    set<int> s;
    int cnt = 0;
    int res = 0;
    REP(i, 2*n) {
        if (s.find(a[i]) != s.end()) {
            s.erase(a[i]);
            cnt--;
        }
        else {
            s.insert(a[i]);
            cnt++;
            res = max(res, cnt);
        }
    }
    printf("%d\n", res);
    return 0;
}
