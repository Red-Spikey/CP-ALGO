// https://codeforces.com/contest/727/problem/A

#include<bits/stdc++.h>
using namespace std;

using i64 = long long int;
#define deb(...) debug(#__VA_ARGS__, __VA_ARGS__)
template<typename T>
void debug(const char* t, T&& v) {cout << t << " = " << v << '\n';}
template<typename T, typename... Args>
void debug(const char* n, T&& v, Args&&... args) {
    const char* c = strchr(n, ','); cout.write(n, c - n) << " = " << v << " |";
    debug(c + 1, std::forward<Args>(args)...);
}

constexpr int mod = 1'000'000'007;
// constexpr int mod = 998244353;

void solve() {
    int a, b;
    cin >> a >> b;

    vector<int> ans;
    auto dfs = [&](this auto&& dfs, i64 u) -> bool {
        // deb(u);
        if(u == b) {
            ans.push_back(u);
            return true;
        }
        if(u > b) return false;

        if(dfs(1LL * 2 * u)) {
            ans.push_back(u);
            return true;
        }
        if(dfs(1LL * 10 * u + 1)) {
            ans.push_back(u);
            return true;
        }

        return false;
    };
    dfs(a);

    reverse(ans.begin(), ans.end());
    if(!ans.size()) cout << "NO\n";
    else {
        cout << "YES\n" << ans.size() << "\n";
        for(auto x : ans) cout << x << " ";
    cout << "\n";
    }
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