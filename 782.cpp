
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
const int N = 2*1e5+1;
int n;
VI adj[N];
vector<bool> visited;
VI color;
VI par;
int mx_color;
void dfs(int u)
{
    visited[u] = 1;
    int col = 0;
    for (auto & v : adj[u]) if (!visited[v]){
        col++;
        while (col == color[u] || col == color[par[u]])
            col++;
        color[v] = col;
        mx_color = max(mx_color, col);
        par[v] = u;
        dfs(v);
    }
}
int main()
{
#ifdef DEBUG
    freopen("in", "r", stdin);
#endif
    scanf("%d", &n);
    color.resize(n+1);
    visited.resize(n+1);
    par.resize(n+1);
    REP(i, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].PB(v);
        adj[v].PB(u);
    }
    int start_vertex = 0;
    FOR(i, 1, n) {
        if (adj[i].size() == 1)
        {
            start_vertex = i;
            break;
        }
    }
    par[start_vertex] = start_vertex;
    color[start_vertex] = 1;
    mx_color = 1;
    dfs(start_vertex);
    printf("%d\n", mx_color);
    FOR(i, 1, n) {
        printf("%d ", color[i]);
    }
    return 0;
}
