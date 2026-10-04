#include <bits/stdc++.h>
using namespace std;

int main() {
    int d, sumTime;
    cin >> d >> sumTime;

    vector<int> lo(d), hi(d);
    int sumMin = 0, sumMax = 0;
    for (int i = 0; i < d; i++) {
        cin >> lo[i] >> hi[i];
        sumMin += lo[i];
        sumMax += hi[i];
    }

    if (sumTime < sumMin || sumTime > sumMax) {
        cout << "NO\n";
        return 0;
    }

    int rem = sumTime - sumMin;  // hours still to hand out
    cout << "YES\n";
    for (int i = 0; i < d; i++) {
        int add = min(hi[i] - lo[i], rem);
        cout << lo[i] + add << " ";
        rem -= add;
    }
    cout << "\n";
    return 0;
}