#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Env { int w, h, id; };

int main() {
    int n, cw, ch;
    cin >> n >> cw >> ch;

    vector<Env> v;
    for (int i = 1; i <= n; i++) {
        int w, h;
        cin >> w >> h;
        if (w > cw && h > ch) v.push_back({w, h, i});
    }

    sort(v.begin(), v.end(), [](const Env& a, const Env& b) {
        if (a.w != b.w) return a.w < b.w;
        return a.h < b.h;
    });

    int m = v.size();
    if (m == 0) {
        cout << 0 << "\n";
        return 0;
    }

    vector<int> dp(m, 1), par(m, -1);
    int best = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < i; j++) {
            if (v[j].w < v[i].w && v[j].h < v[i].h && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                par[i] = j;
            }
        }
        if (dp[i] > dp[best]) best = i;
    }

    vector<int> chain;
    for (int i = best; i != -1; i = par[i]) chain.push_back(v[i].id);
    reverse(chain.begin(), chain.end());

    cout << chain.size() << "\n";
    for (int x : chain) cout << x << " ";
    cout << "\n";
    return 0;
}