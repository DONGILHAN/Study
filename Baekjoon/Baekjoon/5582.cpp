#include <iostream>
#include <string>
using namespace std;
string s, t;
int dp[4000][4000] = {0, };
int answer= 0;
int main() {
    cin >> s;
    cin >> t;
    for (int i = 0; i < t.size(); i++) {
        if (s[0] == t[i])
            dp[0][i] = 1;
    }
    for (int i = 0; i < s.size(); i++) {
        if (t[0] == s[i])
            dp[i][0] = 1;
    }
    for (int i = 1; i < t.size(); i++) {
        for (int j = 1; j < s.size(); j++) {
            if (t[i] == s[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (answer < dp[i][j])
                    answer = dp[i][j];
            }
        }
    }
    cout << answer;
}