// https://codeforces.com/contest/709/problem/E

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
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> tot(n), maxi(n), ans(n);

    auto dfs = [&](auto&& dfs, int u, int p = -1) -> int {
        int cnt = 1, mx = 0, smx = 0;
        for(auto& v : g[u]) {
            if(v != p)  {
                int val = dfs(dfs, v, u);
                if(val >= mx && val <= n / 2) mx = max(mx, val);
                mx = max(mx, maxi[v]);
                cnt += val;
            }
        }
        tot[u] = cnt;
        maxi[u] = mx;
        return cnt;
    };

    dfs(dfs, 0);
    // deb(maxi[8]);

    // for(int i = 0; i < n; i++) cout << maxi[i] << " "; cout << "\n";

    auto dfs2 = [&](auto&& dfs2, int u, int p = -1) -> void {
        bool flag = 1;
        vector<int> temp;
        // deb(u);
        for(auto& v : g[u]) {
            // deb(v, tot[v], maxi[v]);
            if(tot[v] > n / 2 &&  tot[v] - maxi[v] > n / 2) flag = 0;
            int mx = maxi[v];
            if(tot[v] <= n / 2) mx = max(mx, tot[v]);
            temp.push_back(mx);
        }
        ans[u] = flag;
        int sz = temp.size();
        vector<int> pre = temp, suf = temp;
        for(int i = 1; i < sz; i++) pre[i] = max(pre[i - 1], pre[i]);
        for(int i = sz - 2; i >= 0; i--) suf[i] = max(suf[i], suf[i + 1]);
        int old_tot = tot[u];
        int old_mx = maxi[u];
        int ind = 0;
        // if(u == 1) {
        //     for(int i = 0; i < temp.size(); i++) cout << temp[i] << " ";
        //     cout << "\n";
        //     for(int i = 0; i < temp.size(); i++) cout << pre[i] << " ";
        //         cout << "\n";
        //     for(int i = 0; i < temp.size(); i++) cout << suf[i] << " ";
        //     cout << "\n";
        // }
        // deb(g[u].size());
        for(auto& v : g[u]) {
            if(v == p) {
                ind++;
                continue;
            }

            // store
            int old_v = tot[v];
            int old_mxv = maxi[v];

            // reroot
            tot[u] -= tot[v];
            tot[v] += tot[u];
            int mx_u = 0;
            if(ind > 0) mx_u = max(mx_u, pre[ind - 1]);
            // deb(ind, mx_u, suf.size(), suf[ind + 1]);
            if(ind + 1 < sz) mx_u = max(mx_u, suf[ind + 1]);
            // maxi[u] = max(tot[u], mx_u);
            if(tot[u] <= n / 2) mx_u = max(mx_u, tot[u]);
            maxi[u] = mx_u;
            // if(u == 1 && v == 4) deb(maxi[u], mx_u);

            // new max
            maxi[v] = max(maxi[v], maxi[u]);

            dfs2(dfs2, v, u);

            // restore
            tot[u] = old_tot;
            maxi[u] = old_mx;
            tot[v] = old_v;
            maxi[v] = old_mxv;
            ind++;
        }
    };

    dfs2(dfs2, 0);

    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
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