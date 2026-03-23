// https://acm.timus.ru/problem.aspx?space=1&num=1106

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
    vector<vector<int>> g(n);
    for(int i = 0; i < n; i++) {
        while(1) {
            int x; cin >> x;
            if(x--) g[i].push_back(x);
            else break;
        }
    }

    vector<int> vis(n, -1);

    auto dfs = [&](auto&& dfs, int u, int p = 0) -> void {
        vis[u] = p;
        for(auto& v : g[u]) {
            if(vis[v] == -1) {
                dfs(dfs, v, 1 - p);
            }
        }
    };

    for(int i = 0; i < n; i++) {
        if(vis[i] == -1) dfs(dfs, i);
    }

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(vis[i] == 0) cnt++;
    }

    cout << cnt << "\n";
    for(int i = 0; i < n; i++) {
        if(vis[i] == 0) cout << i + 1 << " ";
    }
    cout << "\n";
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
