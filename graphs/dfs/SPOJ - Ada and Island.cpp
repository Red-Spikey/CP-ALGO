// https://www.spoj.com/problems/ADASEA/

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

    vector<string> s(n);
    for(auto& x : s) cin >> x;

    vector<vector<int>> vis(n, vector<int>(m));
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    auto dfs = [&](auto&& dfs, int u, int v) -> int {
        vis[u][v] = 1;
        int cnt = 1;
        for(int i = 0; i < 4; i++) {
            int nu = u + dx[i];
            int nv = v + dy[i];
            if(nu >= 0 && nu < n && nv >= 0 && nv < m && !vis[nu][nv] && s[nu][nv] == '#') {
                cnt += dfs(dfs, nu, nv);
            }
        }
        return cnt;
    };

    i64 num = 0, den = n * m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vis[i][j] && s[i][j] == '#') {
                int x = dfs(dfs, i, j);
                num += 1LL * x * x;
            }
        }
    }

    i64 fac = __gcd(num, den);
    num /= fac;
    den /= fac;

    if(den == 1) cout << num << "\n";
    else cout << num << " / " << den << "\n";
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
