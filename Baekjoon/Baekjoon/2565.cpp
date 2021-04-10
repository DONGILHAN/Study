#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> v;
int dp[501];

int main()
{
    int a, b;
    int temp, answer=0;
    cin >> N;
    for (int i=1;i<=N;i++) {
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end());
    dp[0]=1;
    for (int a=1; a<N; a++) {
        temp = 0;
        for (int b=0; b<=a; b++) {
            if (v[a].second > v[b].second && temp < dp[b]) {
                dp[a] = dp[b] + 1;
                temp = dp[b];
            }
            if (answer < dp[b])
                answer = dp[b];
            if (dp[a] == 0)
                dp[a]++;
        }
    }
    cout << N-answer;
}