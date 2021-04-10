#include <iostream>
using namespace std;

int A[1001] = {0, };
int dp[1001] = {0, };
int N=0, t=0, answer = 1, temp = 0;
int main()
{
    cin>>N;
    for(int a=1; a<=N; a++) {
        cin >> A[a];
    }
    dp[1]=1;
    for (int a=2; a<=N; a++) {
        temp = 0;
        for (int b=1; b<=a; b++) {
            if (A[a] > A[b] && temp < dp[b]) {
                dp[a] = dp[b] + 1;
                temp = dp[b];
            }
            if (answer < dp[b])
                answer = dp[b];
            if (dp[a] == 0)
                dp[a]++;
        }
    }
    cout << answer;
}