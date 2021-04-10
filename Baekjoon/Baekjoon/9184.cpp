#include <iostream>
using namespace std;

int a,b,c;
int answer = 0;
int dp[21][21][21] = {0, };
int solution(int a, int b, int c);

int main()
{
    cin>>a>>b>>c;
    while(a!=-1 || b!=-1 || c!=-1)
    {
        cout << "w(" << a << ", " << b << ", " << c << ") = " << solution(a,b,c) << "\n";
        cin >>a>>b>>c;
    }
}
int solution(int a, int b, int c)
{
    if (a<=0 || b<=0 || c<=0)
        return 1;
    else if (a>20 || b>20 || c>20)
        return 1048576;
    else if (a<b && b<c)
    {
        if (dp[a][b][c] != 0)
            return dp[a][b][c];
        else
            return dp[a][b][c] = solution(a, b, c-1) + solution(a, b-1, c-1) - solution(a, b-1, c);
    }
    else
    {
        if (dp[a][b][c] != 0)
            return dp[a][b][c];
        else
            return dp[a][b][c] = solution(a-1, b, c) + solution(a-1, b-1, c) + solution(a-1, b, c-1) - solution(a-1, b-1, c-1);
    }
}
