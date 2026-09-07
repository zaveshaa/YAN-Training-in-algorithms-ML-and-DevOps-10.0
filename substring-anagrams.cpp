#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    string s, t;

    if (!(cin >> s >> t)) return 0;

    vector<int> target_count(26, 0);

    vector<int> window_count(26, 0);

    for (char ch : t) {

        target_count[ch - 'a']++;

    }

    long long ans = 0;

    int R = 0;

    for (int L = 0; L < s.length(); ++L) {

        while (R < s.length()) {

            int char_idx = s[R] - 'a';

            if (window_count[char_idx] + 1 > target_count[char_idx]) {

                break;
            }
            window_count[char_idx]++;

            R++;
        }

        ans += (R - L);
        
        window_count[s[L] - 'a']--;
    }

    cout << ans << "\n";

    return 0;
}
