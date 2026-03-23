// https://www.spoj.com/problems/RIOI_2_3/

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
    vector<vector<int>> g(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }

    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;

    vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
    int ans = 10;

    for(int mask = 0; mask < (1 << 10); mask++) {
        vector<int> v(10);
        int cnt = 0;
        for(int i = 0; i < 10; i++) {
            int b = (mask >> i) & 1;
            if(b) v[i] = 1, cnt++;
        }
        vector<vector<int>> vis(n, vector<int> (n));
        auto dfs = [&](auto&& dfs, int x, int y) -> void {
            vis[x][y] = 1;
            if(x == ex && y == ey) {
                ans = min(ans, cnt);
                return;
            }
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny] && v[g[nx][ny]]) {
                    dfs(dfs, nx, ny);
                }
            }
        };
        if(v[g[sx][sy]]) dfs(dfs, sx, sy);
    }

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
    cin >> t;
    for(int i = 1; i <= t; i++) {
        // cout << "\nCase #" << i << ":\n";
        solve();
    }

    return 0;
}
