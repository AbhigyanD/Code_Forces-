#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<string, int> cnt;

    while (n--) {
        string s;
        cin >> s;

        if (!cnt.count(s)) {
            cnt[s] = 0;
            cout << "OK\n";
        } else {
            int k = cnt[s] + 1;
            while (cnt.count(s + to_string(k))) k++;
            cnt[s + to_string(k)] = 0;
            cout << s + to_string(k) << "\n";
            cnt[s] = k;
        }
    }
}