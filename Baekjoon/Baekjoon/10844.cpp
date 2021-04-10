#include <iostream>
using namespace std;

long long dp[101][11]={0, };
int modular = 1000000000;
int main()
{
    int N;
    cin>> N;
    dp[1][0] = 0;
    long long answer = 0;
    for (int a=1 ;a<10;a++)
        dp[1][a] = 1;
    for (int a=2; a<=N;a++)
    {
        for (int b=0;b<10;b++)
        {
            if (b==0)
                dp[a][b] = dp[a-1][b+1]  % modular;
            else if (b==9)
                dp[a][b] = dp[a-1][b-1] % modular;
            else
                dp[a][b] = dp[a-1][b-1] + dp[a-1][b+1] % modular;
        }
    }
    for (int a=0;a<10;a++)
        answer+=dp[N][a];
    cout << answer % modular;
}