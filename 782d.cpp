
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
const int N = 1001;
int n;
string a[N], b[N];
VS splitWords(const string & x)
{
    string fi, se;
    REP(i, SZ(x)) {
        if (x[i] == ' ') {
            fi = x.substr(0, i);
            se = x.substr(i+1);
            break;
        }
    }
    return VS{fi, se};
}

int main()
{
#ifdef DEBUG
    freopen("in", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    string tmp;
    getline(cin, tmp);
    REP(i, n) {
        string line;
        getline(cin, line);
        // cerr << "string " << line << '\n';
        VS tmp = splitWords(line);
        // cerr << tmp[0] << ' ' << tmp[1]<< endl;
        // cerr << tmp[0].substr(0,3);
        a[i] = tmp[0].substr(0,3);
        b[i] = tmp[0].substr(0,2) + tmp[1].substr(0,1);
    }
    VS res(n);
    map<string, int> asd;
    REP(i, n) {
        bool opt = 0;
        REP(j, n) if (i != j) {
            if (a[i] == a[j]) {
                opt = 1;
            }
        }
        if (opt) {
            res[i] = b[i];
            asd[res[i]]++;
        } else {
            if (asd.find(a[i]) != asd.end()) {
                res[i] = b[i];
            }
            else res[i] = a[i];
            asd[res[i]]++;
        }
    }
    for (auto & x : asd) {
        if (x.S > 1) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    REP(i, n)
        cout << res[i] << '\n';
    return 0;
}
