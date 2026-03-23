// https://www.spoj.com/problems/ABCPATH/

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
typedef long long ll;
constexpr int mod = 1'000'000'007;
// constexpr int mod = 998244353;
int maxstring;
int deli[] = {1,1,1,0,0,-1,-1,-1};
int delj[] = {1,0,-1,1,-1,1,0,-1};
int h , w;
void dfs(int i, int j, vector<string> &grid, vector<vector<int>> & vis){
    // start dfs at this A
    if(maxstring == 26) return;
    int curlevel = grid[i][j]-'A'; // starts from 0
    vis[i][j] = 1;
    maxstring = max(maxstring, curlevel + 1);
    int newi, newj;
    for(int k = 0; k< 8; k++){
        newi = i + deli[k];
        newj = j + delj[k];
        if(newi < 0 || newj < 0 || newi >= h || newj >= w) continue;
        if(grid[newi][newj] != grid[i][j] + 1) continue;
        // explore this one;
        if(!vis[newi][newj]) dfs(newi, newj, grid, vis);
    }
}
int solve(){
    maxstring = 0;
    vector<string> grid(h);
    vector<vector<int>> vis(h, vector<int>(w, 0));
    for(int i = 0; i< h; i++){
        cin >> grid[i];
    }
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            if(grid[i][j] == 'A'){
                dfs(i,j, grid, vis);
            }
        }
    }
    return maxstring;
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int cnt = 1;
    
while(cin >> h >> w && (h || w)){
    cout << "Case " << cnt << ": " << solve() << "\n";
    cnt++;
}
    return 0;
}