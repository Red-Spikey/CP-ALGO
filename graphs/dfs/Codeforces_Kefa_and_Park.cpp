// https://codeforces.com/problemset/problem/580/C

#include<bits/stdc++.h>
using namespace std;

using i64 = long long int;
#define deb(...) debug(#__VA_ARGS__, __VA_ARGS__)
template<typename T>
void debug(const char* t, T&& v) {cout << t << " = " << v << '\n';}
template<typename T, typename... Args>
void debug(const char* n, T&& v, Args&&... args) {
    const char* c = strchr(n, ','); cout.write(n, c - n) << " = " << v << " |";
    debug(c + 1, std::forward<Args>(args)...);
}

constexpr int mod = 1'000'000'007;
// constexpr int mod = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> cats(n);
    for(auto& x : cats) cin >> x;

    vector<vector<int>> g(n + 1);
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ans = 0;
    auto dfs = [&](this auto&& dfs, int u, int par, int cnt) -> void {
        // deb(u);
        if(cnt > m) return;
        bool flag = 0;
        for(auto v : g[u]) {
            if(v == par) continue;
            dfs(v, u, cats[v]*(cnt + cats[v]));
            flag = 1;
        }
        if(!flag) ans++;
    };
    dfs(0, -1, cats[0]);

    cout << ans << "\n";
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