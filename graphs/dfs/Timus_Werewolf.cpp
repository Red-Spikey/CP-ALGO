// https://acm.timus.ru/problem.aspx?space=1&num=1242

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
    vector<vector<int>> p(n), c(n);

    string s;
    while(cin >> s) {
        if(s == "BLOOD") break;

        int child = stoi(s);
        int parent; cin >> parent;

        child--, parent--;
        c[parent].push_back(child);
        p[child].push_back(parent);
    }

    vector<int> vis(n);

    auto dfs = [&](auto&& dfs, int u, bool flag) -> void {
        vis[u] = 1;

        if(flag) {
            for(auto& v : p[u]) {
                if(!vis[v]) dfs(dfs, v, flag);
            }
        } else {
            for(auto& v : c[u]) {
                if(!vis[v]) dfs(dfs, v, flag);
            }
        }
    };

    int x;
    while(cin >> x) {
        x--;
        dfs(dfs, x, 1);
        dfs(dfs, x, 0);
    }

    bool found = 0;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            cout << i + 1 << " ";
            found = 1;
        }
    }
    if(!found) cout << 0;
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
