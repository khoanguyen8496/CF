
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
typedef pair<ll, int> lli;
typedef vector<lli> vlli;
typedef vector<ll> vll;
typedef vector<int> vi;
const int N = 100001;
int n, m;
int a,b;
vlli c;
int main()
{
    // freopen("inp", "r", stdin);
    scanf("%d%d", &n, &m);
    scanf("%d%d", &a, &b);
    REP(i,n) {
        int x ,y;
        scanf("%d%d", &x, &y);
        c.pb(mp((ll)x*a+(ll)y*b, i+1));
    }
    sort(all(c));
    vi res;
    REP(i,n) if (m >= c[i].fir) {
        res.pb((int)c[i].sec);
        m-= c[i].fir;
    }
    else 
        break;
    cout << sz(res) << '\n';
    REP(i, sz(res)) {
        cout << res[i] << ' ';
    }
    return 0;
}
