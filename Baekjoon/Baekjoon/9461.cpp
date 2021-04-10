#include <iostream>
using namespace std;

long long dp[101] = {0,1,1,1,2,2,3,4,5,7,9};
long long solution(int N);
int main()
{
    int T;
    int N;
    cin >> T;
    for(int a=0;a<T;a++)
    {
        cin>>N;
        cout << solution(N)<< "\n";
    }
}
long long solution(int N)
{
    if (dp[N] != 0)
        return dp[N];
    else
        return dp[N] = solution(N-1)+solution(N-5);
}
