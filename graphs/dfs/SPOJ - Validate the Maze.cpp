// https://www.spoj.com/problems/MAKEMAZE/

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
    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for(auto& x : s) cin >> x;

    vector<vector<int>> vis(n, vector<int>(m));
    vector<int> du = {1, -1, 0, 0}, dv = {0, 0, 1, -1};

    auto dfs = [&](auto&& dfs, int u, int v) -> void {
        vis[u][v] = 1;
        for(int i = 0; i < 4; i++) {
            int nu = u + du[i];
            int nv = v + dv[i];

            if(nu >= 0 && nu < n && nv >= 0 && nv < m && !vis[nu][nv] && s[nu][nv] == '.') {
                // deb(nu, nv);
                dfs(dfs, nu, nv);
            }
        }
    };

    for(int i = 0; i < n; i++) {
        bool flag = 0;
        for(int j = 0; j < m; j++) {
            if((i == 0 || i == n - 1 || j == 0 || j == m - 1) && s[i][j] == '.') {
                dfs(dfs, i, j);
                flag = 1;
                break;
            }
        }
        if(flag) break;
    }

    int cnt = 0, tot = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if((i == 0 || i == n - 1 || j == 0 || j == m - 1) && s[i][j] == '.') {
                tot++;
                if(vis[i][j]) cnt++;
            }
        }
    }
    // deb(cnt, tot);

    if(tot == 2 && cnt == 2) cout << "valid\n";
    else cout << "invalid\n";
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
