// https://www.spoj.com/problems/KOZE/

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

    vector<string> g(n);
    for(auto& x : g) cin >> x;

    vector<vector<int>> vis(n, vector<int>(m));
    bool flag = 0;

    vector<int> du = {1, -1, 0, 0};
    vector<int> dv=  {0, 0, 1, -1};

    auto dfs = [&](auto&& dfs, int u, int v) -> pair<int, int> {
        vis[u][v] = 1;
        int s = (g[u][v] == 'k');
        int w = (g[u][v] == 'v');
        for(int i = 0; i < 4; i++) {
            int nu = u + du[i];
            int nv = v + dv[i];
            if(nu < 0 || nu >= n || nv < 0 || nv >= m) {
                flag = 1;
            } else if(!vis[nu][nv] && g[nu][nv] != '#') {
                auto [sheep, wolve] = dfs(dfs, nu, nv);
                s += sheep;
                w += wolve;
            }
        }
        return make_pair(s, w);
    };

    int sheep = 0, wolve = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(g[i][j] != '#' && !vis[i][j]) {
                auto [s, w] = dfs(dfs, i, j);
                if(flag) sheep += s, wolve += w;
                else {
                    sheep += (s > w ? s : 0);
                    wolve += (s > w ? 0 : w);
                }
                flag = 0;
            }
        }
    }

    cout << sheep << " " << wolve;
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
