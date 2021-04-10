#include <iostream>
#include <algorithm>
using namespace std;

int wine[10001] = {0, };
int dp[10001]= {0, };
int main()
{
    int N;
    cin >> N;
    for(int a=1;a<=N;a++)
        cin>>wine[a];
    dp[0]=0;
    dp[1]=wine[1];
    dp[2]=max(wine[2] + wine[1], wine[2]);
    for (int a=3; a<=N;a++)
    {
        dp[a] = max(dp[a-3] + wine[a-1] + wine[a], dp[a-2] + wine[a]);
        dp[a] = max(dp[a], dp[a-4] + wine[a-1] + wine[a]);
    }
    cout << max(dp[N-1], dp[N]);
}
