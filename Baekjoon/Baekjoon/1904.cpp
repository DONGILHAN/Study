#include <iostream>
using namespace std;

int solution(int N);
int dp[1000001]={0,1,2};
int main()
{
    int N = 0;
    int a=1, b=2;
    cin>>N;
    cout << solution(N);
}

int solution(int N)
{
    if(N == 1)
        return 1;
    else if (N==2)
        return 2;
    else
    {
        if (dp[N]!=0)
            return dp[N];
        else
            return dp[N] = (solution(N-1) + solution(N-2))%15746;
    }
}
