
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
const int N = 2*1e5+1;
int n, m;
int BIT[N];
int a[N];
void updateBIT(int x, int val) 
{
    while (x <= n) {
        BIT[x] += val;
        x+= (x & -x);
    }
}
int queryBIT(int x) 
{
    int res = 0;
    while (x > 0) {
        res += BIT[x];
        x-= (x & -x);
    }
    return (int)res;
}
int main()
{
    scanf("%d%d", &n, &m);
    REP(i, n) {
        scanf("%d", &a[i]);
    }
    REP(i, m) {
        int l, r;
        scanf("%d%d", &l, &r);
        swap(a[l], a[r]);
    }
    return 0;
}
