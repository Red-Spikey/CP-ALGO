// https://acm.timus.ru/problem.aspx?space=1&num=1709

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
    int d, a; cin >> d >> a;

    vector<string> g(n);
    for(auto& x : g) cin >> x;

    vector<string> s(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            s[i] += '0';
        }
    }
    
    vector<int> vis(n);
    i64 cnt_d = 0, cnt_a = 0;
    auto dfs = [&](auto&& dfs, int u, int p = -1) -> void {
        vis[u] = 1;
        for(int v = 0; v < n; v++) {
            if(g[u][v] == '1') {
                if(!vis[v]) dfs(dfs, v, u);
                else if(v != p && s[u][v] != 'd') {
                    s[u][v] = 'd';
                    s[v][u] = 'd';
                    cnt_d++;
                }
            }
        }
    };

    int prev = -1;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(dfs, i);
            if(prev != -1) {
                s[prev][i] = 'a';
                s[i][prev] = 'a';
                cnt_a++;
            }
            prev = i;
        }
    }

    cout << d * cnt_d + a * cnt_a << "\n";
    for(auto& x : s) cout << x << "\n";
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
