// https://www.spoj.com/problems/GHOSTS/

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
    int n, t; cin >> n >> t;

    vector<bitset<1000>> reach(n);
    for(int i = 0; i < n; i++) reach[i][i] = 1;

    for(int i = 0; i < t; i++) {
        int a, b; cin >> a >> b;
        a--, b--;

        if(reach[b][a]) {
            cout << a + 1 << " " << b + 1 << "\n";
            continue;
        }

        reach[a] |= reach[b];

        for(int j = 0; j < n; j++) {
            if(reach[j][a]) reach[j] |= reach[a];
        }
    }

    cout << "0 0\n";
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
