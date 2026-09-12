#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k;
    cin >> n >> k;

    vector<long long> a(n);
    unordered_map<long long, long long> cnt;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    long long removed = 0;
    unordered_set<long long> seen;
    for (long long x : a) {
        if (seen.count(x)) continue;
        long long y = k - x;
        if (y == x) {
            removed += cnt[x] - 1;          
        } else if (cnt.count(y) && !seen.count(y)) {
            removed += min(cnt[x], cnt[y]); 
        }
        seen.insert(x);
    }

    cout << removed << '\n';
    return 0;
}
