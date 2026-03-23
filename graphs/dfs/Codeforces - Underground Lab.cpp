// https://codeforces.com/contest/781/problem/C

#include <bits/stdc++.h>
using namespace std;

#define deb(...) debug(#__VA_ARGS__, __VA_ARGS__)
template<typename T>
void debug(const char* t, T&& v) {cout << t << " = " << v << '\n';}
template<typename T, typename... Args>
void debug(const char* n, T&& v, Args&&... args) {
    const char* c = strchr(n, ','); cout.write(n, c - n) << " = " << v << " |";
    debug(c + 1, std::forward<Args>(args)...);
}

using i64 = long long int;
constexpr int mod = 1'000'000'007;
// constexpr int mod = 998244353;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> g(n);

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> ans, vis(n);

    auto dfs = [&](auto&& dfs, int u) -> void {
        vis[u] = 1;
        ans.push_back(u + 1);
        for(auto& v : g[u]) {
            if(!vis[v]) {
                dfs(dfs, v);
                ans.push_back(u + 1);
            }
        }
    };

    dfs(dfs, 0);

    int mx = (2 * n + k - 1) / k;
    int cnt = 0;
    for(int i = 0; i < ans.size(); i++) {
        if(i % mx == 0) {
            if(i) cout << "\n";
            cout << min((int)ans.size() - i, mx) << " ";
            cnt++;
        }
        cout << ans[i] << " ";
    }
    while(cnt < k) {
        cout << "1 1\n";
        cnt++;
    }
}


int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++) {
        // cout << "\nCase #" << i << ":\n";
        solve();
    }

    return 0;
}