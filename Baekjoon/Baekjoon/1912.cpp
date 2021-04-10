#include <iostream>
#include <algorithm>
using namespace std;

int n=0;
int dp[1000001]={0, };
int main()
{
    cin>>n;
    int answer =-10000;
    for(int a=1;a<=n;a++)
        cin>>dp[a];
    for(int a=1; a<=n; a++) {
        dp[a] = max(dp[a], dp[a - 1] + dp[a]);
        if (dp[a] > answer)
            answer = dp[a];
    }
    cout<<answer;
}
