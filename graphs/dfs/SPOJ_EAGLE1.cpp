// https://www.spoj.com/problems/EAGLE1/

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

    vector<vector<pair<int, int>>> g(n);
    for(int i = 0; i < n - 1; i++) {
    	int u, v, d; cin >> u >> v >> d;
    	u--, v--;
    	g[u].push_back({v, d});
    	g[v].push_back({u, d});
    }

    vector<int> vis(n);
    vector<i64> dis(n), dis2(n);

    auto dfs = [&](auto&& dfs, int u, vector<i64>& d, i64 cnt = 0) -> void {
    	vis[u] = 1;
    	d[u] = cnt;
    	for(auto& [v, x] : g[u]) {
    		if(!vis[v]) dfs(dfs, v, d, cnt + x);
    	}
    };

    dfs(dfs, 0, dis);

    int pt1 = 0, pt2 = 0;
    i64 mx = 0;

    for(int i = 0; i < n; i++) {
    	if(dis[i] > mx) {
    		pt1 = i;
    		mx = dis[i];
    	}
    }

    fill(vis.begin(), vis.end(), 0);
    dfs(dfs, pt1, dis);

    mx = 0;

    for(int i = 0; i < n; i++) {
    	if(dis[i] > mx) {
    		pt2 = i;
    		mx = dis[i];
    	}
    }

    fill(vis.begin(), vis.end(), 0);
    dfs(dfs, pt2, dis2);

    for(int i = 0; i < n; i++) {
    	cout << max(dis[i], dis2[i]) << " ";
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
    cin >> t;
    for(int i = 1; i <= t; i++) {
        // cout << "\nCase #" << i << ":\n";
        solve();
    }

    return 0;
}
