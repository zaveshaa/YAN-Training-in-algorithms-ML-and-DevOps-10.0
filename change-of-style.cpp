#include <iostream>
#include <string>
#include <cctype>

using namespace std; 

int main() 
{
    int n;

    cin >> n;

    for (int i = 0; i < n; ++i) {

        string s;

        cin >> s; 

        if (!s.empty()) {

            cout << (char)tolower(s[0]);

        }

        for (int j = 1; j < s.length(); ++j) {

            if (isupper(s[j])) {

                cout << '_' << (char)tolower(s[j]);

            } else {

                cout << s[j];

            }
        }
        
        cout << "\n"; 

    }
    
    return 0;
}
