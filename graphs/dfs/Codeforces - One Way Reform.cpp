// https://cp-algorithms.com/graph/depth-first-search.html

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
    int n, m; cin >> n >> m;

    vector<vector<int>> g(n), edge(n, vector<int>(n)), real(n, vector<int>(n));

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--, v--;

        g[u].push_back(v);
        g[v].push_back(u);
        real[u][v] = real[v][u] = 1;
        edge[u][v]++;
        edge[v][u]++;
    }

    vector<int> odd;
    for(int i = 0; i < n; i++) {
        if(g[i].size() & 1) odd.push_back(i);
    }
    for(int i = 0; i < odd.size(); i += 2) {
        int u = odd[i], v = odd[i + 1];
        g[u].push_back(v);
        g[v].push_back(u);
        edge[u][v]++;
        edge[v][u]++;
    }

    vector<int> path, vis(n);

    auto euler = [&](auto&& euler, int u) -> void {
        vis[u] = 1;
        for(auto& v : g[u]) {
            if(edge[u][v] > 0) {
                edge[u][v]--;
                edge[v][u]--;
                euler(euler, v);
            }
        }
        path.push_back(u);
    };

    for(int i = 0; i < n; i++) {
        if(!vis[i]) euler(euler, i);
    }

    reverse(path.begin(), path.end());
    
    vector<pair<int, int>> res;
    for(int i = 0; i < path.size() - 1; i++) {
        int u = path[i], v = path[i + 1];
        if(real[u][v]) {
            res.push_back({u, v});
            real[u][v] = real[v][u] = 0;
        }
    }

    cout << n - odd.size() << "\n";
    for(auto f : res) cout << f.first + 1 << " " << f.second + 1 << "\n";
}


int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        // cout << "\nCase #" << i << ":\n";
        solve();
    }

    return 0;
}