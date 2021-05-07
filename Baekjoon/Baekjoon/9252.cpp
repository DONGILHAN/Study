#include <iostream>
#include <string>
using namespace std;
string a, b;
int dp[1001][1001] = {0, };
string LCS[1001][1001];
int main() {
    cin >> a;
    cin >> b;
    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                LCS[i][j] = LCS[i - 1][j - 1] + a[i - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if (LCS[i - 1][j].size() > LCS[i][j - 1].size())
                    LCS[i][j] = LCS[i - 1][j];
                else
                    LCS[i][j] = LCS[i][j - 1];
            }
        }
    }
    cout << dp[a.size()][b.size()] << "\n" << LCS[a.size()][b.size()];
}