#include <bits/stdc++.h>
using namespace std;
int n;

int main()
{
    freopen("inp", "r", stdin);
    scanf("%d", &n);
    set<int> a;
    for (int i = 1; i <= n; ++i)
        a.insert(i);
    for (int i = 0; i < n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        auto && it= a.lower_bound(tmp);
        // cout << *it << '\n';
        if (it == a.end()) 
            cout << '\n';
        else {
            vector<int> t;
            for (auto && x = it; x != a.rend(); --x) {
                t.push_back(*x);
                cout << *x << ' ';
            }
            for (auto && x : t) {
                a.erase(x);
            }
        }
    }
    return 0;
}
