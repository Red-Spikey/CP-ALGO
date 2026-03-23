// https://codeforces.com/contest/734/problem/E

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
    int n; cin >> n;
    vector<int> color(n);
    for(auto& x : color) cin >> x;

    vector<vector<int>> g(n);
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> vis(n), same(n);

    auto mark = [&](auto&& mark, int u, int head) -> void {
        vis[u] = 1;
        same[u] = head;
        for(auto& v : g[u]) {
            if(!vis[v] && color[u] == color[v]) {
                mark(mark, v, head);
            }
        }
    };

    for(int i = 0; i < n; i++) {
        if(!vis[i]) mark(mark, i, i);
    }

    // for(int i = 0; i < n; i++) {
    //     cout << same[i] << " ";
    // }
    // cout << "\n";

    fill(vis.begin(), vis.end(), 0);
    vector<set<int>> ng(n);

    auto bi = [&](auto&& bi, int u) -> void {
        vis[u] = 1;
        for(auto& v : g[u]) {
            if(!vis[v]) {
                if(color[u] != color[v]) {
                    ng[same[u]].insert(same[v]);
                    ng[same[v]].insert(same[u]);
                }
                bi(bi, v);
            }
        }
    };

    bi(bi, 0);

    fill(vis.begin(), vis.end(), 0);
    vector<int> dis(n);

    auto dia = [&](auto&& dia, int u, int cnt, vector<int>& d) -> void {
        vis[u] = 1;
        d[u] = cnt;
        // deb(d[u], cnt, u);
        for(auto& v : ng[u]) {
            if(!vis[v]) dia(dia, v, cnt + 1, d);
        }
    };

    dia(dia, 0, 0, dis);
    int end1 = -1, mx = -1;
    for(int i = 0; i < n; i++) {
        if(dis[i] > mx) {
            end1 = i;
            mx = dis[i];
        }
    }
    // for(auto& v : ng[0]) {
    //     cout << v << " ";
    // }
    // cout << "\n";
    // for(int i = 0; i < n; i++) {
    //     cout << dis[i] << " ";
    // }
    // cout << "\n";
    // deb(end1, mx);

    fill(dis.begin(), dis.end(), 0);
    fill(vis.begin(), vis.end(), 0);
    dia(dia, end1, 0, dis);

    mx = -1;
    for(int i = 0; i < n; i++) {
        mx = max(mx, dis[i]);
    }

    cout << (mx + 1) / 2;
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