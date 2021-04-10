#include <iostream>
using namespace std;

int N=0;
int A[1001]={0, };
int dp[1001][2] = {0, };
int temp = 0, answer =0;
int main()
{
    cin>>N;
    for(int a=1;a<=N;a++)
        cin>>A[a];
    dp[1][0] = 1;
    dp[N][1] = 1;
    for (int a=2; a<=N; a++) {
        temp = 0;
        for (int b = 1; b <= a; b++) {
            if (A[a] > A[b] && temp < dp[b][0]) {
                dp[a][0] = dp[b][0] + 1;
                temp = dp[b][0];
            }
            if (dp[a][0] == 0)
                dp[a][0]++;
        }
    }
    for (int a=N-1; a>=1; a--) {
        temp = 0;
        for (int b = N; b >= a-1; b--) {
            if (A[a] > A[b] && temp < dp[b][1]) {
                dp[a][1] = dp[b][1] + 1;
                temp = dp[b][1];
            }
            if (dp[a][1] == 0)
                dp[a][1]++;
        }
    }
    for( int a=1; a<=N; a++)
    {
        if (answer<dp[a][0]+dp[a][1])
            answer = dp[a][0]+dp[a][1];
    }
    cout<<answer-1;
}