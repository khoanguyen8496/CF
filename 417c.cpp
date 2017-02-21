#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int N = 5000;
int n, k;
int a[N][N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    vii res;
    bool possible = 1;
    for (int i = 1; i <= n; ++i) {
        int cnt = k;
        for (int j = 1; j <= n; ++j) 
            if (cnt)
            if (i != j && a[i][j] == 0) {
                res.pb(mp(i, j));
                a[i][j] = 1;
                a[j][i] = -1;
                cnt--;
            }
        if (cnt != 0) {
            possible = 0;
            break;
        }
    }
    if (possible == 0) {
        cout << "-1\n";
    }
    else {
        cout << res.size() << '\n';
        for (int i = 0; i < res.size(); ++i) {
            cout << res[i].first << ' ' << res[i].second << '\n';
        }
    }
    return 0;
}
